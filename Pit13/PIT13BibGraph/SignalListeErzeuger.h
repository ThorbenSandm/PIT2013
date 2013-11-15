#ifndef SIGNALLISTEERZEUGER_H
#define SIGNALLISTEERZEUGER_H
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "Signal.h"
#include "signalTypen.h"


class SignalListeErzeuger {
private:	
	std::string datei;
	long frequenz;
	signalTypen sigTyp;
	short anzahlSignale;
	Signal *signale;
public:
	SignalListeErzeuger ();
	~SignalListeErzeuger();
	
	
	
	void AusgabeSignalliste(short anzahlSignale);
	void AusgabeSchaltnetzdatei(std::string datei);
	short anzahlSignaleBestimmen(std::string datei);
	long frequenzBestimmen(std::string datei);
	void ArrayAnlegen(short anzahlSignale, std::string datei);
	
	

	
	

};
#endif
