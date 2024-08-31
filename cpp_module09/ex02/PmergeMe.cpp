#include "PmergeMe.hpp"

void PmergeMe::FillContainers()
{
	for (size_t i = 0; i < count; i++)
	{
		/* code */
	}
	
}

void PmergeMe::SetNumbersString(char **args, int argc)
{
	for (int i = 1; i < argc; i++)
	{
		numbers.append(args[i]);
		numbers.append(" ");
	}
}

PmergeMe::PmergeMe(char **args, int argc)
{
	SetNumbersString(args, argc);
}

PmergeMe::~PmergeMe() {}
