#include "RPN.hpp"

bool RPN::CheckError(const std::string& str)
{
	if (str.length() == 1)
	{
		char ch = str[0];
		if (isdigit(ch) || ch == '*' || ch == '+' || ch == '-' || ch == '/')
			return true;
	}
	return false;
}

bool RPN::ParseArguments(std::string notation)
{
	std::istringstream iss(notation);
	std::string token;
	while (iss >> token) 
	{
		if(!CheckError(token))
			return false;
		
		this->revNotation.push_back(token);
	}
	return true;
}

void RPN::CalculateResult()
{
	int first = -1;
	for (std::deque<std::string>::iterator it = revNotation.begin(); it != revNotation.end(); ++it) 
	{
		char ch = it->at(0);

		if (isdigit(ch))
		{
			if (first == -1)
				first = ch - '0';
			else
				result = ch - '0';
		}
		else
		{
			switch (ch)
			{
				case '*':
					result = result * first;
				break;
				case '+':
					result = result + first;
				break;
				case '-':
					result = result - first;
				break;
				case '/':
					result = result / first;
				break;
			}
			first = -1;
		}
	}
}

RPN::RPN(const std::string &notation)
{
	if (!ParseArguments(notation))
		return;

	result = 0;
	CalculateResult();
	std::cout << result << std::endl;
}

RPN::RPN(const RPN &src)
{
	this->revNotation = src.revNotation;
	this->result = src.result;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
	{
		this->revNotation = other.revNotation;
		this->result = other.result;
	}
    return *this;
}

RPN::~RPN() {}
