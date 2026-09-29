#include "ScalarConverter.hpp"

void handleInt(const std::string &literal)
{
    long value = std::strtol(literal.c_str(), NULL, 10);

    if (value < std::numeric_limits<int>::min()
        || value > std::numeric_limits<int>::max())
    {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }

    int number = static_cast<int>(value);

    if (number < std::numeric_limits<char>::min()
        || number > std::numeric_limits<char>::max())
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (!std::isprint(static_cast<unsigned char>(number)))
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
    }

    std::cout << "int: " << number << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(number) << std::endl;
}

void handleChar(const std::string &literal)
{
    char c = literal[0];

    std::cout << "char: '" << c << "'" << "\nint: " << static_cast<int>(c) << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void handleFloat(const std::string &literal)
{
    errno = 0;

    double value = std::strtod(literal.c_str(), NULL);

    if (errno == ERANGE
        || value > std::numeric_limits<float>::max()
        || value < -std::numeric_limits<float>::max())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << value << std::endl;
        return;
    }

    float number = static_cast<float>(value);

    if (static_cast<double>(number) < std::numeric_limits<char>::min()
        || static_cast<double>(number) > std::numeric_limits<char>::max())
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (!std::isprint(static_cast<unsigned char>(number)))
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
    }

    if (static_cast<double>(number) < std::numeric_limits<int>::min()
        || static_cast<double>(number) > std::numeric_limits<int>::max())
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << static_cast<int>(number) << std::endl;
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << number << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(number) << std::endl;
}

void handleDouble(const std::string &literal)
{
    errno = 0;

    double number = std::strtod(literal.c_str(), NULL);

    if (errno == ERANGE)
    {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }

    if (number < std::numeric_limits<char>::min()
        || number > std::numeric_limits<char>::max())
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (!std::isprint(static_cast<unsigned char>(number)))
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
    }

    if (number < std::numeric_limits<int>::min()
        || number > std::numeric_limits<int>::max())
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << static_cast<int>(number) << std::endl;
    }

    if (number < -std::numeric_limits<float>::max()
        || number > std::numeric_limits<float>::max())
    {
        std::cout << "float: impossible" << std::endl;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << number << std::endl;
}
