
#include "Form.hpp"


Form::Form(std::string _name, int _gradeToSign, int _gradeToExecute) : 
    name(_name), 
    gradeToSign(_gradeToSign),
    gradeToExecute(_gradeToExecute)  
{
    isSigned = false;

	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooLowException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooHighException();
}

std::string Form::getName() const
{
	return this->name;
}

int Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}

bool Form::getIsSigned()
{
	return this->isSigned;
}

int Form::getGradeToSign() const
{
	return this->gradeToSign;
}

void Form::beSigned(const Bureaucrat &br )
{
	if(br.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& fr)

{
 	os << fr.getName() << " Form info : grade to sign " << fr.getGradeToSign() << " Form grade to execute "<< fr.getGradeToExecute() << std::endl;
 	return os;
}


