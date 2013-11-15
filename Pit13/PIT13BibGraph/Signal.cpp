//Erstellt von Thorben

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Signal.h"

	Signal::Signal() {
		signalTyp = unbekannt;
		quelle = "NULL";
		quellenTyp = "NULL";
		for ( int i = 0 ; i <= anzahlZiele ; i++ ) {
			ziele[i] = "NULL";
		}
		int anzahlZiele = 0;
	}
	
	Signal::~Signal() {
	}

	int Signal::getAnzahlZiele() {
		return anzahlZiele;
	}

	std::string Signal::getQuelle() {
		return quelle;
	}

	std::string Signal::getQuellentyp() {
		return quellenTyp;
	}

	std::string Signal::getZiel(int pos) {
		return ziele[pos];
	}

	Signal::signalTypen Signal::getSignalTyp() {
		return signalTyp;
	}

	void Signal::setAnzahlZiele(int Ziele) {
		anzahlZiele = Ziele;
	}

	void Signal::setQuelle (std::string gatterName) {
		quelle = gatterName;
	}

	void Signal::setQuellenTyp (std::string gatterTyp) {
		quellenTyp = gatterTyp;
	}

	void Signal::zielHinzufuegen (std::string gatterName, int pos) {
		ziele[pos] = gatterName;

	}


	void Signal::setSignalTyp (signalTypen sigTyp) {
		signalTyp = sigTyp;
	}