
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name) , grade(_grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (grade > 149)
		throw Bureaucrat::GradeTooHighException();
}

std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooHighException();
	this->grade++;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooLowException();
	this->grade--;
}

void    Bureaucrat::signForm( AForm& form ) {
    try {
        form.beSigned( *this );
        std::cout << *this << " signed " << form.getName() << std::endl;
    } catch ( AForm::GradeTooLowException& e ) {
        std::cout << name << " coulnd't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& br)
{
	os << br.getName() << " bureaucrat grade " << br.getGrade() << std::endl;
	return os;
}
