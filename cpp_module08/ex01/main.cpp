#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        Span sp2 = Span(100000);
        std::vector<int> more_numbers;

		for (size_t i = 0; i < 100000; i++)
			more_numbers.push_back(i);
		
        sp2.addNumbers(more_numbers.begin(), more_numbers.end());

        std::cout << "Shortest Span (sp2): " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span (sp2): " << sp2.longestSpan() << std::endl;

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
