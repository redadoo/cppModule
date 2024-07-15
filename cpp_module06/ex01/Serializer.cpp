#include "Serializer.hpp"

// uintptr_t Serializer::serialize(Data *ptr)
// {
//     return reinterpret_cast<uintptr_t>(ptr);
// }

// Data *Serializer::deserialize(uintptr_t raw)
// {
//     return reinterpret_cast<Data *>(raw);
// }

Data::Data(int _id, std::string _name)
{
    this->id = _id;
    this->name = name;
}
