#include "RPN.hpp"

bool RPN::CheckError(const std::string& str)
{
		if (str.length() > 1)
			return false;
		if (std::isdigit(str[0]) == 0)
		{
			if (str[0] != '*' && str[0] != '+' && str[0] != '-' && str[0] != '/')
				return false;
		}
		return true;
}

bool RPN::ParseArguments(std::string notation)
{
	size_t pos = 0;
	std::string token;
	while ((pos = notation.find(' ')) != std::string::npos) 
	{
		token = notation.substr(0, pos);

		if(!CheckError(token))
			return false;
		
		this->revNotation.push_back(token);
		notation.erase(0, pos + 1);
	}
	if(!CheckError(notation))
		return false;	
	this->revNotation.push_back(notation);
	return true;
}

void RPN::CalculateResult()
{
	int first = -1;
	for (std::deque<std::string>::iterator it = revNotation.begin(); it != revNotation.end(); ++it) 
	{
		char ch = it->at(0);

		if (ch >= '0' && ch <= '9')
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

RPN::~RPN() {}
