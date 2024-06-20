/**
 * @file functions.hpp
 * @brief Plik nagłówkowy zawierający deklaracje funkcji z plików functions.cpp i commands.cpp.
 * 
 */

#include <iostream>

using namespace std;

vector<string> processInput(char delimeter);
void addBook(vector<string> command);
void removeBook(vector<string> command);
void showBooks(vector<string> command);
