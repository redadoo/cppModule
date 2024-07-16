
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

public:

	Form(std::string name, int _gradeToSign, int _gradeToExecute);
	Form(const Form &other);
	Form &operator=(const Form& other);
	~Form();
	
	std::string 		getName() const;
	bool				getIsSigned() const;
	int 				getGradeToSign() const;
	int 				getGradeToExecute() const;
	void				beSigned(const Bureaucrat &br);

private:
	std::string const   name;
	bool				isSigned;
	int const			gradeToSign;
	int const			gradeToExecute;

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade too high\n"; }
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade too low\n"; }
	};
};

	std::ostream& operator<<(std::ostream& os, const Form& br);

#endif