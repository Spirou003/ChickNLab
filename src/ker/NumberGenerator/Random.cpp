#include "Random.hpp"
#include <ctime>
#include <cstdio>
#include <stdexcept>


Random::Random(uint32_t a, uint32_t m, uint32_t c) throw():
Random_a(a), Random_m(m), Random_Seed(0), Random_x(0), Random_c(c)
{
    Random_Seed = time(00);
    Random_x = Random_Seed;
}

Random::~Random(){}

void Random::SetSeed(uint32_t s) throw()
{
    Random_Seed = s;
    Random_x = s;
    Random_c = 0;
}

uint32_t Random::GetSeed() throw()
{
    return Random_Seed;
}

uint32_t Random::NextInt() throw()
{
    uint64_t temp = Random_x;
    Random_x = (Random_a * temp + Random_c) % Random_m;
    Random_c = (Random_a * temp + Random_c) / Random_m;
    return Random_x;
}


