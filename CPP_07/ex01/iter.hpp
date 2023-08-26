#ifndef ITER_
#define ITER_

#include <iostream>

template <typename AnyT>
void iter(AnyT *array, size_t lenght, void (*func)(AnyT &))
{
    for(size_t i = 0; i < lenght; i++)
        func(array[i]);
}

template <typename AnyT>
void printer (AnyT param)
{
    std::cout << param << " HA HA " << std::endl;
}

#endif