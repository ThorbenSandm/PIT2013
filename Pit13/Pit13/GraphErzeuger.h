//Erstellt von Alex am 08.11.13

#ifndef GraphErzeuger_H
#define GraphErzeuger_H

#include <iostream>
using namespace std;

#include "ListenElement.h";
#include "Signal.h"

class GraphErzeuger{

private:
	//Bibliothek* bibliothek;
	ListenElement* startElement;
	ListenElement* endElement;
	Signal* signale;
	short anzahlSignale;

public:
	GraphErzeuger( Signal* signalliste , short laenge );
	~GraphErzeuger();

	void GraphErstellen();
	void ListeErstellen();


};

#endif