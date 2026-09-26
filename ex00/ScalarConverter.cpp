#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void) other;
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &other)
{
    (void)other;
    std::cout << "Assignment operator called" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    if (literal == "nan" || literal == "nanf"
        || literal == "+inf" || literal == "-inf"
        || literal == "+inff" || literal == "-inff")
    {
        if (literal == "nan" || literal == "nanf")
            std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
        else if (literal == "+inf" || literal == "+inff")
            std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
        else
            std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
    }
    else if (isChar(literal))
        handleChar(literal);
    else if (isInt(literal))
        handleInt(literal);
    else if (isFloat(literal))
        handleFloat(literal);
    else if (isDouble(literal))
        handleDouble(literal);
    else
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}
