/**
 * @file functions.cpp
 * @brief Definicje przydatnych funkcji.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int uid = 0;

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

int makeUID()
{
	return uid++;
}

bool checkIsbn(string isbn)
{
	return true;
}

bool checkIfNumber(string arg)
{
	bool succes = true;

	for (int i = 0; i < arg.size() && arg[i] != '\0'; i++)
	{
		if (arg[i] < '0' && arg[i] > '9')
		{
			succes = false;
			break;
		}
	}
	
	return succes;
}