/** @file */

/*

PROJEKT LOTY

*/

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream> 

#include "struktury.h"

using namespace std;

/**Funkcja parsuje dane os�b z pliku
@param str tekst z pliku przekonwertowany na typ string*/
Record parse_record(const string& str);


/**Funkcja dodaje pasa�er�w do lotu automatycznie sortuj�c w porz�dku rosn�cym
@param[in,out] head adres pierwszego elementu listy lot�w
@param record dane pasa�era w postaci struktury
*/
void add_lot_pasazerSorted(LotListItem* head, const Record& record);


/**Funkcja zapisuje dane os�b podr�ujacych do mniejszych plik�w
@param[in,out] head adres pierwszego elementu listy lot�w
*/
void ZapisdoPlikuPosortowanego(LotListItem* head);


/**Funkcja odczytuje dane z pliku
@param the_file plik do odczytu
@param[in,out] head adres pierwszego elementu listy lot�w*/
void OdczytajZPliku(fstream & the_file, LotListItem* head);


/**Funkcja usuwa list� lot�w
@param[in,out] head adres pierwszego elementu listy lot�w*/
void usunListeLotow(LotListItem* head);


/**Funkcja usuwa list� pasa�er�w
@param[in,out] head adres pierwszego elementu listy pasazer�w*/
void usunListePasazerow(PasazerListItem* head);



#endif


