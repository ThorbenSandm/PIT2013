//Erstellt von Alex am 08.11.13


#ifndef SchaltwerkElement_H
#define SchaltwerkElement_H


#include <iostream>
using namespace std;

#include "GatterTyp.h";

class SchaltwerkElement{	

private:
	string name;
	GatterTyp* typ;
	double laufzeitEinzelgatter;
	SchaltwerkElement* nachfolgerElemente[5];
	int anzahlNachfolger;
	bool isEingangsElement;
	bool isAusgangsElement;
	short anzahlEingangssignale;

public:
	SchaltwerkElement( GatterTyp* gTyp ); 
	~SchaltwerkElement();

	inline string getName(){ return name; }
	inline GatterTyp getTyp() { return *typ; }
	inline double getLaufzeitEinzelgatter() { return laufzeitEinzelgatter; }
	inline SchaltwerkElement getNachfolger( int pos ) { return *nachfolgerElemente[pos]; };
	inline int getAnzahlNachfolger() { return anzahlNachfolger; }
	inline short getAnzahlEingangssignale() { return anzahlEingangssignale; }
	inline bool getIsEingangsElement() { return isEingangsElement; }
	inline bool getIsAusgangsElement() { return isAusgangsElement; }

	inline void setName( string n ) { name = n; }
	inline void nachfolgerHinzufuegen( SchaltwerkElement* schaltwerkElement , int pos ) { nachfolgerElemente[pos] = schaltwerkElement; } 
	inline void setAnzahlNachfolger( int anzahlN ) { anzahlNachfolger = anzahlN; }
	inline void setAnzahlEingangssignale( short anzahlE ) { anzahlEingangssignale = anzahlE; }
	inline void AnzahlEingangssignaleErhoehen(){ anzahlEingangssignale++; }
	inline void setIsEingangselement( bool isEingangsEl ) { isEingangsElement = isEingangsEl; }
	inline void setIsAusgangsElement( bool isAusgangsEl ) { isAusgangsElement = isAusgangsEl; }
	inline void setLaufzeitEinzelgatter( double lfz )  { laufzeitEinzelgatter = lfz; }

};

#endif