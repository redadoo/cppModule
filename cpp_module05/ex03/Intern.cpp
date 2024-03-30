#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string formName, std::string formTarger)
{
    std::string arrayFormName[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };

    AForm*    forms[] = {
        new RobotomyRequestForm( formTarger ),
        new PresidentialPardonForm( formTarger ),
        new ShrubberyCreationForm( formTarger )
    };

    for ( size_t i = 0 ; i < 3; i++ ) 
    {
        if ( formName == arrayFormName[i] ) 
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i];
        }
    }
    std::cout << "Intern cannot create " << formName << " form" << std::endl;
    return NULL;
}
