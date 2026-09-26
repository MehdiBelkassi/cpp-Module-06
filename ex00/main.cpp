#include "ScalarConverter.hpp"


int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
}
