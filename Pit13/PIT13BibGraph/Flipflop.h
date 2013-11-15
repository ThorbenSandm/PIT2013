#ifndef _FLIPFLOP_
#define _FLIPFLOP_

#include <iostream>

using namespace std;

#include "GatterTyp.h"

class Flipflop : public GatterTyp{

	private:
		short setupTime;
		short holdTime;
		short lastKapazitaetClock;

	public:
		
		//Konstruktor
		Flipflop();
		//Destruktor
		~Flipflop();

		//Methoden
		bool getIsFlipflop();
		short getSetupTime();
		short getHoldTime();
		short getLastKapazitaetClock();
		void setSetupTime( short st );
		void setHoldTime( short ht );
		void setLastKapazitaetClock( short lkc );

};
#endif