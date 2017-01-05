#include "../ker/Map.hpp"
#include "../ker/MapGenerator/CirclesBased.hpp"

struct Datamap
{
    int w, h;
    Map map;
    MapGeneratorCirclesBased mapgen;
};

void printmap(Map & map);
