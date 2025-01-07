
#include "PmergeMe.hpp"

int main (int argc ,char **argv)
{
	if (argc != 2)
	{
		std::cerr << "no number to sort" << std::endl;
		return(0);
	}

	try
	{
		PmergeMe pmergeMe(argv, argc);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}