/** @file */

/*

PROJEKT LOTY

*/

#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <iostream> 
#include <string>

using namespace std;

/**Pozycja na liœcie pasa¿erów*/
struct PasazerListItem {
	string imie;						///< imie pasa¿era
	string nazwisko;					//< nazwisko pasa¿era
	unsigned numerMiejsca;				//< numer miejsca pasa¿era
	PasazerListItem* nextPasazer;		//< adres nastêpnego pasa¿era
};

/**Pozycja na liœcie lotów*/
struct LotListItem {
	string symbol;						//< symbol lotu
	tm data;							//< data lotu
	string odlot;						//< data odlotu
	string przylot;						//< data przylotu
	PasazerListItem* firstPasazer;		//< adres pierwszego pasazera na liœcie
	LotListItem* nextLot;				//< adres nastêpnego lotu
};

/**Dane z pliku*/
struct Record {
	string symbol;						//< symbol lotu
	tm data;							//< data lotu
	string odlot;						//< data odlotu
	string przylot;						//< data przylotu
	string imie;						//< imie pasa¿era
	string nazwisko;					//< nazwisko pasa¿era
	unsigned numerMiejsca;				//< numer miejsca pasa¿era
};

#endif