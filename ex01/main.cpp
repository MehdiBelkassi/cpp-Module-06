#include <iostream>
#include <cstdint>
#include "Serializer.hpp"

int main()
{
	Data *data = new Data;


	data->value = 1950;

	uintptr_t raw = Serializer::serialize(data);
	std::cout << raw << std::endl;
	data = Serializer::deserialize(raw);
	std::cout << data->value << std::endl;
	return (0);
}
