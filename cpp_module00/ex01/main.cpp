#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	std::string	command;
	PhoneBook	phoneBook;

	std::cout << "write ADD or SEARCH or EXIT on terminal any other command will be ignored" << std::endl; 
	while (true)
	{
		std::cin >> command;
		if (command == "ADD")
		{
			Contact		contact;
			contact.fillField();
			phoneBook.Add(contact);
		}
		if (command == "SEARCH")
		{
			int	index;
			std::cout << "insert contact index : " << std::endl;
			std::cin >> index;
			std::cout << std::endl;
			phoneBook.Search(index);
		}
		if (command == "EXIT")
			break ;
	}
	return 0;
}