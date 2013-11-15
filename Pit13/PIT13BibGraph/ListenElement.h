//Erstellt von Alex am 08.11.13

#ifndef ListenElement_H
#define ListenElement_H

#include <iostream>
using namespace std;

#include "SchaltwerkElement.h";

class ListenElement{

private:
	SchaltwerkElement* schaltwerkElement;
	ListenElement* next;
	

public:
	ListenElement();
	~ListenElement();

	inline SchaltwerkElement* getSchaltwerkElement() { return schaltwerkElement; }
	inline ListenElement* getNextelement() { return next; }
	
	inline void setSchaltwerkElement( SchaltwerkElement* schaltwerkEl ) { schaltwerkElement = schaltwerkEl ;} //klappt das so? oder wird das schaltwerkEl nach beenden der Methode gelöscht. Evtl muss ein neues Schaltwerkelement dynamisch erzeugt werden.
	inline void setNextElement( ListenElement* nextEl ) { next = nextEl; } // hier dasselbe?




};

#endif