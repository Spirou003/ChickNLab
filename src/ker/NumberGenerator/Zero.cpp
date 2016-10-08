#include "Zero.hpp"
#include <ctime>
#include <cstdio>
#include <stdexcept>


Zero * Zero::instance = 00;

Zero::Zero(){}
Zero::~Zero(){}

uint32_t Zero::NextInt() throw()
{
    return 0;
}

NumberGenerator * Zero::GetInstance()
{
    if (instance == 00)
        instance = new Zero();
    return instance;
}


