#ifndef CHICKNLAB_KER_MAP_HPP
#define CHICKNLAB_KER_MAP_HPP

#include <cstdint>
#include "Matrix.hpp"
#include "Point2D.hpp"

class MapGenerator;

enum MapCell
{
    EMPTY = false,
    WALL = true
};

class MapWriter
{
    public:
        MapWriter();
        virtual ~MapWriter();
        virtual uint16_t GetWidth() const = 0;
        virtual uint16_t GetHeight() const = 0;

        virtual bool IsWall(uint16_t x, uint16_t y) const = 0;
        virtual void SetWall(uint16_t x, uint16_t y, bool isWall = true) = 0;
        virtual bool IsEmpty(uint16_t x, uint16_t y) const = 0;
        virtual void SetEmpty(uint16_t x, uint16_t y, bool isEmpty = true) = 0;
        virtual void Clear(MapCell value) = 0;
};

class Map
{
    public:
        Map();
        Map(const Map & map);
        ~Map();

        bool Create(uint16_t width, uint16_t height, MapCell value = WALL);
        bool Create(const Point2D<uint16_t> & size, MapCell value = WALL);

        uint16_t GetWidth() const;
        uint16_t GetHeight() const;

        bool IsWall(uint16_t x, uint16_t y) const;
        bool IsEmpty(uint16_t x, uint16_t y) const;

        void Generate(MapGenerator & generator);

    private:
        Matrix<bool> * map;

        class M_Writer: public MapWriter
        {
            public:
                M_Writer(Map * map);
                virtual ~M_Writer();
                virtual uint16_t GetWidth() const;
                virtual uint16_t GetHeight() const;

                virtual bool IsWall(uint16_t x, uint16_t y) const;
                virtual void SetWall(uint16_t x, uint16_t y, bool isWall = true);
                virtual bool IsEmpty(uint16_t x, uint16_t y) const;
                virtual void SetEmpty(uint16_t x, uint16_t y, bool isEmpty = true);
                virtual void Clear(MapCell value);

            private:
                Map * map;
        };

        M_Writer m_writer;
};


#endif
