#include "iter.hpp"
#include <iostream>

void add(int &x) { x++;}
void print(std::string &x) { std::cout << x << std::endl;}

int main( void ) {
	int array[20];

	for (size_t i = 0; i < 20; i++)
	{
		array[i] = i;
		std::cout << "elements at " << i << " is " << array[i] << std::endl;
	}
    
	iter(array, sizeof(array) / sizeof(array[0]),add);
	std::cout <<"after iter" << std::endl;

	for (size_t i = 0; i < 20; i++)
		std::cout << "elements at " << i << " is " << array[i] << std::endl;

	std::string stringArray[4] = {
		std::string("string1"),
		std::string("string2"),
		std::string("string3"),
		std::string("string4")
	};

	iter(stringArray,4,print);

	return 0;
}
