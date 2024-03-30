#ifndef SPAN_H
#define SPAN_H

#include <vector>

class Span
{
private:
		std::vector<int>  numberList;
		unsigned int    size;

public:
		Span(unsigned int N);
		~Span();


		void addNumber(int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		std::vector<int> getList();
		class TooFewElements : public std::exception {
			public:
				virtual const char* what() const throw() { return "too few elements on span\n"; }
		};
	
		class ExceededNumberElements : public std::exception {
			public:
				virtual const char* what() const throw() { return "exceeded the number of elements on span\n"; }
		};
};

#endif