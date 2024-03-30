#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardonForm", 25, 5), target(_target)
{

}
PresidentialPardonForm::~PresidentialPardonForm()
{

}

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw AForm::GradeTooLowException();
    else {
        std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}