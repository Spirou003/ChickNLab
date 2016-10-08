#include "Map.hpp"
#include "MapGenerator.hpp"

MapWriter::MapWriter(){}
MapWriter::~MapWriter(){}

Map::Map():map(00), m_writer(this){}

Map::Map(const Map & map):map(00), m_writer(this)
{
    if (map.map == 00)
        return;
    this->map = new Matrix<bool>(map.map);
}

Map::~Map()
{
    if (map != 00)
        delete(map);
}

bool Map::Create(uint16_t width, uint16_t height, MapCell value)
{
    if (width == 0 || height == 0)
    {
        if (map != 00)
            delete(map);
        return true;
    }
    if (not (map != 00 && map->Line() == width && map->Column() == height))
    {
        Matrix<bool> * nmap = new Matrix<bool>(value, width, height);
        delete(map);
        map = nmap;
    }
    int i = 0, j = 0;
    while (i < width)
    {
        j = 0;
        while (j < height)
        {
            (*map)(i, j) = value;
            j++;
        }
        i++;
    }
    return true;
}

bool Map::Create(const Point2D<uint16_t> & size, MapCell value)
{
    return Create(size.x, size.y, value);
}

uint16_t Map::GetWidth() const
{
    return map->Line();
}

uint16_t Map::GetHeight() const
{
    return map->Column();
}

bool Map::IsWall(uint16_t x, uint16_t y) const
{
    return ((*map)(x, y) == WALL);
}

bool Map::IsEmpty(uint16_t x, uint16_t y) const
{
    return ((*map)(x, y) == EMPTY);
}

void Map::Generate(MapGenerator & generator)
{
    if (map != 00)
    {
        generator.Generate(map->Line(), map->Column(), m_writer);
    }
}

Map::M_Writer::M_Writer(Map * map):map(map){}

Map::M_Writer::~M_Writer(){}

uint16_t Map::M_Writer::GetWidth() const
{
    return map->map->Line();
}

uint16_t Map::M_Writer::GetHeight() const
{
    return map->map->Column();
}

bool Map::M_Writer::IsWall(uint16_t x, uint16_t y) const
{
    return ((*(map->map))(x, y) == WALL);
}

void Map::M_Writer::SetWall(uint16_t x, uint16_t y, bool isWall)
{
    (*(map->map))(x, y) = isWall;
}

bool Map::M_Writer::IsEmpty(uint16_t x, uint16_t y) const
{
    return ((*(map->map))(x, y) == EMPTY);
}

void Map::M_Writer::SetEmpty(uint16_t x, uint16_t y, bool isEmpty)
{
    (*(map->map))(x, y) = !isEmpty;
}

void Map::M_Writer::Clear(MapCell value)
{
    int i = 0, j = 0;
    while (i < int(map->map->Line()))
    {
        j = 0;
        while (j < int(map->map->Column()))
        {
            (*(map->map))(i, j) = value,
            j++;
        }
        i++;
    }
}


