#include "MapEntity.hpp"

#include <cmath>

MapEntity::MapEntity(double x, double y)
:x(0), y(0), map_x(0), map_y(0)
{
    SetX(x);SetY(y);
}

MapEntity::MapEntity(const Point2D<double> & position)
:x(0), y(0), map_x(0), map_y(0)
{
    SetX(position.x);SetY(position.y);
}

MapEntity::~MapEntity(){}

uint16_t MapEntity::GetMapX() const
{
    return map_y;
}

uint16_t MapEntity::GetMapY() const
{
    return map_x;
}

Point2D<uint16_t> MapEntity::GetMapPosition() const
{
    return Point2D<uint16_t>(map_x, map_y);
}

double MapEntity::GetX() const
{
    return y;
}

double MapEntity::GetY() const
{
    return x;
}

Point2D<double> MapEntity::GetPosition() const
{
    return Point2D<double>(x, y);
}

void MapEntity::SetX(double x)
{
    if (x-floor(x) < x-ceil(x))
    {
        map_x = int(floor(x));
    }
    else
    {
        map_x = int(ceil(x));
    }
    this->x = x;
}

void MapEntity::SetY(double y)
{
    if (y-floor(y) < x-ceil(y))
    {
        map_y = int(floor(y));
    }
    else
    {
        map_y = int(ceil(y));
    }
    this->y = y;
}

Point2D<double> MapEntity::VectorSpeed(double speed, Direction direction)
{
    switch(direction)
    {
        case None:
            return Point2D<double>(0, 0);
        case Up:
            return Point2D<double>(0, speed);
        case Right:
            return Point2D<double>(speed, 0);
        case Down:
            return Point2D<double>(0, -speed);
        case Left:
            return Point2D<double>(-speed, 0);
        default:
            return Point2D<double>(0, 0);
    }
}
