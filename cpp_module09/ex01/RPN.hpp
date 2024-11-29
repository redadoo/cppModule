
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
		int result;

		int StringToInt(const std::string &str);
		bool CheckError(const std::string &str);
		bool Resolve(const std::string& args);
};


#endif