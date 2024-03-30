
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
private:
    
public:
    Intern();
    ~Intern();

    AForm *makeForm(std::string formName, std::string formTarger);
};

#endif