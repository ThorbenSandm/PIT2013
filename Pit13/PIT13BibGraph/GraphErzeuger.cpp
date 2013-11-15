//Erstellt von Alex am 08.11.13

#include "GraphErzeuger.h";

GraphErzeuger::GraphErzeuger( Signal* signalListe , short laenge ){
	bibliothek = new Bibliothek;
	bibliothek->pfadEinlesen( "C:\\bib.txt" );
	bibliothek->dateiAuswerten();
	cout << "bib.txt ausgewertet" << endl;
	anzahlSignale = laenge;
	startElement = NULL;
	endElement = NULL;
	signale = signalListe;
	
}

void GraphErzeuger::ListeErstellen(){

	GatterTyp* typ ;//=  new GatterTyp;
	ListenElement* temp;

	for( int i = 0 ; i < anzahlSignale ; i++){

		ListenElement* LE = new ListenElement;  // wie kann ich viele davon erzeugen? klappt das evtl so?
		typ = bibliothek->getBibElement( signale[i].getQuellentyp() );	// typ = suche nach "such" in der Bibliothek und Rückgabe eines Zeigers auf den GatterTyp
		SchaltwerkElement* SE = new SchaltwerkElement( typ );
		SE->setName( signale[i].getQuelle() );

		LE->setSchaltwerkElement( SE );
		
		if( temp != NULL ){
			temp->setNextElement( LE );
		}

		temp = LE;
	}




}

void GraphErzeuger::GraphErstellen(){ // Es fehlt noch die Ueberpruefung auf unbenutzte Signale, unbeschaltete Gattereingaenge oder Gatter, die Ziel von zu vielen Signalen  sind

	string such;
	SchaltwerkElement* quelle;

	for( int i = 0 ; i < anzahlSignale ; i++){

		such = signale[i].getQuelle();

		for( ListenElement* LE = new ListenElement ; LE != NULL ; LE = LE->getNextelement() ){ // suche nach de

			if( LE->getSchaltwerkElement()->getName() == such ){

				quelle = LE->getSchaltwerkElement();
				break;
			}

		}

		for( int e = 0 ; e < signale[i].getAnzahlZiele() ; e++ ){

			such = signale[i].getZiel( e );

			for( ListenElement* LE = new ListenElement ; LE != NULL ; LE = LE->getNextelement() ){ // suche nach dem Ziel ( stelle e ) in der Liste

			if( LE->getSchaltwerkElement()->getName() == such ){

				quelle->nachfolgerHinzufuegen( LE->getSchaltwerkElement() , e );
				break;
			}

		}
		}

		

	}

	}




