#include "RPN.hpp"

bool RPN::ParseArguments(std::string args)
{
    return false;
}

RPN::RPN(char **args)
{
    std::string notation (args[1]);
    if (!ParseArguments(notation))
        return ;
}

RPN::~RPN()
{

}
