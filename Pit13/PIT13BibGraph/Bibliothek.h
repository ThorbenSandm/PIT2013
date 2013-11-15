// Definition der Klasse Bibliothek

#ifndef _BIBLIOTHEK_
#define _BIBLIOTHEK_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "GatterTyp.h"
#include "Flipflop.h"

class Bibliothek {
	private:
	void openError();
	void readError();

	vector <GatterTyp*> bibElement; //Zeiger
	string datei;

	public:
		//Konstruktor
		Bibliothek(); //ist string pfad nötig

		//Destruktor
		~Bibliothek();

		//Methoden
		string getPfad();
		GatterTyp* getBibElement( string typ );
		void dateiAusgabe();
		void dateiAuswerten();
		bool pfadEinlesen( string pfad );
};
#endif