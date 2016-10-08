#ifndef CHICKNLAB_KER_MAPGENERATOR_CIRCLESBASED_HPP
#define CHICKNLAB_KER_MAPGENERATOR_CIRCLESBASED_HPP

#include "../MapGenerator.hpp"

class NumberGenerator;

class MapGeneratorCirclesBased: public MapGenerator
{
    public:
        MapGeneratorCirclesBased();
        virtual ~MapGeneratorCirclesBased();

        virtual void Generate(uint16_t width, uint16_t height, MapWriter & map);

        NumberGenerator * rng;
        uint16_t p, q;
        bool symetric;
};


#endif
