#include <string>
#include <stdexcept>
#include <iostream>

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class Bureaucrat
{
	private:
		const	std::string name;
		int		grade;

	public:
		Bureaucrat(std::string name, int grade);

		std::string getName() const;
		int			getGrade() const;
		void		incrementGrade();
        void decrementGrade();
        
		friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& br);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade too high\n"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade too low\n"; }
		};

};
#endif
