//
// Created by chaed on 18. 11. 25.
//

#ifndef TERIS_FIGURE_CLASS_TTYPETRAITS_H
#define TERIS_FIGURE_CLASS_TTYPETRAITS_H

#include <cstdlib>
#include <random>
#include <ctime>
#include <memory>

#include "TType.h"

namespace tetris
{

template<class T>
constexpr  auto toUType(T enuml) 
{
    return static_cast<std::underlying_type_t<T>>(enuml);
}

template <class T>
struct EnumIterator
{
    T value;
    
    EnumIterator()
        :value(T::Begin)
    {}
    
    T begin() 
    {
        value = static_cast<T>( toUType(value) << 1);
        return value;
    }
    
    bool end()  
    {
        return toUType(value) != toUType(T::End);
    }
    
    EnumIterator operator++()
    {
        value = (T)(toUType(value) << 1);
        return *this;
    }
    
    bool operator!=( EnumIterator *other)
    {
        return toUType(value) != toUType(other->value);
    }
};

template <class T>
class EnumHelper
{
public:

    static T getRandomly()
    {
        auto rnd = rand()%(toUType(T::End)-toUType(T::Begin)+1);
        return T(rnd);
    }
    
    static  T getRandomly( T begin,  T end)
    {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(toUType(begin), toUType(end));
        return T(distribution(generator));
    }

private:

    EnumHelper()
    {

    }

};

}
#endif //TERIS_FIGURE_CLASS_TTYPETRAITS_H
