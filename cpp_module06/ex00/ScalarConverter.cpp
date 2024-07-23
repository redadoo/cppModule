#include "ScalarConverter.hpp"

enum Type
{
    _char,
    _int,
    _float,
    _double,
	_pseudoLiterals,
	_none
};

int countOccurance(const std::string & str, char ch)
{
	int nOccurance = 0;
	int strSize = str.size();

	for(int i = 0; i < strSize; i++)
		if (str[i] == ch) nOccurance++;

	return nOccurance;
}

int	stringToInt(const std::string& str)
{
	int num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

float stringToFloat(const std::string& str)
{
	float num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

double	stringToDouble(const std::string& str)
{
	double num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

void PrintFloat(float nbr)
{
	if (nbr - static_cast<int>(nbr) != 0)
		std::cout << "float: " << nbr << "f" << std::endl;
	else
		std::cout << "float: " << nbr << ".0" <<"f" << std::endl;
}

void PrintDouble(double nbr)
{
	if (nbr - static_cast<int>(nbr) != 0)
		std::cout << "double: " << nbr << std::endl;
	else
		std::cout << "double: " << nbr << ".0" << std::endl;
}

void literalInt(int nbr)
{
	if (nbr>= 32 && nbr <= 126)
		std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl; 
    else
		std::cout << "char: " << ERROR_NON_DISPLAYABLE  << std::endl;

	std::cout << "int: " << nbr << std::endl;
	PrintFloat(static_cast<float>(nbr));
	PrintDouble(static_cast<double>(nbr));
}

void literalChar(char ch)
{
	if (ch>= 32 && ch <= 126)
		std::cout << "char: '" << ch  << "'" << std::endl; 
    else
		std::cout << "char: " << ERROR_NON_DISPLAYABLE  << std::endl;

	std::cout << "int: " << static_cast<int>(ch) << std::endl;
	PrintFloat(static_cast<float>(ch));
	PrintDouble(static_cast<double>(ch));
}

void literalFloat(float nbr)
{
	if (nbr>= 32 && nbr <= 126)
		std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl; 
    else
		std::cout << "char: " << ERROR_NON_DISPLAYABLE  << std::endl;

	std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	PrintFloat(static_cast<float>(nbr));
	PrintDouble(static_cast<double>(nbr));
}

void literalDouble(double nbr)
{
	if (nbr>= 32 && nbr <= 126)
		std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl; 
    else
		std::cout << "char: " << ERROR_NON_DISPLAYABLE  << std::endl;


	std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	PrintFloat(static_cast<float>(nbr));
	PrintDouble(static_cast<double>(nbr));
}

void printPseudoLiberal(std::string str)
{
	std::cout << "char: " << ERROR_IMPOSSIBLE  << std::endl;
	std::cout << "int: " << ERROR_IMPOSSIBLE << std::endl;
	
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("inff") == 0 || str.compare("nanf") == 0)
		std::cout << "float: " << str << std::endl;
	else
		std::cout << "float: " << str << "f" << std::endl;

	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("inff") == 0 || str.compare("nanf") == 0)
		std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
	else
		std::cout << "double: " << str << std::endl;
}

bool IsStringInt(const std::string& str)
{
	int i = 0;
	int strLength = str.length();

	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}

	if (strLength > 10 + i)
		return false;

	while (i < strLength)
	{
		if (!std::isdigit(str[i])) return false;
		i++;
	}
	return true;
}

bool IsStringFloat(const std::string& str)
{
	int i = 0;
	int strLength = str.length();

	if (str[i] == '-' || str[i] == '+')
		i++;

	while (i < strLength)
	{
		if (str[i] == 'f' || str[i] == '.')
		{
			i++;
			continue;
		}

		if (!std::isdigit(str[i])) return false;

		i++;
	}
	
	return 	str.find('f') != std::string::npos 	&& 
			str.find('.') != std::string::npos 	&&
			countOccurance(str, '.') == 1		&&
			countOccurance(str, 'f') == 1		&&
			str.find('f') == str.length() - 1	&&
			str.find('.') != str.length() - 2;
}

bool IsStringDouble(const std::string& str)
{
	int i = 0;
	int strLength = str.length();

	if (str[i] == '-' || str[i] == '+')
		i++;
	
	while (i < strLength)
	{
		if (str[i] == '.')
		{
			i++;
			continue;
		}
		if (!std::isdigit(str[i])) return false;
		i++;
	}

	return 	str.find('.') != std::string::npos 	&&
			countOccurance(str, '.') == 1		&&
			str.find('.') < str.length() - 1;
}

Type GetVarType(const std::string& toConvert)
{
	if (toConvert.compare("-inff") == 0 || toConvert.compare("+inff") == 0|| 
		toConvert.compare("-inf") == 0 || toConvert.compare("+inf") == 0|| 
		toConvert.compare("nan") == 0 || toConvert.compare("nanf") == 0)
		return _pseudoLiterals;
	if (toConvert.length() == 1 && !std::isdigit(toConvert[0]))
		return _char;
	if (IsStringInt(toConvert))
		return _int;
	if (IsStringFloat(toConvert))
		return _float;
	if (IsStringDouble(toConvert))
		return _double;
	return _none;
}

void ScalarConverter::convert(const std::string& toConvert)
{
	switch (GetVarType(toConvert))
	{
	case _char:
		literalChar(toConvert[0]);
		break;

	case _int:
		literalInt(stringToInt(toConvert));
		break;
	
	case _float:
		literalFloat(stringToFloat(toConvert));
		break;

	case _double:
		literalDouble(stringToDouble(toConvert));
		break;

	case _pseudoLiterals:
		printPseudoLiberal(toConvert);
		break;
	
	case _none:
		std::cout << "is none \n";
		break;
	}
}
