/**
 * @file main.cpp
 * @brief Główny plik programu, tworzy interfejs i przetwarza wejście.
 * 
 */

#include <iostream>

#define PROMPT "(cli) "
#define INITIAL_MESSAGE "System biblioteczny Bibliotex. Wpisz \'help\', aby uzyskać więcej informacji.\n"
#define HELP_TEXT \
	"quit - Opuszcza program.\n" \
	"help - Wyświetla informacje o komendach\n" \
	"TODO!!!\n"

using namespace std;

vector<string> processInput(char delimeter);
bool processCommand(vector<string> command);

int main(void)
{
	bool quit = false;
	vector<string> command;
	
	cout << INITIAL_MESSAGE;
	
	while (!quit && cin)
	{
		cout << PROMPT;

		command = processInput(' ');

		if (!command.empty())
		{
			quit = processCommand(command);
		}
	}
	
	if (!cin)
	{
		cout << endl;
	}
	
	return EXIT_SUCCESS;
}

vector<string> processInput(char delimiter)
{
	vector<string> command;
	string buffer;
	char c;
	bool state = false;

	while ((c = cin.get()) != '\n' && cin)
	{
		if (c == delimiter || c == '\t')
		{
			if (state == true)
			{
				command.push_back(buffer);
				buffer.clear();
			}
			state = false;
		}
		else
		{
			state = true;
			buffer += c;
		}
	}
	
	if (buffer != "" && c == '\n')
	{
		command.push_back(buffer);
	}
	
	return command;
}

void addBook(vector<string> command);
void removeBook(vector<string> command);
void showBooks(vector<string> command);

bool processCommand(vector<string> command)
{
	if (command[0] == "quit")
	{
		return true;
	}
	else if (command[0] == "help")
	{
		cout << HELP_TEXT;
	}
	else if (command[0] == "add")
	{
		addBook(command);
	}
	else if (command[0] == "remove")
	{
		removeBook(command);
	}
	else if (command[0] == "show")
	{
		showBooks(command);
	}
	else
	{
		cout << "Nieznana komenda!" << endl;
	}
	
	return false;
}