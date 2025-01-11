#include "RPN.hpp"

RPN::RPN(const std::string &notation)
{
	Resolve(notation);
}

RPN::RPN(const RPN &src)
{
	this->result = src.result;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		this->result = other.result;
	return *this;
}

RPN::~RPN() {}

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

bool RPN::Resolve(const std::string& notation) 
{
	std::istringstream iss(notation);
	std::string token;
	std::stack<int> stack;

	while (iss >> token) 
	{
		if (!CheckError(token) && token.length() > 1) 
		{
			std::cerr << "Error with token: " << token << std::endl;
			return false;
		}

		if (isdigit(token[0]) || isdigit(token[1])) 
			stack.push(StringToInt(token));
		else 
		{
			if (stack.size() < 2) 
			{
				std::cerr << "Error: stak size < 2" << std::endl;
				return false;
			}

			int operand2 = stack.top();
			stack.pop();
			int operand1 = stack.top();
			stack.pop();

			if (token == "+") 
				stack.push(operand1 + operand2);
			else if (token == "-") 
				stack.push(operand1 - operand2);
			else if (token == "*") 
				stack.push(operand1 * operand2);
			else if (token == "/") 
			{
				if (operand2 == 0) 
				{
					std::cerr << "Error: Division by zero" << std::endl;
					return false;
				}
				stack.push(operand1 / operand2);
			}
		}
	}

	if (stack.size() == 1) 
	{
		result = stack.top();
		std::cout << result << std::endl;
		return true;
	} 
	else 
	{
		std::cerr << "Error" << std::endl;
		return false;
	}
}

int RPN::StringToInt(const std::string &str) {
	std::istringstream iss(str);
	int num;
	iss >> num;
	return num;
}
