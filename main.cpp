/**
 * @file main.cpp
 * @brief Główny plik programu, tworzy interfejs i przetwarza wejście.
 * 
 */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <locale>
#include "functions.hpp"

#define PROMPT "(cli) "
#define INITIAL_MESSAGE "System biblioteczny Bibliotex. Wpisz \'help\', aby uzyskać więcej informacji.\n"
#define HELP_TEXT \
	"quit - Opuszcza program.\n" \
	"clear - Czyści zawartość ekranu.\n" \
	"help - Wyświetla informacje o komendach.\n" \
	"show - Wyświetla wszystkie przedmioty w bibliotece.\n" \
	"addbook <nazwa> <autor> <ISBN> <ilość> - Dodaje książke.\n" \
	"remove <ID> - Usuwa przedmiot z biblioteki.\n" \
	"rent <ID> - Wypożycza kopie przedmiotu z biblioteki.\n" \
	"return <ID> - Zwraca kopie przedmiotu do biblioteki.\n" \

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "pl_PL.UTF-8");

	bool quit = false;
	vector<string> command;
	
	cout << INITIAL_MESSAGE;
	
	while (!quit && cin)
	{
		cout << "\033[1;31m"; // set color to bold red
		cout << PROMPT;
    	cout << "\033[0m"; // reset color to default

		command = processInput();

		if (!command.empty())
		{
			
			if (command[0] == "quit")
			{
				quit = true;
			}
			else if (command[0] == "clear")
			{
				clearScreen();
			}
			else if (command[0] == "help")
			{
				cout << HELP_TEXT;
			}
			else if (command[0] == "addbook")
			{
				addBook(command);
			}
			else if (command[0] == "remove")
			{
				removeItem(command);
			}
			else if (command[0] == "show")
			{
				showItems(command);
			}
			else if (command[0] == "rent")
			{
				rentItem(command);
			}
			else if (command[0] == "return")
			{
				returnItem(command);
			}
			else
			{
				cout << "Nieznana komenda!" << endl;
			}
		}
	}
	
	if (!cin)
	{
		cout << endl;
	}
	
	return EXIT_SUCCESS;
}