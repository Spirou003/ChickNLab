#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include "Range.hpp"

#include "Tiled.hpp"

using namespace sf;

MapDrawerTiled::MapDrawerTiled():
m_texture(00), m_vertices(), m_width(0), m_height(0)
{m_vertices.setPrimitiveType(PrimitiveType::Triangles);}
MapDrawerTiled::~MapDrawerTiled(){}

void MapDrawerTiled::Draw(sf::RenderTarget & target, sf::RenderStates states, const Map & map)
{
    int32_t width = map.GetWidth(), height = map.GetHeight();
    ResizeIfNeeded(width, height);
    for (int32_t i : range(width))
        for (int32_t j : range(height))
            SetVerticesFor(i, j, map.IsWall(i, j));
    target.draw(m_vertices, states);
}

void MapDrawerTiled::ResizeIfNeeded(int32_t width, int32_t height)
{
    if (width*height != m_width*m_height)
    {
        m_vertices.resize(width*height*6);
    }
    if (width != m_width || height != m_height)
    {
        for (int32_t i : range(width))
            for (int32_t j : range(height))
            {
                int32_t index = 6*(i*height + j);
                m_vertices[index  ].position = Vector2f(i, j);
                m_vertices[index+1].position = Vector2f(i+1, j);
                m_vertices[index+2].position = Vector2f(i+1, j+1);
                m_vertices[index+3].position = Vector2f(i+1, j+1);
                m_vertices[index+4].position = Vector2f(i, j+1);
                m_vertices[index+5].position = Vector2f(i, j);
            }
        m_width = width;
        m_height = height;
    }
}

void MapDrawerTiled::SetVerticesFor(int32_t x, int32_t y, bool isWall)
{
    if (x < 0 || x >= m_width || y < 0 || y >= m_height)
        return;
    int32_t index = 6*(x*m_height + y);
    Color color = (isWall ? Color(200, 200, 200) : Color(0, 0, 0));
    m_vertices[index  ].color = color;
    m_vertices[index+1].color = color;
    m_vertices[index+2].color = color;
    m_vertices[index+3].color = color;
    m_vertices[index+4].color = color;
    m_vertices[index+5].color = color;
}
