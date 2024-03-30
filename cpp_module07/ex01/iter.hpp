#ifndef ITER_HPP
#define ITER_HPP

#include <cstdio>

template<typename T>
void iter(T *array, size_t arrayLength, void (*func)(T&))
{
    for (size_t i = 0; i < arrayLength; i++)
    {
        func(array[i]);
    }
}

#endif