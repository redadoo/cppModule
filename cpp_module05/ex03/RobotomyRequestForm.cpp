
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm ("RobotomyRequestForm", 72, 45) , target(_target) {
        srand (time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), target(src.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this == &src)
		return *this;
	AForm::operator=(src);
	target = src.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    int successfully;

    std::cout << "Zzzzzzzzzzzzz" << std::endl;
    successfully = (rand() % 10) + 1;
    if (successfully % 2 == 0)
        std::cout << executor << "has been robotomized successfully" << std::endl;
    else
        std::cout << " the robotomy failed" << std::endl;
    
}