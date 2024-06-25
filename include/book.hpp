/**
 * @file book.hpp
 * @brief Definiuje klasę książki (Book), pochodną klasy Item.
 * 
 */

#ifndef BOOK
#define BOOK

#include <iostream>
#include <vector>
#include "item.hpp"

using namespace std;

/**
 * @brief definiuje obiekt książki
 * 
 */
class Book : public Item
{
private:
	string isbn;
public:
	Book(int id, string name, string author, string isbn, int quantity);

	virtual string getIsbn();

	virtual void show();
};

Book::Book(int id, string name, string author, string isbn, int quantity)
: Item(id, name, author, quantity)
{
	this->isbn = isbn;
}

/**
 * @brief zwraca kod ISBN książki reprezentowanej obiektem
 * 
 * @return string 
 */
string Book::getIsbn()
{
	return this->isbn;
}

/**
 * @brief wyświetla informacje o książce 
 * 
 */
void Book::show()
{
	cout << "ID: " << this->getId() << endl;
	cout << "Nazwa: " << this->getName() << endl;
	cout << "Autor: " << this->getAuthor() << endl;
	cout << "ISBN: " << this->getIsbn() << endl;
	cout << "Ilość: " << this->getQuantity() << endl;
	cout << "Dostępne sztuki: " << this->getAvailable() << endl;
}

#endif