#ifndef SERIALIZER_CLASS
#define SERIALIZER_CLASS

#include <iostream>
#include <stdint.h>

struct Data {
    std::string data;
    int number;
};

class Serializer
{
public:
    //Constructor / Destructor
    Serializer();
    ~Serializer();
    Serializer(const Serializer &cp);
    // Operator
    Serializer operator=(const Serializer &cp);
    //Methods
    uintptr_t serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);
};

#endif