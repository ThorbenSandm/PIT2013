#include <iostream>
using namespace std;

#include "Bibliothek.h"

int main(){
		
	Bibliothek* Bib = new Bibliothek;
	GatterTyp* Gat = new GatterTyp;
	Flipflop* Flip = new Flipflop;

	Bib->pfadEinlesen( "C:\\bib.txt" );
	Bib->dateiAuswerten();
	Bib->dateiAusgabe();

	system( "pause" );
	return 0;
}
