/**
 * @file functions.cpp
 * @brief Definicje przydatnych funkcji.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int uid = 0;

vector<string> processInput()
{
	vector<string> command;
	string buffer;
	char c;
	bool state_a = false;
	bool state_b = false;

	while ((c = cin.get()) != '\n' && cin)
	{
		if ((c == ' ' || c == '\t') && state_b == false)
		{
			if (state_a == true)
			{
				command.push_back(buffer);
				buffer.clear();
			}
			state_a = false;
		}
		else if (c == '\"')
		{
			if (state_b == true)
			{
				state_b = false;
			}
			else if (state_b == false)
			{
				state_b = true;
			}
		}
		else
		{
			state_a = true;
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
	bool success = false;
	string buff;

	if (isbn.size() == 13)
	{
		success = true;
	}
	
	if (!(success == true && (buff = isbn.substr(0, 3)) == "978" || buff == "979"))
	{
		success = false;
	}
	
	return success;
}

bool checkIfNumber(string arg)
{
	bool success = true;

	for (int i = 0; i < arg.size() && arg[i] != '\0'; i++)
	{
		if (arg[i] < '0' || arg[i] > '9')
		{
			success = false;
			break;
		}
	}
	
	return success;
}