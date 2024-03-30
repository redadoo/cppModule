#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span(unsigned int _size) : size(_size) {}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (numberList.size() == this->size)
		throw Span::ExceededNumberElements();
	numberList.push_back(n);
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
	std::sort(tmp.begin(), tmp.end(),compare);
	return tmp.at(0) - tmp.at(tmp.size() - 1);
}

std::vector<int> Span::getList()
{
	return this->numberList;
}