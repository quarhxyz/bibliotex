/**
 * @file item.hpp
 * @brief Definiuje klasę przedmiotu (Item) zamieszczanego w bibliotece.
 * 
 */

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class Item
{
private:
	int id;
	string name;
	string author;
	int quantity;
	int available;
public:
	Item() {}

	Item(int id, string name, string author, int quantity)
	{
		this->id = id;
		this->name = name;
		this->author = author;
		this->quantity = quantity;
		this->available = quantity;
	}
	
	int getId()
	{
		return this->id;
	}

	string getName()
	{
		return this->name;
	}

	string getAuthor()
	{
		return this->author;
	}

	int getQuantity()
	{
		return this->quantity;
	}

	int getAvailable()
	{
		return this->available;
	}
	
	virtual void show()
	{
		cout << "ID: " << this->getId() << endl;
		cout << "Nazwa: " << this->getName() << endl;
		cout << "Autor: " << this->getAuthor() << endl;
		cout << "Ilość: " << this->getQuantity() << endl;
		cout << "Dostępne sztuki: " << this->getAvailable() << endl;
	}
};

#endif