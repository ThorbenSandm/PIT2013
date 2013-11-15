#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Signal.h"
#include "SignalListeErzeuger.h"
#include <stdlib.h>
#include <sstream>

using namespace std;

SignalListeErzeuger::SignalListeErzeuger() {
	anzahlSignale=0;
}
SignalListeErzeuger::~SignalListeErzeuger() {
}
short SignalListeErzeuger::anzahlSignaleBestimmen(std::string datei) {
	ifstream Schaltnetzdatei(datei);
	if( !Schaltnetzdatei ) {
	cout << "Fehler beim Oeffnen der Datei" << endl;
	}
	else {
		cout<<"Datei erfolgreich geladen"<<endl;
	string zeile;
	while( getline (Schaltnetzdatei, zeile)) {
		if (zeile.substr(0, 5)=="INPUT") {
			while (zeile.find("s", 0)!=-1) {
				zeile.erase(zeile.find("s",0), 1);
				anzahlSignale++;
			}
		}
		if (zeile.substr(0, 6)=="OUTPUT") {
			while (zeile.find("s", 0)!=-1) {
				zeile.erase(zeile.find("s",0), 1);
				anzahlSignale++;
			}
		}
		if (zeile.substr(0, 7)=="SIGNALS") {
			while (zeile.find("s", 0)!=-1) {
				zeile.erase(zeile.find("s",0), 1);
				anzahlSignale++;
			}
		}	
	}
}
	return anzahlSignale;
}
long SignalListeErzeuger::frequenzBestimmen(std::string datei) {
	ifstream Schaltnetzdatei( datei);
	if( !Schaltnetzdatei ) {
	cout << "Fehler beim Oeffnen der Datei" << endl;
	}
	string zeile;
	while( getline (Schaltnetzdatei, zeile)) {
		if (zeile.substr(0,5)=="CLOCK") {
			int poskomma=zeile.find(",",0);
			int possemikolon=zeile.find(";",0);
			std::string frequ=zeile.substr(poskomma+2, possemikolon-poskomma-2);
			int posleerzeichen=frequ.find(" ",0);
			std::string ziffern=frequ.substr(0, posleerzeichen);
			std::string einheit=frequ.substr(posleerzeichen+1,frequ.length()-posleerzeichen-1);
			frequenz=atol(ziffern.c_str());
			if (einheit=="Hz") {
				frequenz=frequenz;
			}
			else if (einheit=="kHz") {
				frequenz=1000*frequenz;
				
			}
			else if (einheit=="MHz") {
				frequenz=1000000*frequenz;				
			}
		}
	}
	return frequenz;
}
void SignalListeErzeuger::ArrayAnlegen(short anzahlSignale, std::string datei) {
	ifstream Schaltnetzdatei( datei);
	string zeile;
	signale=new Signal [anzahlSignale];
	int gatternummer=1;
	
	
	
	while (getline (Schaltnetzdatei, zeile)) {
		if (zeile.substr(0,5)=="INPUT") {
			int possem =zeile.find(";",0); //Position Semikolon bestimmen
			string a =zeile.substr(6, possem-6); //Teilstring, der nur Namen der Signale enthält, getrennt durch Komma
			
			int poskom;
			do {
				string b=a.substr(1,3); //Teilstring der nur die Zagl des Namens des Signals enthält
				cout<<b<<endl;
				a=a.erase(0,5); //Das extrahierte Signal wird aus dem String gelöscht
				int name =atol(b.c_str()); //Umwandeln der Namenszahl in eine Integervariable
				signale[name-1].setSignalTyp(eingang); //Speichern der Information in das richtige Objekt
			} 
			while (poskom=a.find(",",0)!=-1);
		}

			
		
		else if (zeile.substr(0,6)=="OUTPUT") {
			int possem =zeile.find(";",0); //Position Semikolon bestimmen
			string a =zeile.substr(7, possem-7); //Teilstring, der nur Namen der Signale enthält, getrennt durch Komma
			
			int poskom;
			while (poskom=a.find(",",0)!=-1) {
				string b=a.substr(1,3); //Teilstring der nur die Zagl des Namens des Signals enthält
				a=a.erase(0,5); //Das extrahierte Signal wird aus dem String gelöscht
				int name =atol(b.c_str()); //Umwandeln der Namenszahl in eine Integervariable
				signale[name-1].setSignalTyp(ausgang); //Speichern der Information in das richtige Objekt
			} 
			string c=a.substr(1,3);
			int name =atol(c.c_str());
			signale[name-1].setSignalTyp(ausgang);
			
			
			
			
		}
		else if (zeile.substr(0,7)=="SIGNALS") {
			int possem =zeile.find(";",0); //Position Semikolon bestimmen
			string a =zeile.substr(8, possem-8); //Teilstring, der nur Namen der Signale enthält, getrennt durch Komma
			
			int poskom;
			while (poskom=a.find(",",0)!=-1){
				string b=a.substr(1,3); //Teilstring der nur die Zagl des Namens des Signals enthält
				a=a.erase(0,5); //Das extrahierte Signal wird aus dem String gelöscht
				int name =atol(b.c_str()); //Umwandeln der Namenszahl in eine Integervariable
				signale[name-1].setSignalTyp(intern); //Speichern der Information in das richtige Objekt
			} 
		
			string c=a.substr(1,3);
			int name =atol(c.c_str());
			signale[name-1].setSignalTyp(intern);
			
			
			
		}
		else if (zeile.substr(0,1)=="g") {
			
			std::string gattername;
			std::string GatterZahl; //Umwandeln der Gatterzahl in einen String
			ostringstream convert;
			convert<<gatternummer;
			GatterZahl=convert.str();
			if (gatternummer<10) {
				gattername="g00"+GatterZahl;
				
			}
			else if (10<=gatternummer&&gatternummer<100) {
				gattername="g0"+GatterZahl;
				
			}
			else {
				gattername="g"+GatterZahl;
			}
			
			int posklammerZu=zeile.find(")",0); //Bestimmen der Position von )
			std::string ausgangsSignal=zeile.substr(posklammerZu-3,3); //bestimmen der Nummer des Ausgangssignals
			int name=atol(ausgangsSignal.c_str()); //Umwandeln in integer Variable
			signale[name-1].setQuelle(gattername); //Speichern des Namens der Quelle im Objekt signal
			
			int posklammerAuf=zeile.find("(",0); //Bestimmen der Position von (
			std::string gattertyp=zeile.substr(5, posklammerAuf-5);//Teilstring, welcher den Gattertyp beinhaltet
			signale[name-1].setQuellenTyp(gattertyp); //speichern des quellentyp im Objekt
			
			int poskomma1=zeile.find(",", 0); //Bestimmen der Position des ersten Komma
			std::string eingang1=zeile.substr(posklammerAuf+2, poskomma1-posklammerAuf-2); //Teilstring, welcher SignalName des 1. Eingangssignals beinhaltet
			int eingangsSignal1=atol(eingang1.c_str()); //Umwandeln in integer Variable
			signale[eingangsSignal1-1].zielHinzufuegen(gattername,signale[eingangsSignal1-1].getAnzahlZiele()); //Hinzufügen des Ziels in den Array des Objektes, an die erste noch nicht besetzte Stelle
			
			switch (signale[eingangsSignal1-1].getAnzahlZiele()) {   //Die AnzahlZiele des Signals wird um 1 erhöht
			case 0:signale[eingangsSignal1-1].setAnzahlZiele(1); 
				break;
			case 1:signale[eingangsSignal1-1].setAnzahlZiele(2);
				break;
			case 2:signale[eingangsSignal1-1].setAnzahlZiele(3);
				break;
			case 3:signale[eingangsSignal1-1].setAnzahlZiele(4);
				break;
			case 4:signale[eingangsSignal1-1].setAnzahlZiele(5);
				break;
			}

			int poskomma2=zeile.find(",",poskomma1+1); //Bestimmen der Position des 2. Komma
			if (poskomma2!=-1) { //Überprüfen, ob 2. Komma im String enthalten
				if(zeile.at(poskomma1+1)!='c') { //Prüfen, ob 2. Eingang das Taktsignal ist
					string eingang2;
					eingang2=zeile.substr(poskomma1+2, poskomma2-poskomma1-2); ////Teilstring, welcher SignalName des 1. Eingangssignals beinhaltet
					int eingangsSignal2=atol(eingang2.c_str()); //Umwandeln in integer Variable
					signale[eingangsSignal2-1].zielHinzufuegen(gattername,signale[eingangsSignal2-1].getAnzahlZiele()); //Hinzufügen des Ziels in den Array des Objektes, an die erste noch nicht besetzte Stelle

					switch (signale[eingangsSignal2-1].getAnzahlZiele()) {   //Die AnzahlZiele des Signals wird um 1 erhöht
					case 0:signale[eingangsSignal2-1].setAnzahlZiele(1); 
						break;
					case 1:signale[eingangsSignal2-1].setAnzahlZiele(2);
						break;
					case 2:signale[eingangsSignal2-1].setAnzahlZiele(3);
						break;
					case 3:signale[eingangsSignal2-1].setAnzahlZiele(4);
						break;
					case 4:signale[eingangsSignal2-1].setAnzahlZiele(5);
						break;
					}
				}
			}
			gatternummer++;
		}
	}
	for (int i=0; i<anzahlSignale; i++) { //Überprüfen auf Kurzschlüsse, bei Kurzschluss ist Quelle gleich einem der Ziele
		for (int j=0; j<4; j++) {
			if (signale[i].getQuelle()==signale[i].getZiel(j)) {
				cout<<"Kurzschluss im Schaltnetz festgestellt!"<<endl;
				exit(0);
				
			}
		}
	}
	
	

}

void SignalListeErzeuger::AusgabeSchaltnetzdatei(std::string datei) {
	ifstream Schaltnetzdatei( datei);
	if( !Schaltnetzdatei ) {
	cout << "Fehler beim Oeffnen der Datei" << endl;
	}
	string zeile;
	while( getline (Schaltnetzdatei, zeile)) {
		cout<<zeile<<endl;
	}
}


void SignalListeErzeuger::AusgabeSignalliste(short anzahlSignale) {
	
	cout<<"*************"<<endl;
	cout<<"*Signalliste*"<<endl;
	cout<<"*************"<<endl;
	for (int i=0; i<anzahlSignale; i++) {
		if (i+1<10) {
			cout<<"Signalname : s00"<<i+1<<endl;
			signalTypen SiTyp=signale[i].getSignalTyp();
			switch (SiTyp) {
			case 0: cout<<"Signaltyp: eingang"<<endl;
				break;
			case 1: cout<<"Signaltyp: intern"<<endl;
				break;
			case 2: cout<<"Signaltyp: ausgang"<<endl;
				break;
			}
			
			if (signale[i].getQuelle()=="NULL") {
				cout <<"Signalquelle : keine Quelle"<<endl;
			}
			else {	
				cout<<"Signalquelle : "<<signale[i].getQuelle()<<endl;
			}
			cout<<"Quellentyp: "<<signale[i].getQuellentyp()<<endl;
			cout<<"-->Das Signal hat "<<signale[i].getAnzahlZiele()<<" Zielgatter"<<endl;
			cout<<"Ziel-Gatter :";
			for (int j=0; j<signale[i].getAnzahlZiele(); j++) {
			cout<<" "<<signale[i].getZiel(j);
			}
			cout<<endl;
		}
		else if (i+1>=10&&i+1<100) {
			cout<<"Signalname : s0"<<i+1<<endl;
			signalTypen SiTyp=signale[i].getSignalTyp();
			switch (SiTyp) {
			case 0: cout<<"Signaltyp: eingang"<<endl;
				break;
			case 1: cout<<"Signaltyp: intern"<<endl;
				break;
			case 2: cout<<"Signaltyp: ausgang"<<endl;
				break;
			}
			if (signale[i].getQuelle()=="NULL") {
				cout <<"Signalquelle : keine Quelle"<<endl;
			}
			else {	
				cout<<"Signalquelle : "<<signale[i].getQuelle()<<endl;
			}
			cout<<"Quellentyp: "<<signale[i].getQuellentyp()<<endl;
			cout<<"-->Das Signal hat "<<signale[i].getAnzahlZiele()<<" Zielgatter"<<endl;
			cout<<"Ziel-Gatter :";
			for (int j=0; j<signale[i].getAnzahlZiele(); j++) {
			cout<<" "<<signale[i].getZiel(j);
			}
			cout<<endl;
		}
		else if (i+1>=100) {
			cout<<"Signalname : s"<<i+1<<endl;
			signalTypen SiTyp=signale[i].getSignalTyp();
			switch (SiTyp) {
			case 0: cout<<"Signaltyp: eingang"<<endl;
				break;
			case 1: cout<<"Signaltyp: intern"<<endl;
				break;
			case 2: cout<<"Signaltyp: ausgang"<<endl;
				break;
			}
			if (signale[i].getQuelle()=="NULL") {
				cout <<"Signalquelle : keine Quelle"<<endl;
			}
			else {	
				cout<<"Signalquelle : "<<signale[i].getQuelle()<<endl;
			}
			cout<<"Quellentyp: "<<signale[i].getQuellentyp()<<endl;
			cout<<"-->Das Signal hat "<<signale[i].getAnzahlZiele()<<" Zielgatter"<<endl;
			cout<<"Ziel-Gatter :";
			for (int j=0; j<signale[i].getAnzahlZiele(); j++) {
			cout<<" "<<signale[i].getZiel(j);
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
			
				
			



