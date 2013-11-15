#ifndef SIGNAL_H
#define SIGNAL_H
#include "stdafx.h"
#include <iostream>
#include <string>
#include "signalTypen.h"



class Signal {
private:
	
	
	std::string quelle;
	std::string quellenTyp;
	std::string ziele[5];
	int anzahlZiele;	
	signalTypen signalTyp;
	
	
public:
	
	Signal();
	~Signal();
	
	
	
	int getAnzahlZiele();
	signalTypen getSignalTyp();
	std::string getQuelle();
	std::string getQuellentyp();
	std::string getZiel(int pos);
	void setAnzahlZiele(int Ziele);
	void setSignalTyp(signalTypen sigTyp);
	void setQuelle (std::string gatterName);
	void setQuellenTyp (std::string gatterTyp);
	void zielHinzufuegen (std::string gatterName, int pos);
	

};
#endif
