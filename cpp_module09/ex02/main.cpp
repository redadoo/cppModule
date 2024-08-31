
#include "PmergeMe.hpp"

int main (int argc ,char **argv)
{
    if (argc < 2)
    {
		std::cerr << "no number to sort" << std::endl;
        return(0);
    }

    PmergeMe pmergeMe(argv, argc);
}