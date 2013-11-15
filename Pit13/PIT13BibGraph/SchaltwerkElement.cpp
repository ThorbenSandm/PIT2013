//Erstellt von Alex am 08.11.13
#include <iostream>
using namespace std;

#include "SchaltwerkElement.h";

SchaltwerkElement::SchaltwerkElement( GatterTyp* gTyp){

	SchaltwerkElement::name = "NULL";
	SchaltwerkElement::typ = NULL; //evtl nullptr statt NULL ( im Listenelement.cpp gehts nur mit nullptr. warum? )
	SchaltwerkElement::laufzeitEinzelgatter = 0;
	SchaltwerkElement::nachfolgerElemente[0] = NULL;
	SchaltwerkElement::nachfolgerElemente[1] = NULL;
	SchaltwerkElement::nachfolgerElemente[2] = NULL;
	SchaltwerkElement::nachfolgerElemente[3] = NULL;
	SchaltwerkElement::nachfolgerElemente[4] = NULL;
	SchaltwerkElement::anzahlNachfolger = 0;
	SchaltwerkElement::isEingangsElement = false;
	SchaltwerkElement::isAusgangsElement = false;
	SchaltwerkElement::anzahlEingangssignale = 0;

}




