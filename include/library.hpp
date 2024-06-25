/**
 * @file library.hpp
 * @brief Definiuje klasę biblioteki (Library), przechowującą obiekty klas Book i Item.
 * 
 */

#ifndef LIBRARY
#define LIBRARY

#include <iostream>
#include <vector>
#include "item.hpp"
#include "book.hpp"

using namespace std;

/**
 * @brief główna klasa programu, zawiera wektor items ze wszystkimi przedmiotami
 * znajdującymi się w bibliotece 
 * 
 */
class Library
{
private:
	vector<Item*> items;
public:
	~Library();

	int size();
	bool searchById(int id, int *pos);
	void showItem(int pos);
	bool addItem(Item* item);
	bool removeItem(int id);
	bool rentItem(int id);
	bool returnItem(int id);
};

Library::~Library()
{
	for (int i = 0; i < this->size(); i++)
	{
		delete this->items[i];
	}
}

/**
 * @brief zwraca ilość obiektów znajdujących się w bibliotece
 * 
 * @return int 
 */
int Library::size()
{
	return this->items.size();
}

/**
 * @brief wyszukuje pozycję przedmiotu po jego id
 * 
 * @param id 
 * @param pos zmienna int do której zapisywana jest pozycja przedmiotu w wektorze
 * @return true gdy znaleziono przedmiot
 * @return false gdy przedmiot nie został znaleziony
 */
bool Library::searchById(int id, int *pos)
{
	bool success = false;
	int i;

	for (i = 0; i < this->size(); i++)
	{
		if (items[i]->getId() == id)
		{
			success = true;
			*pos = i;
			break;
		}
	}
	
	return success;
}

/**
 * @brief wywołuje metodę show() dla obiektu klasy przedmiotu (Item lub Book)
 * 
 * @param pos 
 */
void Library::showItem(int pos)
{
	this->items[pos]->show();
}

/**
 * @brief dodaje przedmiot do klasy biblioteka
 * 
 * @param item wskaźnik na obiekt klasy Item
 * @return true jeżeli ISBN jest unikalny 
 * @return false jeżeli ISBN nie jest unikalny
 */
bool Library::addItem(Item* item)
{
	bool success = true;

	if (item->getIsbn() != "")
	{
		for (int i = 0; i < this->size(); i++)
		{
			if (item->getIsbn() == items[i]->getIsbn())
			{
				success = false;
			}
		}
	}
	
	if (success == true)
	{
		this->items.push_back(item);
		cout << "==========================" << endl;
		item->show();
		cout << "==========================" << endl;
	}
	else
	{
		cout << "Książka o danym numerze ISBN już istnieje." << endl;
	}
	
	return success;
}

/**
 * @brief usuwa przedmiot o danym ID
 * 
 * @param id 
 * @return true jeżeli przedmiot o danym ID istnieje
 * @return false jeżeli przedmiot o danym ID nie istnieje
 */
bool Library::removeItem(int id)
{
	bool success;
	int pos;

	success = searchById(id, &pos);

	if (success == true)
	{
		delete items[pos];
		this->items.erase(items.begin() + pos);
	}
	else
	{
		cout << "Nie ma przedmiotu o danym numerze ID." << endl;
	}
	
	return success;
}

/**
 * @brief „wypożycza” przedmiot za pomocą Item::rentThis()
 * 
 * @param id 
 * @return true jeżeli obiekt o danym ID istnieje
 * @return false jeżeli obiekt o danym ID nie istnieje
 */
bool Library::rentItem(int id)
{
	bool success;
	int pos;
	
	success = searchById(id, &pos);
		
	if (success == true)
	{
		success = items[pos]->rentThis();
	}
	else
	{
		cout << "Nie ma przedmiotu o danym numerze ID." << endl;
	}
	
	if (success == true)
	{
		cout << "==========================" << endl;
		items[pos]->show();
		cout << "==========================" << endl;
	}
	
	return success;
}

/**
 * @brief „zwraca” przedmiot za pomocą Item::returnThis()
 * 
 * @param id 
 * @return true jeżeli obiekt o danym ID istnieje
 * @return false jeżeli obiekt o danym ID nie istnieje
 */
bool Library::returnItem(int id)
{
	bool success;
	int pos;
	
	success = searchById(id, &pos);
		
	if (success == true)
	{
		success = items[pos]->returnThis();
	}
	else
	{
		cout << "Nie ma przedmiotu o danym numerze ID." << endl;
	}

	if (success == true)
	{
		cout << "==========================" << endl;
		items[pos]->show();
		cout << "==========================" << endl;
	}
	
	
	return success;
}

#endif