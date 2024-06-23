/**
 * @file functions.hpp
 * @brief Plik nagłówkowy zawierający deklaracje funkcji z plików functions.cpp i commands.cpp.
 * 
 */

#include <iostream>

using namespace std;

vector<string> processInput(char delimeter);

void addBook(vector<string> command);
void removeItem(vector<string> command);
void showItems(vector<string> command);
void rentItem(vector<string> command);
void returnItem(vector<string> command);

int makeUID();
bool checkIsbn(string isbn);
bool checkIfNumber(string arg);