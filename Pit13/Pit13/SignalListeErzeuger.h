#ifndef SIGNALLISTEERZEUGER_H
#define SIGNALLISTEERZEUGER_H
#include "StdAfx.h"
#include <iostream>
#include <string>
#include <vector>
#include "Signal.h"


class SignalListeErzeuger {
private:	
	std::string datei;
	long frequenz;
	Signal::signalTypen sigTyp;
public:
	SignalListeErzeuger ();
	~SignalListeErzeuger();
	short anzahlSignale;
	Signal *signale;
	
	void AusgabeSignalliste(short anzahlSignale);
	void AusgabeSchaltnetzdatei(std::string datei);
	short anzahlSignaleBestimmen(std::string datei);
	long frequenzBestimmen(std::string datei);
	void ArrayAnlegen(short anzahlSignale, std::string datei);
	
	

	
	

};
#endif
