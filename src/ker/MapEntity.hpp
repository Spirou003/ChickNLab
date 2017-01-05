#ifndef CHICKNLAB_KER_MAPENTITY_HPP
#define CHICKNLAB_KER_MAPENTITY_HPP

#include <cstdint>
#include "Point2D.hpp"

class Map;

enum Direction
{
    None = 0,
    Up = 1,
    Right = 2,
    Down = 3,
    Left = 4,
};

class MapEntity
{
    public:
        MapEntity(double x = 0, double y = 0);
        MapEntity(const Point2D<double> & position);
        virtual ~MapEntity();

        virtual uint16_t GetMapX() const;
        virtual uint16_t GetMapY() const;
        virtual Point2D<uint16_t> GetMapPosition() const;
        virtual double GetX() const;
        virtual double GetY() const;
        virtual Point2D<double> GetPosition() const;
        virtual double GetSpeed() const = 0;
        virtual Direction GetDirection() const = 0;

        static Point2D<double> VectorSpeed(double speed, Direction direction);

    protected:
        void SetX(double x);
        void SetY(double y);

    private:
        double x, y;
        uint16_t map_x, map_y;
};


#endif
