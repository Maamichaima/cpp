#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <iostream>

typedef struct s_data
{
	int x;
} Data;

class Serializer
{
	private:
		
	public:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif