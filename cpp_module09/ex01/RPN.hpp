
#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <deque>

// RPN class for Reverse Polish Notation calculations
class RPN
{
    private:
        std::deque<std::string> revNotation;
        int                     result;
        
        // Checks if the token is a valid number or operator
        bool CheckError(const std::string &str);

        // Parses the input notation into tokens
        bool ParseArguments(std::string args);

        // Calculates the result from the parsed notation
        void CalculateResult();
    public:
        RPN(const std::string &notation);
        ~RPN();
};


#endif