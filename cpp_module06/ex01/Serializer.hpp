#include <string>
#include <stdint.h>

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

struct Data
{
    int id;
    std::string name;

    Data(int _id, std::string _name);
};

class Serializer
{
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
private:
    Serializer();
};

#endif 
