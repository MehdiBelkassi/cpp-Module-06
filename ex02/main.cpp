#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <typeinfo>

Base *generate()
{
	srand(static_cast<unsigned int>(time(0)));

	switch (rand() % 3 + 1) {
		case 1:
			return (new A());
		case 2:
			return (new B());
		case 3:
			return (new C());
		default:
			return (NULL);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
	} catch(const std::bad_cast &) {}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
	} catch(const std::bad_cast &) {}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
	} catch(const std::bad_cast &) {}
}

int main()
{
	Base *base = generate();
	if (base)
	{
		identify(base);
		identify(*base);
		delete base;
	}
	else
		std::cerr << "Failed to generate a valid object" << std::endl;
	return (0);
}
