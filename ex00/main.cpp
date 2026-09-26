#include "ScalarConverter.hpp"

int main()
{
    ScalarConverter f;

    // char d = static_cast<char>(100000); // int to double   

    // printf("%c", d);

    printf("%d", f.isChar("ab"));
    return 0;
}