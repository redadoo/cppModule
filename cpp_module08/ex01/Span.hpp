#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{
public:
		Span(unsigned int N);
		~Span();
		Span( const Span& src );
		Span& operator=( const Span& other );

		unsigned int 	shortestSpan();
		unsigned int 	longestSpan();
		void 			addNumber(int n);
		void 			addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

private:
		std::vector<int>  	numberList;
		unsigned int    	size;

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