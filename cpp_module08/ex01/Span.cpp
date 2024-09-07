#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span(unsigned int _size) : size(_size) {}

Span::Span(const Span &src) : numberList(src.numberList), size(src.size) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other) {
        numberList = other.numberList;
        size = other.size;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (numberList.size() == this->size)
		throw Span::ExceededNumberElements();
	numberList.push_back(n);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) + numberList.size() > size) 
        throw ExceededNumberElements();

    numberList.insert(numberList.end(), begin, end);
}

bool compare(int x, int y) { return (x > y);}

unsigned int Span::shortestSpan()
{
	unsigned int shortest;

	if (numberList.size() < 2)
		throw Span::TooFewElements();

	std::vector<int> tmp = numberList;
	std::sort(tmp.begin(), tmp.end(), compare);
	
	shortest = tmp.at(0) - tmp.at(1);
	for (size_t i = 1; i < tmp.size() - 1; i++)
	{
		if ((int)shortest > tmp.at(i) - tmp.at(i + 1))
			shortest = tmp.at(i) - tmp.at(i + 1);
	}
	return shortest;
}

unsigned int Span::longestSpan()
{
	if (numberList.size() < 2)
		throw Span::TooFewElements();
	std::vector<int> tmp = numberList;
	std::sort(tmp.begin(), tmp.end(), compare);
	return std::distance(tmp.begin(), tmp.end());
}