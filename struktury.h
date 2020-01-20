/** @file */

/*

PROJEKT LOTY

*/

#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <iostream> 
#include <string>

using namespace std;

/**Pozycja na li�cie pasa�er�w*/
struct PasazerListItem {
	string imie;						///< imie pasa�era
	string nazwisko;					//< nazwisko pasa�era
	unsigned numerMiejsca;				//< numer miejsca pasa�era
	PasazerListItem* nextPasazer;		//< adres nast�pnego pasa�era
};

/**Pozycja na li�cie lot�w*/
struct LotListItem {
	string symbol;						//< symbol lotu
	tm data;							//< data lotu
	string odlot;						//< data odlotu
	string przylot;						//< data przylotu
	PasazerListItem* firstPasazer;		//< adres pierwszego pasazera na li�cie
	LotListItem* nextLot;				//< adres nast�pnego lotu
};

/**Dane z pliku*/
struct Record {
	string symbol;						//< symbol lotu
	tm data;							//< data lotu
	string odlot;						//< data odlotu
	string przylot;						//< data przylotu
	string imie;						//< imie pasa�era
	string nazwisko;					//< nazwisko pasa�era
	unsigned numerMiejsca;				//< numer miejsca pasa�era
};

#endif