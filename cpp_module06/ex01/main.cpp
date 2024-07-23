#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data(42, "they not like us");

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Raw: " << raw << std::endl;
	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Ptr: " << ptr << std::endl;

	std::cout << "Data: " << ptr->name << " " << ptr->id << std::endl;

	return 0;

}