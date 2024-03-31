#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	std::string	command;
	PhoneBook	phoneBook;

	std::cout << "write ADD or SEARCH or EXIT on terminal any other command will be ignored" << std::endl; 
	while (true)
	{
		std::cout << "insert Command : ";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			Contact		contact;
			contact.fillField();
			phoneBook.Add(contact);
		}
		else if (command == "SEARCH")
		{
			std::cout << "insert contact index : " << std::endl;
			std::getline(std::cin, command);
			std::cout << std::endl;
			phoneBook.Search(command);
		}
		else if (command == "EXIT")
		{
			std::cout << "\nGoodbye\n";
			break ;
		}
	}
	return 0;
}