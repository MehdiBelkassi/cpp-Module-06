#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <cctype>
#include <iomanip>


class ScalarConverter
{   private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &other);
        ScalarConverter& operator=(ScalarConverter const &other);
        ~ScalarConverter();
        
        static bool isChar(const std::string &param);
        static bool isInt(const std::string &param);
        static bool isFloat(const std::string &param);
        static bool isDouble(const std::string &param);

    public:
        static void convert(const std::string &literal);
};

void    handleInt(const std::string &literal);
void    handleChar(const std::string &literal);
void    handleFloat(const std::string &literal);
void    handleDouble(const std::string &literal);

