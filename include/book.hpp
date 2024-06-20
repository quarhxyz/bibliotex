/**
 * @file book.hpp
 * @brief Definiuje klasę książki (Book), pochodną klasy Item.
 * 
 */

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include "item.hpp"

using namespace std;

class Book : public Item
{
private:
	int isbn;
public:
	Book(int id, string name, string author, int isbn, unsigned int quantity) : Item(id, name, author, quantity)
	{
		this->isbn = isbn;
	}
	
	int getIsbn()
	{
		return this->isbn;
	}

	virtual void show()
	{
		cout << "ID: " << this->getId() << endl;
		cout << "Nazwa: " << this->getName() << endl;
		cout << "Autor: " << this->getAuthor() << endl;
		cout << "ISBN: " << this->getIsbn() << endl;
		cout << "Ilość: " << this->getQuantity() << endl;
		cout << "Dostępne sztuki: " << this->getAvailable() << endl;
	}
};

#endif