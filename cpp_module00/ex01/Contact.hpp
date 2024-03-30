#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string first_name;
		std::string nickname;
		std::string last_name;
		std::string number;
		std::string darkest_secret;

	public:
		void	displayField(size_t index);
		void	fillField();
		bool	isEmpty();
};

#endif
