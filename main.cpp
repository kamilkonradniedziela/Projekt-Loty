/** @file */

/*

PROJEKT LOTY

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cassert>

#include "struktury.h"
#include "funkcje.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cerr << "Podaj jeden plik do odczytu!";
		assert(0);
	}
	fstream the_file(argv[1]);
	if (!the_file.is_open())
	{
		cerr << "Nie mozna otowrzyc pliku! \n";
		assert(0);
	}
	
	LotListItem* head = new LotListItem;
	head->symbol = "";
	head->firstPasazer = nullptr;
	head->nextLot = nullptr;

	OdczytajZPliku(the_file,head);

	ZapisdoPlikuPosortowanego(head);

	usunListeLotow(head);

	return 0;
}
