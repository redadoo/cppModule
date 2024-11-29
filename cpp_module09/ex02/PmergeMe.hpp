#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>

class PmergeMe
{
private:
	bool                isOdd;
	int                 straggler;
	std::vector< int>   vec;
	std::list< int>     list;

	void FillContainers(char **args, int argc);
	int StringToInt(const std::string& str);
	void PrintNumbers();
	void MergeInsertionSort(std::vector<int> &vec);
	void MergeInsertionSort(std::list<int> &list);

	class FoundNegativeNumber : public std::exception {
		public:
			virtual const char* what() const throw() { return "found a negative number\n"; }
	};

	class NotDigitFound : public std::exception {
		public:
			virtual const char* what() const throw() { return "found a non digit char\n"; }
	};

public:
	void Sort();
	
	PmergeMe(char **args, int argc);
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	
	~PmergeMe();
};

#endif