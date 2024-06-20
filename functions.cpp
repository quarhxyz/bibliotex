/**
 * @file functions.cpp
 * @brief Definicje przydatnych funkcji.
 * 
 */

#include <iostream>

using namespace std;

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