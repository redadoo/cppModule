
#include "RPN.hpp"

int main (int argc ,char **argv)
{
    if (argc != 2)
    {
		std::cerr << "no number to found" << std::endl;
        return(1);
    }

    RPN rpn(argv[1]);
}