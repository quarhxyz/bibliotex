/**
 * @file item.hpp
 * @brief Definiuje klasę przedmiotu (Item) zamieszczanego w bibliotece.
 * 
 */

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>

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
	Item();
	Item(int id, string name, string author, int quantity);
	
	int getId();
	string getName();
	string getAuthor();
	int getQuantity();
	int getAvailable();
	
	bool rentThis();
	bool returnThis();
	
	virtual string getIsbn() {return "";}
	virtual void show() {}
};

Item::Item() {}
Item::Item(int id, string name, string author, int quantity)
{
	this->id = id;
	this->name = name;
	this->author = author;
	this->quantity = quantity;
	this->available = quantity;
}

int Item::getId()
{
	return this->id;
}

string Item::getName()
{
	return this->name;
}

string Item::getAuthor()
{
	return this->author;
}

int Item::getQuantity()
{
	return this->quantity;
}

int Item::getAvailable()
{
	return this->available;
}

bool Item::rentThis()
{
	bool succes = true;
	
	if (this->available != 0)
	{
		this->available--;
	}
	else
	{
		cout << "Brak kopii do wypożyczenia." << endl;
		succes = false;
	}
	
	return succes;
}

bool Item::returnThis()
{
	bool succes = true;
	
	if (this->available < this->quantity)
	{
		this->available++;
	}
	else
	{
		cout << "Wszystkie kopie są dostępne, chyba komuś się biblioteka pomyliła." << endl;
		succes = false;
	}
	
	return succes;
}

#endif