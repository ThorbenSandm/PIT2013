#ifndef _GATTERTYP_
#define _GATTERTYP_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class GatterTyp{
	protected:
	
		string name;
		double grundLaufzeit;
		short lastFaktor;
		short lastKapazitaet;
		short eingaenge;

	public:

		//Konstruktor
		GatterTyp();
		//Destruktor
		~GatterTyp();

		//Methoden
		string getName();
		double getGrundLaufzeit();
		short getLastFaktor();
		short getLastKapazitaet();
		short getEingaenge();
		bool getIsFlipflop();
		void setName( string n );
		void setGrundLaufzeit( double gl );
		void setLastFaktor( short lf );
		void setLastKapazitaet( short lk );
		void setEingaenge( short ei );

};
#endif