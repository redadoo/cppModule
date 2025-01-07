#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <stdexcept>
#include <iomanip>
#include <cstddef>      
#include <algorithm>    
#include <iterator> 

template <typename Container>
struct IteratorGroup
{
    typedef typename Container::iterator Iterator;

	Iterator start;
	size_t size;      

    IteratorGroup()
        : size(0) {}

    IteratorGroup(Iterator start, size_t groupSize)
        : start(start), size(groupSize) {}

    IteratorGroup(Container &container, size_t groupSize) 
        : start(container.begin()), size(groupSize) {}
		
	Iterator GetLast(){
		return this->start + this->size;
	};

	bool operator==(const IteratorGroup &other) const;
	bool operator>(const IteratorGroup &other) const;
	bool operator<(const IteratorGroup &other) const;

	static void SwapIteratorGroup(IteratorGroup &first, IteratorGroup &second);
	static void FillVectorOfGroup(IteratorGroup &cont, std::vector<IteratorGroup<Container> > &toFill, size_t groupsSize);
	static void FillVectorOfGroup(Container &cont, std::vector<IteratorGroup<Container> > &toFill, size_t groupsSize);
	static void DivideGroup(std::vector<IteratorGroup<Container> > &toDivide, size_t groupsSize);
	static IteratorGroup<Container> VectorToGroup(std::vector<IteratorGroup<Container> > &toCopy);

};

template <typename T>
std::ostream& operator<<(std::ostream &o, const IteratorGroup<T> &i) 
{
	for (size_t idx = 0; idx < i.size + 1; ++idx)
		o << *(i.start + idx) << " ";
    return o;
}


class PmergeMe
{
private:
	std::vector<unsigned int> vect;
	std::list<unsigned int> list;

	void FillContainers(char **args, int argc);
	void SortVector();
	void PrintNumbers() const;
	void PrintPairs(int pairSize) const;
	int StringToInt(const std::string &str) const;

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
	PmergeMe(char **args, int argc);
	~PmergeMe();
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
	{
		_iter_swap(first.start, second.start);
	}
	else
	{
		_swap_ranges(first.start, first.start + first.size + 1, second.start);
	}
}

template <typename T>
inline void IteratorGroup<T>::FillVectorOfGroup(IteratorGroup &cont,  std::vector<IteratorGroup<T> > &toFill , size_t groupsSize)
{
	if (toFill.size() == 0)
	{
		
	}
	size_t rest = 0;
	while (rest <= cont.size)
	{
		toFill.push_back(IteratorGroup<T>(cont.start + rest, groupsSize - 1));
		rest += groupsSize;
	}
}

template <typename Container>
inline IteratorGroup<Container> IteratorGroup<Container>::VectorToGroup(std::vector<IteratorGroup<Container> > &toCopy)
{
	for (size_t i = 0; i < toCopy.size(); i++)
	{
		
	}
	
	(void)toCopy;
    return IteratorGroup<Container>();
}

template <typename T>
inline void IteratorGroup<T>::FillVectorOfGroup(T &cont,  std::vector<IteratorGroup<T> > &toFill , size_t groupsSize)
{
	size_t rest = 0;
	while (rest <= cont.size())
	{
		toFill.push_back(IteratorGroup<T>(cont.begin() + rest, groupsSize - 1));
		rest += groupsSize;
	}
}