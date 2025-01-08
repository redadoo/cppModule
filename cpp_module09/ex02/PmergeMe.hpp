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
#include <ctime> 

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

    IteratorGroup(std::vector<unsigned int> tmp) 
        : start(tmp.begin()), size(tmp.size() - 1) {}

	Iterator GetLast(){
		return this->start + this->size;
	};

	bool operator==(const IteratorGroup &other) const;
	bool operator>(const IteratorGroup &other) const;
	bool operator<(const IteratorGroup &other) const;

	static void SwapIteratorGroup(IteratorGroup &first, IteratorGroup &second);
	static void FillVectorOfGroup(IteratorGroup &cont, std::vector<IteratorGroup<Container> > &toFill, size_t groupsSize);
	static void VectorToGroup(IteratorGroup<Container> &con, std::vector<IteratorGroup<Container> > &toCopy);

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
	void SortList();
	void PrintVector() const;
	void PrintList() const;
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
	// std::cout << "this : " << *this << " other " << other << "\n";

	unsigned int firstValue = *(this->start + this->size);
	unsigned int secondValue = *(other.start + other.size);

	// std::cout << " firstValue " << firstValue << " secondValue " << secondValue << "\n";

	return firstValue > secondValue;
}

template <typename T>
bool IteratorGroup<T>::operator<(const IteratorGroup &other) const
{
	unsigned int firstValue = *(this->start + this->size);
	unsigned int secondValue = *(other.start + other.size);
	// std::cout << " firstValue " << firstValue << " secondValue " << secondValue << "\n";
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
	size_t rest = 0;
	while (rest <= cont.size)
	{
		toFill.push_back(IteratorGroup<T>(cont.start + rest, groupsSize - 1));
		rest += groupsSize;
	}
}

template <typename Container>
inline void IteratorGroup<Container>::VectorToGroup(IteratorGroup<Container> &con, std::vector<IteratorGroup<Container> > &toCopy)
{
	std::vector<unsigned int>tmp;
	for (size_t i = 0; i < toCopy.size(); i++)
		tmp.insert(tmp.end(), toCopy[i].start, toCopy[i].start + (toCopy[i].size + 1));
	con.start = tmp.begin();
	con.size = tmp.size() - 1;
}