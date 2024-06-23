/**
 * @file main.cpp
 * @brief Główny plik programu, tworzy interfejs i przetwarza wejście.
 * 
 */

#include <iostream>
#include <stdlib.h>
#include "functions.hpp"
#define PROMPT "(cli) "
#define INITIAL_MESSAGE "System biblioteczny Bibliotex. Wpisz \'help\', aby uzyskać więcej informacji.\n"
#define HELP_TEXT \
	"quit - Opuszcza program.\n" \
	"help - Wyświetla informacje o komendach\n" \
	"TODO!!!\n"

using namespace std;

int main(void)
{
	bool quit = false;
	vector<string> command;
	
	cout << INITIAL_MESSAGE;
	
	while (!quit && cin)
	{
		cout << "\033[1;31m"; // set color to bold red
		cout << PROMPT;
    	cout << "\033[0m"; // reset color to default

		command = processInput(' ');

		if (!command.empty())
		{
			
			if (command[0] == "quit")
			{
				quit = true;
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
