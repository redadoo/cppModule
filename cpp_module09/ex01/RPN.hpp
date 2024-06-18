
#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <deque>

class RPN
{
    private:
        std::deque<std::string> revNotation;
        
        bool ParseArguments(std::string args);
    public:
        RPN(char **args);
        ~RPN();
};


#endif