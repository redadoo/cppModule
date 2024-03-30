#include "Contact.hpp"

void    Contact::fillField()
{
    std::cout << "first name :" << std::endl;
    std::cin >> this->first_name;
    std::cout << "last name :" << std::endl;
    std::cin >> this->last_name;
    std::cout << "nickname :" << std::endl;
    std::cin >> this->nickname;
    std::cout << "number :" << std::endl;
    std::cin >> this->number;
    std::cout << "darkest secret :" << std::endl;
    std::cin >> this->darkest_secret;
    std::cout << "you have created a new user in the phone book called " << this->first_name << std::endl;
}

std::string truncateString(const std::string& str) 
{
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void    Contact::displayField(size_t index)
{
    std::cout << std::setiosflags (std::ios_base::right);

    std::cout << "|"<< std::setw(10) << "INDEX" << "|" << std::setw(10) << index << "|"<< std::endl;
    std::cout << "|"<< std::setw(10) << "FIRST NAME" << "|" << std::setw(10) << truncateString(this->first_name) << "|"<< std::endl;
    std::cout << "|"<< std::setw(10) << "LAST NAME" << "|" << std::setw(10) << truncateString(this->last_name) << "|" << std::endl;
    std::cout << "|"<< std::setw(10) << "NICKNAME" << std::setw(1) << "|" << std::setw(10) << truncateString(this->nickname) << "|" << std::endl;
}

bool    Contact::isEmpty()
{
    return (this->first_name.empty());
}
