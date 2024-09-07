#include "PmergeMe.hpp"

int PmergeMe::StringToInt(const std::string& str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]) == 0)
			throw NotDigitFound();
	}
	
	std::stringstream ss(str);
	int number;
	ss >> number;
	if (ss.fail())
		throw std::runtime_error("Invalid string to convert to int");
	if (number < 0)
		throw FoundNegativeNumber();
		
	return number;
}

void PmergeMe::PrintNumbers()
{
	std::vector< int>::iterator it1;
	for (it1 = vec.begin(); it1 != vec.end(); ++it1)
		std::cout << *it1 << " ";
	std::cout << std::endl;	
}


void PmergeMe::Sort()
{
	double time;

	std::cout << "numbers pre sort : ";
	PrintNumbers();

	clock_t start = clock();
	MergeInsertionSort(vec);
	clock_t end = clock();
	
	time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << std::fixed << std::setprecision(10) << "Time to process a range of " << this->vec.size() << " elements with std::vector: " << time << " s" << std::endl;
}

void PmergeMe::FillContainers(char **args, int argc)
{
	for (int i = 1; i < argc; i++)
	{
		std::string number(args[i]);
		if (number.find(" ") != std::string::npos)
		{
			std::istringstream tokenStream(number);
			std::string token;
			while (std::getline(tokenStream, token, ' '))
			{
				int n = StringToInt(token);
				vec.push_back(n);
				list.push_back(n);
			}
		}
		else
		{
			int n = StringToInt(number);
			vec.push_back(n);
			list.push_back(n);
		}
	}
}

PmergeMe::PmergeMe(char **args, int argc)
{
	FillContainers(args, argc);
}

PmergeMe::~PmergeMe() {}
