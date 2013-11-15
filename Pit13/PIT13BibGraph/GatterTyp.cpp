#include "GatterTyp.h"

//Konstruktor
GatterTyp::GatterTyp(){
}
//Destruktor
GatterTyp::~GatterTyp(){
}

//Methoden
string GatterTyp::getName(){
	return name;
}
double GatterTyp::getGrundLaufzeit(){
	return grundLaufzeit;
}
short GatterTyp::getLastFaktor(){
	return lastFaktor;
}
short GatterTyp::getLastKapazitaet(){
	return lastKapazitaet;
}
short GatterTyp::getEingaenge(){
	return eingaenge;
}
bool GatterTyp::getIsFlipflop(){
	return false;
}
void GatterTyp::setName( string n){
	name = n;
}
void GatterTyp::setGrundLaufzeit( double gl ){
	grundLaufzeit = gl;
}
void GatterTyp::setLastFaktor( short lf ){
	lastFaktor = lf;
}
void GatterTyp::setLastKapazitaet( short lk ){
	lastKapazitaet = lk;
}
void GatterTyp::setEingaenge( short ei ){
	eingaenge = ei;
}
