#include <cstdint>
#include <string>

struct Data
{
    int id;
    std::string name;

    Data(int _id, std::string _name);
};

// class Serializer
// {
// public:
//     static uintptr_t serialize(Data* ptr);
//     static Data* deserialize(uintptr_t raw);
// private:
//     Serializer();
// };

