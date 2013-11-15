#include <string>
#include <iostream>
#include <fstream>

#include "Bibliothek.h"

using namespace std;

//Konstruktor
Bibliothek::Bibliothek(){
}								
//Destruktor
Bibliothek::~Bibliothek(){
}

void Bibliothek::openError(){
	ifstream myfile( datei );
	if( myfile.fail() ){
		cout<< "Fehler beim Oeffnen der Datei!" <<endl;
	}
}

void Bibliothek::readError(){
	ifstream myfile( datei );
	if( myfile.fail() == !myfile.eof() ){
		cout<< "Fehler beim Lesen der Datei!" <<endl;
	}
}
string Bibliothek::getPfad(){
	return datei;
}
GatterTyp* Bibliothek::getBibElement( string typ ){
	for( int i=0 ; i < bibElement.size() ; i++ ){
		if( bibElement[i] -> getName() == typ ){
			return bibElement[i];
		}
	}
}

void Bibliothek::dateiAusgabe(){
	ifstream myfile( datei );
	if( myfile.fail() ){
		cout<< "Fehler beim oeffnen der Datei!" <<endl;
	}
	else{
		int i = 1; 
		while( !myfile.eof() ){
			if( myfile ){
				string zeile;
				getline( myfile,zeile );
				cout<< i << " " << zeile << endl;
			}
			else{
				cout<< "Fehler beim Lesen der Bibliotheksdatei!" << endl;
				break;
			}
			i = i+1;
		}
	}
}

void Bibliothek::dateiAuswerten(){

	ifstream myfile;
	myfile.open( datei );
	string str;
	getline( myfile , str );
	
	while( str.find("Bausteine") == str.npos ){
		getline( myfile, str );
		
	}

	while( !myfile.eof() ){
		getline( myfile, str );

		while( str.find( "]" ) == -1 && str.find( "#endfile" ) == -1){
			getline( myfile, str );
		}
		
		int pos;
		pos = str.find( "]" );
		string _name;
		_name = str.substr( 1, pos-1 );

		if( _name != "dff" ){

			GatterTyp* pointer = new GatterTyp;
			bibElement.push_back( pointer );
			

			getline( myfile, str );
			str = str.substr( str.find( ":" )+1 );
			short _eingaenge = atoi( str.c_str() );
			
			getline( myfile, str );
			str = str.substr( str.find( ":" )+1 );
			double _grundLaufzeit = atof( str.c_str() );
			
			getline( myfile, str );
			str = str.substr( str.find( ":" )+1 );
			short _lastFaktor = atoi( str.c_str() );
			
			getline( myfile, str );
			str = str.substr( str.find( ":" )+1 );
			short _lastKapazitaet = atoi( str.c_str() );
				
			pointer->setName( _name );
			pointer->setEingaenge( _eingaenge );
			pointer->setGrundLaufzeit( _grundLaufzeit );
			pointer->setLastFaktor( _lastFaktor );
			pointer->setLastKapazitaet( _lastKapazitaet );

		}

		else{


			Flipflop* pointer = new Flipflop;
			bibElement.push_back( pointer );

			getline( myfile, str );
			str = str.substr( str.find( ":" )+1 );
			short _eingaenge = atoi( str.c_str() );

			getline( myfile, str );
			str = str.substr(str.find( ":" )+1 );
			short _setupTime = atoi( str.c_str() );

			getline( myfile, str );
			str = str.substr( str.find( ":" )+1 );
			short _holdTime = atoi( str.c_str() );

			getline( myfile, str );
			str = str.substr( str.find( ":" )+1 );
			short _lastKapazitaet = atoi( str.c_str() );

			getline( myfile, str ); //Takteingang weglassen
			
			getline( myfile, str );
			str = str.substr( str.find( ":" )+1 );
			double _grundLaufzeit = atof( str.c_str() );

			getline( myfile, str );
			str = str.substr( str.find( ":" )+1 );
			short _lastFaktor = atoi( str.c_str() );

			getline( myfile, str );
			str = str.substr( str.find( ":" )+1 );
			short _lastKapazitaetClock = atoi( str.c_str() );


			pointer->setName( _name );
			pointer->setEingaenge( _eingaenge );
			pointer->setSetupTime( _setupTime );
			pointer->setHoldTime( _holdTime );
			pointer->setLastKapazitaet( _lastKapazitaet );
			pointer->setLastFaktor( _lastFaktor );
			pointer->setLastKapazitaetClock( _lastKapazitaetClock );

		}
	}
}

bool Bibliothek::pfadEinlesen( string pfad ){
	ifstream myfile;
	myfile.open( pfad.c_str() );

	if( myfile.is_open() ){

		cout << pfad << " erfolgreich geoeffnet" << endl << endl;
		datei = pfad;
		return true;
	}
	else{ 
		return false;
	}
}







