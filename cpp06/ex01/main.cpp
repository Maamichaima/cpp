#include "Serializer.hpp"

int main()
{
	Data d;
	d.x = 10;
	uintptr_t c = Serializer::serialize(&d);
	std::cout << &d << std::endl;
	std::cout << c << std::endl;
	Data* ptr=  Serializer::deserialize(c);
	std::cout << ptr << std::endl;
	std::cout << ptr->x;
}