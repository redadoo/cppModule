#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	Span sp = Span(10000);

	for (size_t i = 0; i < 10000; i++)
	{
		sp.addNumber(i);
	}
	

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
