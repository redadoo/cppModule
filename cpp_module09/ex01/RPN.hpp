
#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <stack>

// RPN class for Reverse Polish Notation calculations
class RPN
{
	public:
		RPN(const std::string &notation);
		RPN(const RPN &src);
		RPN &operator=(const RPN &other);
		~RPN();

	private:
		std::deque<std::string> revNotation;
		int                     result;

		int StringToInt(const std::string &str);


		// Checks if the token is a valid number or operator
		bool CheckError(const std::string &str);

		// Parses the input notation into tokens
		bool ParseArguments(const std::string& args);
};


#endif