#pragma once


#include <string>
#include <cstdint>
#include <iostream>
#include <sys/types.h>

typedef struct Data
{
	int value;
} Data;


class Serializer
{
    private:
        Serializer();
        Serializer(std::string const &param);
        Serializer& operator=(Serializer const &other);
        ~Serializer();
    
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);


};
