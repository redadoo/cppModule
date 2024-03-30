
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string target;
    
public:
    PresidentialPardonForm(std::string _targer);
    ~PresidentialPardonForm();

    void execute(const Bureaucrat& executor) const;
};

#endif