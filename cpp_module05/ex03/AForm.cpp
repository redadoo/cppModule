
#include "AForm.hpp"


AForm::AForm(std::string _name, int _gradeToSign, int _gradeToExecute) : 
    name(_name), 
    gradeToSign(_gradeToSign),
    gradeToExecute(_gradeToExecute)  
{
    isSigned = false;

	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooLowException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooHighException();
}

AForm::~AForm()
{
	
}

std::string AForm::getName() const
{
	return this->name;
}

int AForm::getGradeToExecute() const
{
    return this->gradeToExecute;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

void AForm::beSigned(const Bureaucrat &br )
{
	if(br.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& fr)

{
 	os << fr.getName() << " Form info : grade to sign " << fr.getGradeToSign() << " Form grade to execute "<< fr.getGradeToExecute() << std::endl;
 	return os;
}


