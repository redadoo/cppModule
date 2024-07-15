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

void literalInt(int nbr)
{
	if (std::isprint(nbr))
		std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl; 
    else
		std::cout << "char: " << ERROR_NON_DISPLAYABLE  << std::endl;

	std::cout << "int: " << nbr << std::endl;
    std::cout << "float: " << FIXED_FLOAT(static_cast<float>(nbr))  << 'f' <<std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

void literalChar(char ch)
{
	if (std::isprint(ch))
		std::cout << "char: '" << ch  << "'" << std::endl; 
    else
		std::cout << "char: " << ERROR_NON_DISPLAYABLE  << std::endl;

	std::cout << "int: " << static_cast<int>(ch) << std::endl;
    std::cout << "float: " << FIXED_FLOAT(static_cast<float>(ch))  << 'f' <<std::endl;
    std::cout << "double: " << static_cast<double>(ch) << std::endl;
}

void literalFloat(float nbr)
{
	if (std::isprint(nbr))
		std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl; 
    else
		std::cout << "char: " << ERROR_NON_DISPLAYABLE  << std::endl;

	std::cout << "int: " << static_cast<int>(nbr) << std::endl;
    std::cout << "float: " << FIXED_FLOAT(static_cast<float>(nbr))  << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

void literalDouble(double nbr)
{
	if (std::isprint(nbr))
		std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl; 
    else
		std::cout << "char: " << ERROR_NON_DISPLAYABLE  << std::endl;

	std::cout << "int: " << static_cast<int>(nbr) << std::endl;
    std::cout << "float: " << FIXED_FLOAT(static_cast<float>(nbr))  << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

void printPseudoLiberal(std::string str)
{
	std::cout << "char: " << ERROR_IMPOSSIBLE  << std::endl;
	std::cout << "int: " << ERROR_IMPOSSIBLE << std::endl;
    std::cout << "float: " << str  << 'f' << std::endl;
    std::cout << "double: " << str << std::endl;
}

bool IsStringInt(const std::string& str)
{
	size_t i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;

	if (str.length() > MAX_STRING_LENGHT + i)
		return false;

	while (i < str.length())
	{
		if (isdigit(str[i]) == 0) 
			return false;
		i++;
	}
	return true;
}

bool IsStringFloat(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == 'f' || str[i] == '.') continue;
	
		if (!std::isdigit(str[i])) return false;
	}

	if ((str.find('f') != str.length() - 1) || (str.find('.') == 0))
		return false;

	return str.find('f') && str.find('.');
}

bool IsStringDouble(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.') continue;
	
		if (!std::isdigit(str[i])) return false;
	}

	if ((str.find('.') == 0))
		return false;

	return str.find('.');
}

Type GetVarType(const std::string& toConvert)
{
	if (toConvert.compare("-inff") == 0 || toConvert.compare("+inff") == 0|| 
		toConvert.compare("-inf") == 0 || toConvert.compare("+inf") == 0|| 
		toConvert.compare("nan") == 0)
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
