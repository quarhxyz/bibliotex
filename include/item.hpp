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

/**
 * @brief klasa bazowa elementu w bibliotece
 * 
 */
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

/**
 * @brief zwraca unikalny identyfikator obiektu klasy generowany przez makeUID()
 * 
 * @return int 
 */
int Item::getId()
{
	return this->id;
}

/**
 * @brief zwraca nazwę przedmiotu
 * 
 * @return string 
 */
string Item::getName()
{
	return this->name;
}

/**
 * @brief zwraca autora
 * 
 * @return string 
 */
string Item::getAuthor()
{
	return this->author;
}

/**
 * @brief zwraca całkowitą ilość przedmiotów
 * 
 * @return int 
 */
int Item::getQuantity()
{
	return this->quantity;
}

/**
 * @brief zwraca ilość dostępnych przedmiotów
 * 
 * @return int 
 */
int Item::getAvailable()
{
	return this->available;
}

/**
 * @brief „wypożycza” jeden przedmiot zmniejszając ilość dostępnych przedmiotów (available)
 * 
 * @return true „wypożyczenie” przebiegło pomyślnie (przedmiot jest dostępny)
 * @return false „wypożyczenie” nie przebiegło pomyślnie (przedmiot nie jest dostępny)
 */
bool Item::rentThis()
{
	bool success = true;
	
	if (this->available != 0)
	{
		this->available--;
	}
	else
	{
		cout << "Brak kopii do wypożyczenia." << endl;
		success = false;
	}
	
	return success;
}

/**
 * @brief „zwraca” jeden przedmiot zwiększając ilość dostępnych przedmiotów (available)
 * 
 * @return true „zwrot” przebiegł pomyślnie
 * @return false „zwrot” nie przebiegł pomyślnie
 */
bool Item::returnThis()
{
	bool success = true;
	
	if (this->available < this->quantity)
	{
		this->available++;
	}
	else
	{
		cout << "Wszystkie kopie są dostępne, chyba komuś się pomyliła biblioteka." << endl;
		success = false;
	}
	
	return success;
}

#endif