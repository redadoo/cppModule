#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data *data1 = new Data(1,"luca"); 

    uintptr_t ser;
    ser = Serializer::serialize(data1);

    Data *test; 
    test = Serializer::deserialize(ser);

    if (test == data1)
    {
        std::cout << test->name <<"\n";
    }

}