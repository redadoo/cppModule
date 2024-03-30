
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	br = Bureaucrat("mario",10);
		Form		fr = Form("F24",100,23);
		br.signForm(fr);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}