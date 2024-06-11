/**
 * @file main.cpp
 * @brief Główny plik programu, tworzy interfejs i przetwarza wejście.
 * 
 */

#include <iostream>

using namespace std;

string prompt = "(cli) ";
string initialMessage = "System biblioteczny Bibliotex. Wpisz \'help\', aby uzyskać więcej informacji.\n";
string helpText =
	"quit - Opuszcza program.\n"
	"help - Wyświetla informacje o komendach\n"
	"TODO!!!\n";

vector<string> processInput(char delimeter);
bool processCommand(vector<string> command);

int main(void)
{
	bool quit = false;
	vector<string> command;
	
	cout << initialMessage;
	
	while (!quit && cin)
	{
		cout << prompt;

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

void addBook(vector<string> command);
void removeBook(vector<string> command);
void showBooks(vector<string> command);

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

bool processCommand(vector<string> command)
{
	if (command[0] == "quit")
	{
		return true;
	}
	else if (command[0] == "help")
	{
		cout << helpText;
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