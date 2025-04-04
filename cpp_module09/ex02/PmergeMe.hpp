#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <iterator>
#include <stdexcept>
#include <algorithm>    
#include <ctime>

template <typename Container>
struct IteratorGroup
{
	typedef typename Container::iterator Iterator;

	Iterator start;
	size_t size;      

	IteratorGroup();
	IteratorGroup(Iterator start, size_t groupSize);
	IteratorGroup(Container &container, size_t groupSize);

	Iterator GetLast();

	bool operator==(const IteratorGroup &other) const;
	bool operator>(const IteratorGroup &other) const;
	bool operator<(const IteratorGroup &other) const;

	static void SwapIteratorGroup(IteratorGroup &first, IteratorGroup &second);
	static void FillVectorOfGroup(IteratorGroup &cont, std::vector<IteratorGroup<Container> > &toFill, size_t groupsSize);
	static void FillDequeOfGroup(IteratorGroup &cont, std::deque<IteratorGroup<Container> > &toFill, size_t groupsSize);

};

template <typename T>
IteratorGroup<T>::IteratorGroup() 
{ 
	this.size = 0;
}

template <typename T>
IteratorGroup<T>::IteratorGroup(Iterator start, size_t groupSize)
{
	this->start = start;
	this->size = groupSize;
}

template <typename Container>
IteratorGroup<Container>::IteratorGroup(Container &container, size_t groupSize)
{
	this->start = container.begin();
	this->size = groupSize;
}

template <typename Container>
typename Container::iterator IteratorGroup<Container>::GetLast()
{
	return this->start + this->size;
};

class PmergeMe
{
private:
	static const unsigned long long jacobsthal_diff[];
	
	std::vector<unsigned int> vect;
	std::deque<unsigned int> deq;

	void FillContainers(char **args, int argc);
	int StringToInt(const std::string &str) const;
	
	void SortDeque();
	void PrintDeque() const;
	int	 SortDequePairs(int pairSize);
	void MergeInsertionDeque(int pairSize, int oddSize);

	void SortVector();
	void PrintVector() const;
	int	 SortVectorPairs(int pairSize);
	void MergeInsertionVector(int pairSize, int oddSize);

	class FoundNegativeNumber : public std::exception
	{
	public:
		const char *what() const throw() { return "Found a negative number"; }
	};

	class NotDigitFound : public std::exception
	{
	public:
		const char *what() const throw() { return "Found a non-digit character"; }
	};

public:

	PmergeMe();
	PmergeMe(char **args, int argc);
	PmergeMe( const PmergeMe& src );
	PmergeMe& operator=( const PmergeMe& other );
	~PmergeMe();

	void Sort();
};

#endif

template<class ForwardIt1, class ForwardIt2>
void _iter_swap(ForwardIt1 a, ForwardIt2 b)
{
	using std::swap;
	swap(*a, *b);
}

template<class ForwardIt1, class ForwardIt2>
ForwardIt2 _swap_ranges(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2)
{
	for (; first1 != last1; ++first1, ++first2)
		_iter_swap(first1, first2);
 
	return first2;
}

template <typename T>
bool IteratorGroup<T>::operator==(const IteratorGroup &other) const
{
	return start == other.start && size == other.size;
}

template <typename T>
bool IteratorGroup<T>::operator>(const IteratorGroup &other) const
{
	unsigned int firstValue = *(this->start + this->size);
	unsigned int secondValue = *(other.start + other.size);
	return firstValue > secondValue;
}

template <typename T>
bool IteratorGroup<T>::operator<(const IteratorGroup &other) const
{
	unsigned int firstValue = *(this->start + this->size);
	unsigned int secondValue = *(other.start + other.size);
	return firstValue < secondValue;
}

template <typename T>
void IteratorGroup<T>::SwapIteratorGroup(IteratorGroup &first, IteratorGroup &second)
{
	if (first.size == 0 && second.size == 0)
		_iter_swap(first.start, second.start);
	else
		_swap_ranges(first.start, first.start + first.size + 1, second.start);
}

template <typename T>
inline void IteratorGroup<T>::FillVectorOfGroup(IteratorGroup &cont, std::vector<IteratorGroup<T> > &toFill, size_t groupsSize)
{
	size_t rest = 0;
	while (rest <= cont.size)
	{
		toFill.push_back(IteratorGroup<T>(cont.start + rest, groupsSize - 1));
		rest += groupsSize;
	}
}

template <typename T>
inline void IteratorGroup<T>::FillDequeOfGroup(IteratorGroup &cont, std::deque<IteratorGroup<T> > &toFill, size_t groupsSize)
{
	size_t rest = 0;
	while (rest <= cont.size)
	{
		toFill.push_back(IteratorGroup<T>(cont.start + rest, groupsSize - 1));
		rest += groupsSize;
	}
}