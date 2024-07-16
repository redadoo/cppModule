
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

bool Form::getIsSigned() const
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
	this->isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& fr)

{
 	os << fr.getName() << 
	" Form info : grade to sign " << 
	fr.getGradeToSign() << 
	" Form grade to execute "<< 
	fr.getGradeToExecute();

	os << " Form is ";
	if (fr.getIsSigned())
		os << "signed ";
	else
		os << "not signed ";
	os << std::endl;
 	return os;
}

Form::Form(const Form& src) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
}

Form& Form::operator=(const Form& src)
{
	if (this == &src)
		return *this;
	isSigned = src.isSigned;
	return *this;
}

Form::~Form()
{
}


