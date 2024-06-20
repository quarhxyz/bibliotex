/**
 * @file library.hpp
 * @brief Definiuje klasę biblioteki (Library), przechowującą obiekty klas Book i Item.
 * 
 */


#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include "item.hpp"
#include "book.hpp"

using namespace std;

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

#endif