#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& src)
{
	(void)src;
}

Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	return *this;
}

Intern::~Intern()
{}

AForm *Intern::makeForm(std::string formName, std::string formTarger)
{
    std::string arrayFormName[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };

    AForm*  form;
	int i = 0;
    
    while (i < 3 && formName.compare(arrayFormName[i]))
    {
        i++;
    }

	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(formTarger);
			break;
		case 1:
			form = new RobotomyRequestForm(formTarger);
			break;
		case 2:
			form = new PresidentialPardonForm(formTarger);
			break;
		default:
            std::cout << "Intern cannot create " << formName << " form" << std::endl;
			return NULL;
	}
    std::cout << "Intern creates " << formName << std::endl;
    return form;
}
