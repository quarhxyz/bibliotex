/**
 * @file classes.hpp
 * @brief Definiuje klasę biblioteki (Library), przedmiotu zamieszczanego w bibliotece (Item) i jego pochodne np. klasę książki (Book).
 * 
 */

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

class Library
{
private:
	vector<Item> Items;
public:
	int size()
	{
		return this->Items.size();
	}

	void addItem(Item item)
	{
		this->Items.push_back(item);
	}

	void addItem(Book book)
	{
		this->Items.push_back(book);
	}

	bool removeItem(int id)
	{
		for (int i = 0; i < this->size(); i++)
		{
			if (this->Items[i].getId() == id)
			{
				this->Items.erase(Items.begin() + i);
				return true;
			}
		}
		
		return false;
	}
	
	void showAllItems()
	{
		for (int i = 0; i < this->size(); i++)
		{
			cout << "========================" << endl;
			this->Items[i].show();
		}
		cout << "========================" << endl;
	}
	
};