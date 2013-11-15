// erstellt von Alex am 08.11.13
#include <iostream>
using namespace std;

#include "ListenElement.h";
#include "SchaltwerkElement.h";
#include "GatterTyp.h";
#include "GraphErzeuger.h";
#include "Bibliothek.h"

 int main(){
	//bibliothek->dateiAusgabe();
	ListenElement* listenElement = new ListenElement;
	cout << "listenElement erstellt" << endl;
	GatterTyp* Typ = new GatterTyp();
	cout << "Typ erstellt" << endl;
	SchaltwerkElement* schaltwerkElement = new SchaltwerkElement( Typ );
	cout << "schaltwerkElement erstellt" << endl;
	Signal* signalListe = new Signal; // sinnlose liste, damits geht
	GraphErzeuger* graphErzeuger = new GraphErzeuger( signalListe , 10 ); // quatschwerte
	cout << "Grapherzeuger erstellt" << endl;
	/*delete listenElement; //kompiliert, aber gibt einen Fehler
	delete Typ;
	delete schaltwerkElement;
	delete graphErzeuger;*/

	
	system( "pause" );

};
