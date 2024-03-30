
#include "Bureaucrat.hpp"
#include <iostream>
int main()
{
	try
	{
		Bureaucrat bureaucrat1 = Bureaucrat("luca",0);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what();
	}

    try
    {
        Bureaucrat bureaucrat2 = Bureaucrat("marco",1);
		for (size_t i = 0; i < 151; i++)
		{
			std::cout << bureaucrat2;
			bureaucrat2.decrementGrade();
		}
    }
    catch(std::exception & e)
    {
        std::cerr << e.what();
    }
}