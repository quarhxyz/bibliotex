/**
 * @file functions.hpp
 * @brief zawierający deklaracje funkcji z plików functions.cpp i commands.cpp.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief przetwarza dane wejściowe, pobiera znaki ze standardowego strumienia wejściowego
 * i zapisuje kolejne słowa lub grupy słów ujęte w cudzysłów do kolejnych pól wektora command
 * 
 * @return vector<string> komenda do wykonania przez główny program
 */
vector<string> processInput();

/**
 * @brief funkcja odpowiadająca komendzie interfejsu, dodaje nową książkę
 * 
 * @param command wektor zwracany przez processInput()
 * 
 */
void addBook(vector<string> command);

/**
 * @brief funkcja odpowiadająca komendzie interfejsu, usuwa przedmiot
 * 
 * @param command wektor zwracany przez processInput()
 */
void removeItem(vector<string> command);

/**
 * @brief funkcja odpowiadająca komendzie interfejsu, wyświetla wszystkie przedmioty znajdujące się w Bibliotece (Library)
 * 
 * @param command wektor zwracany przez processInput()
 */
void showItems(vector<string> command);

/**
 * @brief funkcja odpowiadająca komendzie interfejsu, „wypożycza” przedmiot, zmniejsza ilość dostępnych przedmiotów
 * w obiekcie klasy Item za pomocą metody Library::rentItem()
 * 
 * @param command wektor zwracany przez processInput()
 */
void rentItem(vector<string> command);

/**
 * @brief funkcja odpowiadająca komendzie interfejsu, „zwraca” przedmiot, zwiększa ilość dostępnych przedmiotów
 * w obiekcie klasy Item za pomocą metody Library::returnItem()
 * 
 * @param command wektor zwracany przez processInput()
 */
void returnItem(vector<string> command);

/**
 * @brief generuje unikalny identyfikator numeryczny
 * 
 * @return int identyfikator
 */
int makeUID();

/**
 * @brief sprawdza poprawność kodu ISBN
 * 
 * @param isbn string zawierający kod ISBN
 * @return true jeżeli kod ISBN jest zgodny ze standardem (składa się z trzynastu cyfr
 * oraz zawiera prefiks 978 lub 979)
 * @return false jeżeli zadana wartość wejściowa nie jest poprawnym kodem ISBN
 */
bool checkIsbn(string isbn);

/**
 * @brief sprawdza czy wartość wejściowa arg jest liczbą
 * 
 * @param arg string
 * @return true 
 * @return false 
 */
bool checkIfNumber(string arg);

/**
 * @brief czyści zawartość ekranu
 * 
 */
void clearScreen();