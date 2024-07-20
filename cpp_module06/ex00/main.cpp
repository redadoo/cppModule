#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
    if (argc != 2) return 1;
    
    ScalarConverter::convert(argv[1]);


    ScalarConverter::convert("0");
    std::cout << "\n";
    ScalarConverter::convert("nan");
    std::cout << "\n";
    ScalarConverter::convert("42.0f");
    std::cout << "\n";
}
