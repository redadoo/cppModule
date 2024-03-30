
#include <string>
#include <iostream>


int main()
{
	std::string sentence = "HI THIS IS BRAIN";

	std::string *stringPTR = &sentence;
	std::string &stringREF = sentence;

    std::cout << &sentence << ": " << sentence << std::endl;
    std::cout << stringPTR << ": " << *stringPTR << std::endl;
    std::cout << &stringREF << ": " << stringREF << std::endl;
}