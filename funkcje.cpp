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

Record parse_record(const string& str)
{
	Record record{};					
	istringstream ss{ str };

	ss >> record.symbol
		>> get_time(&(record.data), "%d.%m.%Y")
		>> record.odlot
		>> record.przylot
		>> record.imie
		>> record.nazwisko
		>> record.numerMiejsca;

	if (!ss)
	{
		cerr << "Bledny rekord danych!";
		assert(0);
	}

	return record;
}



void add_lot_pasazerSorted(LotListItem* head, const Record& record)
{
	LotListItem* itemLot = head;
	LotListItem* nowyLot = nullptr;
	PasazerListItem* itemPasazer = nullptr;
	PasazerListItem* nowyPasazer = nullptr;

	if (itemLot->symbol == "")
	{
		itemLot->symbol = record.symbol;
		itemLot->data = record.data;
		itemLot->odlot = record.odlot;
		itemLot->przylot = record.przylot;

	}
	else
	{
		while (itemLot->symbol != record.symbol)			
		{
			if (itemLot->nextLot == nullptr)
			{
				nowyLot = new LotListItem;
				nowyLot->symbol = record.symbol;
				nowyLot->data = record.data;
				nowyLot->odlot = record.odlot;
				nowyLot->przylot = record.przylot;
				nowyLot->firstPasazer = nullptr;
				nowyLot->nextLot = nullptr;
				itemLot->nextLot = nowyLot;			
				itemLot = nowyLot;					
			}
			else
			{
				itemLot = itemLot->nextLot;
			}
		}
	}

	if (itemLot->firstPasazer == nullptr)
	{
		PasazerListItem* nowyPasazer = new PasazerListItem;
		nowyPasazer->imie = record.imie;
		nowyPasazer->nazwisko = record.nazwisko;
		nowyPasazer->numerMiejsca = record.numerMiejsca;
		nowyPasazer->nextPasazer = nullptr;
		itemLot->firstPasazer = nowyPasazer;
	}
	else
	{
		PasazerListItem* nowyPasazer = new PasazerListItem;
		nowyPasazer->imie = record.imie;
		nowyPasazer->nazwisko = record.nazwisko;
		nowyPasazer->numerMiejsca = record.numerMiejsca;
		nowyPasazer->nextPasazer = nullptr;


		if (nowyPasazer->numerMiejsca < itemLot->firstPasazer->numerMiejsca)			
		{
			nowyPasazer->nextPasazer = itemLot->firstPasazer;
			itemLot->firstPasazer = nowyPasazer;
		}
		else
		{
			itemPasazer = itemLot->firstPasazer;
			

			bool dodalemPasazeraDoListy=false;
			while (itemPasazer->nextPasazer != nullptr)
			{
				auto p = itemPasazer;
				itemPasazer = itemPasazer->nextPasazer;
				if (nowyPasazer->numerMiejsca < itemPasazer->numerMiejsca)
				{
					p->nextPasazer = nowyPasazer;
					nowyPasazer->nextPasazer = itemPasazer;
					dodalemPasazeraDoListy = true;
				}
			}
			if (dodalemPasazeraDoListy == false)
			{
				itemPasazer->nextPasazer = nowyPasazer;
			}

		}
	}
}


void ZapisdoPlikuPosortowanego(LotListItem* head)				
{
	LotListItem* itemLot = head;
	PasazerListItem* itemPasazer = nullptr;
	fstream plik;
	if (itemLot->symbol != "")
	{
		do
		{
				string nazwaPliku;
				nazwaPliku = itemLot->symbol + ".txt";
				plik.open(nazwaPliku, ios::out); 
				if (plik.is_open() == false)
				{
					return;
				}
				else
				{		
						itemPasazer = itemLot->firstPasazer;
						plik << put_time(&(itemLot->data), "%d.%m.%Y")<<"  " << itemLot->odlot<<"  "<<itemLot->przylot<<endl;
						while (itemPasazer != nullptr)
						{
							plik << itemPasazer->imie << " " << itemPasazer->nazwisko << " " << itemPasazer->numerMiejsca << endl;
							itemPasazer = itemPasazer->nextPasazer;
						}
						plik.close();
						itemLot = itemLot->nextLot;
				}
			
		} while (itemLot != nullptr);
	}
}


void OdczytajZPliku(fstream & the_file, LotListItem* head)
{
	while (!the_file.eof())							
	{
		string linia;
		getline(the_file, linia);
		if (linia == "")
			break;
		const auto record = parse_record(linia);
		add_lot_pasazerSorted(head, record);
	}
	the_file.close();
}


void usunListePasazerow(PasazerListItem* head)	
{
	PasazerListItem* item = head;
	while (item) {
		auto p = item->nextPasazer;
		delete item;
		item = p;
	}
}

void usunListeLotow(LotListItem* head)	
{
	LotListItem* item = head;
	while (item) {
		auto p = item->nextLot;
		usunListePasazerow(item->firstPasazer);
		delete item;
		item = p;
	}
}