/** @file */

/*

PROJEKT LOTY

*/

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream> 

#include "struktury.h"

using namespace std;

/**Funkcja parsuje dane osób z pliku
@param str tekst z pliku przekonwertowany na typ string*/
Record parse_record(const string& str);


/**Funkcja dodaje pasa¿erów do lotu automatycznie sortuj¹c w porz¹dku rosn¹cym
@param[in,out] head adres pierwszego elementu listy lotów
@param record dane pasa¿era w postaci struktury
*/
void add_lot_pasazerSorted(LotListItem* head, const Record& record);


/**Funkcja zapisuje dane osób podró¿ujacych do mniejszych plików
@param[in,out] head adres pierwszego elementu listy lotów
*/
void ZapisdoPlikuPosortowanego(LotListItem* head);


/**Funkcja odczytuje dane z pliku
@param the_file plik do odczytu
@param[in,out] head adres pierwszego elementu listy lotów*/
void OdczytajZPliku(fstream & the_file, LotListItem* head);


/**Funkcja usuwa listê lotów
@param[in,out] head adres pierwszego elementu listy lotów*/
void usunListeLotow(LotListItem* head);


/**Funkcja usuwa listê pasa¿erów
@param[in,out] head adres pierwszego elementu listy pasazerów*/
void usunListePasazerow(PasazerListItem* head);



#endif


