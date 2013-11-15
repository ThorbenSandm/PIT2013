#ifndef Signal_H
#define Signal_H

#include <iostream>
#include <string>
#include <vector>


class Signal {
private:
	int anzahlZiele;
	enum signalTypen {eingang, intern, ausgang, unbekannt};
	signalTypen signalTyp;
	std::string quelle;
	std::string quellenTyp;
	std::string ziele[2]; // muessen das nicht 5 sein?
	
	
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