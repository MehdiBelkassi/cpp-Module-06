#include "Base.hpp"
#include <iostream>

Base::Base()
{
	std::cout << "Default constructor called" << std::endl;
}

Base::Base(const Base &obj)
{
	(void) obj;
	std::cout << "Copy constructor called" << std::endl;
}

Base& Base::operator=(const Base &obj)
{
	(void) obj;
	std::cout << "Assignment operator called" << std::endl;
	return (*this);
}

Base::~Base()
{
	std::cout << "Destructor called" << std::endl;
}
