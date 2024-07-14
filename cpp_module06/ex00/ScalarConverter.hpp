#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>

#define FIXED_FLOAT(x) std::fixed <<std::setprecision(1)<<(x) 

#define ERROR_IMPOSSIBLE "impossible"
#define ERROR_NON_DISPLAYABLE "Non displayable"

class  ScalarConverter
{
private:
    ScalarConverter();
public:
    static void convert(const std::string& s);
};

#endif