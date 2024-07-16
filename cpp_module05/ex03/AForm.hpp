
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

private:
	std::string const   name;
	bool				isSigned;
	int const			gradeToSign;
	int const			gradeToExecute;

public:

	AForm(std::string name, int _gradeToSign, int _gradeToExecute);
	AForm(const AForm &other);
	AForm &operator=(const AForm& other);
	
	virtual    ~AForm();

	std::string 		getName() const;
	bool				getIsSigned() const;
	int 				getGradeToSign() const;
	int 				getGradeToExecute() const;
	void				beSigned(const Bureaucrat &br);

	virtual void		execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade too high\n"; }
	};
	
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade too low\n"; }
	};
	
	class FormNotSigned : public std::exception {
		public:
			virtual const char* what() const throw() { return "form not signed\n"; }
	};

};

	std::ostream& operator<<(std::ostream& os, const AForm& br);

#endif