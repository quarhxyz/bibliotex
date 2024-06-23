/**
 * @file library.hpp
 * @brief Definiuje klasę biblioteki (Library), przechowującą obiekty klas Book i Item.
 * 
 */

#ifndef LIBRARY
#define LIBRARY

#include <iostream>
#include "item.hpp"
#include "book.hpp"

using namespace std;

class Library
{
private:
	vector<Item*> items;
	bool searchById(int id, int *pos);
public:
	Item *getItem(int pos);

	int size();
	bool addItem(Item* item);
	bool removeItem(int id);
	bool rentItem(int id);
	bool returnItem(int id);
};

Item *Library::getItem(int pos)
{
	return this->items[pos];
}

int Library::size()
{
	return this->items.size();
}

bool Library::searchById(int id, int *pos)
{
	bool succes = false;
	int i;

	for (i = 0; i < this->size(); i++)
	{
		if (items[i]->getId() == id)
		{
			succes = true;
			*pos = i;
			break;
		}
	}
	
	return succes;
}

bool Library::addItem(Item* item)
{
	bool succes = true;

	if (item->getIsbn() != "")
	{
		for (int i = 0; i < this->size(); i++)
		{
			if (item->getIsbn() == items[i]->getIsbn())
			{
				succes = false;
			}
		}
	}
	
	if (succes == true)
	{
		this->items.push_back(item);
	}
	else
	{
		cout << "Książka o danym numerze ISBN już istnieje." << endl;
	}
	
	return succes;
}

bool Library::removeItem(int id)
{
	bool succes;
	int pos;

	succes = searchById(id, &pos);

	if (succes == true)
	{
		delete items[pos];
		this->items.erase(items.begin() + pos);
	}
	else
	{
		cout << "Nie ma przedmiotu o danym numerze ID." << endl;
	}
	
	return succes;
}

bool Library::rentItem(int id)
{
	bool succes;
	int pos;
	
	succes = searchById(id, &pos);
		
	if (succes == true)
	{
		succes = items[pos]->rentThis();
		cout << "==========================" << endl;
		items[pos]->show();
		cout << "==========================" << endl;
	}
	else
	{
		cout << "Nie ma przedmiotu o danym numerze ID." << endl;
	}
	
	return succes;
}

bool Library::returnItem(int id)
{
	bool succes;
	int pos;
	
	succes = searchById(id, &pos);
		
	if (succes == true)
	{
		succes = items[pos]->returnThis();
		cout << "==========================" << endl;
		items[pos]->show();
		cout << "==========================" << endl;
	}
	else
	{
		cout << "Nie ma przedmiotu o danym numerze ID." << endl;
	}
	
	return succes;
}

#endif