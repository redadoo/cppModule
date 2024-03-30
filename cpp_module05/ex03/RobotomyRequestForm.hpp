#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm : public AForm
{
private:
    std::string target;
    
public:
    RobotomyRequestForm(std::string _name);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;

};

#endif