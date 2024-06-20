#include <iostream>
#include "classes.hpp" 
using namespace std;

int main()
{
	Library library;
	
	Item item1(333, "nazwez", "anon", 5);
	Item item2(222, "foo", "anon", 6);
	Book book1(444, "nazwez", "anon", 123456, 5);
	Book book2(555, "foo", "anon", 1234, 6);
	
	library.addItem(item1);
	library.addItem(item2);
	library.addItem(book1);
	library.addItem(book2);
	
	library.showAllItems();

	return 0;
}