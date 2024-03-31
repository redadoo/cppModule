#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
	private:
		Contact contacts[8];
		
	public:
		PhoneBook();

		void Add(Contact contact);
		void Search(std::string index);
};

#endif