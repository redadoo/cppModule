#include "Harl.hpp"

int main() 
{

    std::string input;
    Harl        harl;

    while (1)
    {
        std::cout << "Enter a level: ";
        std::cin >> input;
        harl.complain(input);
        if(input.compare("exit") == 0)
        {
            break;
        }
    }

    return 0;
}