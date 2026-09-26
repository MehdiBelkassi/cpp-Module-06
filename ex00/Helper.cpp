#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(const std::string &param)
{
    if (param.length() != 1)
        return false;
    if (std::isdigit(static_cast<unsigned char>(param[0])))
        return false;
    return std::isprint(static_cast<unsigned char>(param[0]));
}

bool ScalarConverter::isInt(const std::string &param)
{
    if (param.empty())
        return false;

    size_t start = 0;
    if (param[0] == '+' || param[0] == '-')
        start += 1;      

    if (start == param.length())
        return false;

    for (size_t i = start; i < param.length(); i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(param[i])))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string &param)
{
    if (param.empty())
        return false;

    if (param[param.length() - 1] != 'f')
        return false;

    size_t start = 0;
    if (param[0] == '+' || param[0] == '-')
        start += 1;

    if (start == param.length() - 1) // "f" for that case
        return false;

    bool dotSeen = false;
    for (size_t i = start; i < param.length() - 1; i++)
    {
        if (param[i] == '.')
        {
            if (dotSeen)
                return false;
            dotSeen = true;
        }
        else if (!std::isdigit(static_cast<unsigned char>(param[i])))
            return false;
    }
    return true;
}

bool ScalarConverter::isDouble(const std::string &param)
{
    if (param.empty())
        return false;

    size_t start = 0;
    if (param[0] == '+' || param[0] == '-')
        start += 1;

    bool dotSeen = false;
    bool digitSeen = false;

    for (size_t i = start; i < param.length(); i++)
    {
        if (param[i] == '.')
        {
            if (dotSeen)
                return false;
            dotSeen = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(param[i])))
            digitSeen = true;
        else
            return false;
    }
    return digitSeen;
}
