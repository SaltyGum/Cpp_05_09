#include "Serializer.hpp"

int main() { 
    Data *ship = new Data;
    Serializer serial;


    ship->data = "Zaphod";
    ship->number = 42;
    std::cout << "Zaphod going through a portal -> " << ship->data << std::endl;
    std::cout << "42 is the answer reaching Zaphod -> " << ship->number << std::endl << std::endl;

    uintptr_t portal = serial.serialize(ship);
    
    std::cout << "Portal loop to a distant galaxy address -> " << portal << std::endl << std::endl;

    Data *two = serial.deserialize(portal);

    std::cout << "Zaphod back from the portal -> " << two->data << std::endl;
    std::cout << "The asnwer still the same... -> " << two->number << std::endl;

    delete ship;
}