#ifndef CHICKNLAB_KER_MAPGENERATOR_HPP
#define CHICKNLAB_KER_MAPGENERATOR_HPP

#include <cstdint>

class MapWriter;

class MapGenerator
{
    public:
        MapGenerator();
        virtual ~MapGenerator();

        virtual void Generate(uint16_t width, uint16_t height, MapWriter & map);
};


#endif
