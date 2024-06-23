/**
 * @file commands.cpp
 * @brief Definiuje funkcje odpowiadające komendom interfejsu. Tworzy obiekt biblioteki (Library) i nią zarządza.
 * 
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include "functions.hpp"
#include "library.hpp"
#include "item.hpp"
#include "book.hpp"

using namespace std;

Library library;

void addBook(vector<string> command)
{
	if (command.size() != 5)
	{
		cout << "Nieprawidłowa ilość argumentów!" << endl;
		return;
	}

	if (!checkIsbn(command[3]))
	{
		cout << "Niepoprawny numer ISBN" << endl;
		return;
	}
	
	if (!checkIfNumber(command[4]))
	{
		cout << "Niepoprawna wartość dla argumentu \'ilość\'!" << endl;
		return;
	}
	
	int quantity = stoi(command[4]);
	int id = makeUID();
	Book *book = new Book(id, command[1], command[2], command[3], quantity);

	if(!library.addItem(book))
	{
		cout << "Nie udało się dodać książki!" << endl;
	}
	else
	{
		cout << "==========================" << endl;
		book->show();
		cout << "==========================" << endl;
	}
}

void removeItem(vector<string> command)
{
	if (command.size() != 2)
	{
		cout << "Nieprawidłowa ilość argumentów!" << endl;
		return;
	}

	if (!checkIfNumber(command[1]))
	{
		cout << "Niepoprawna wartość dla argumentu ID!" << endl;
		return;
	}

	int id = stoi(command[1]);
	
	if(!library.removeItem(id))
	{
		cout << "Nie udało się usunąć przedmiotu!" << endl;
	}
}

void showItems(vector<string> command)
{
	Item *item;
	
	if (library.size() == 0)
	{
		return;
	}

	for (int i = 0; i < library.size(); i++)
	{
		item = library.getItem(i);
		cout << "==========================" << endl;
		item->show();
	}
	cout << "==========================" << endl;
}

void rentItem(vector<string> command)
{
	int id;

	if (command.size() != 2)
	{
		cout << "Nieprawidłowa ilość argumentów!" << endl;
		return;
	}

	if (!checkIfNumber(command[1]))
	{
		cout << "Niepoprawna wartość dla argumentu ID!" << endl;
		return;
	}

	id = stoi(command[1]);
	
	if(!library.rentItem(id))
	{
		cout << "Nie udało się wypożyczyć przedmiotu!" << endl;
	}
}

void returnItem(vector<string> command)
{
	int id;

	if (command.size() != 2)
	{
		cout << "Nieprawidłowa ilość argumentów!" << endl;
		return;
	}

	if (!checkIfNumber(command[1]))
	{
		cout << "Niepoprawna wartość dla argumentu ID!" << endl;
		return;
	}

	id = stoi(command[1]);
	
	if(!library.returnItem(id))
	{
		cout << "Nie udało się oddać przedmiotu!" << endl;
	}
}