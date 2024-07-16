
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	br = Bureaucrat("mario",10);
		Form		fr = Form("F24",100,23);
		std::cout << fr;
		br.signForm(fr);
		std::cout << fr;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat	br = Bureaucrat("luigi",1);
		Form		fr = Form("F24",112300,23);
		std::cout << fr;
		br.signForm(fr);
		std::cout << fr;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	
}