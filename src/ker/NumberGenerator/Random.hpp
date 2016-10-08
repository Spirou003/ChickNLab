#ifndef CHICKNLAB_NUMBERGENERATORRANDOM_HPP
#define CHICKNLAB_NUMBERGENERATORRANDOM_HPP

#include "../NumberGenerator.hpp"

// remettre toString et fromString


class Random : public NumberGenerator
{
    public:
        Random(uint32_t a = 1103515245, uint32_t m = 12345, uint32_t c = 0) throw();
        Random(Random const & r) = default;
        Random & operator=(Random const & r) = default;
        ~Random();
        void SetSeed(uint32_t s) throw();
        uint32_t GetSeed() throw();
        uint32_t NextInt() throw();

        uint32_t Random_a, Random_m;
        uint32_t Random_Seed;
        uint32_t Random_x, Random_c;
};


#endif
