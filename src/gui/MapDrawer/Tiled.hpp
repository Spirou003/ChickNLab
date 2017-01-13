#ifndef CHICKNLAB_GUI_MAPDRAWERTILED_HPP
#define CHICKNLAB_GUI_MAPDRAWERTILED_HPP

#include <cstdint>
#include <SFML/Graphics/VertexArray.hpp>

#include "../MapDrawer.hpp"

class MapDrawerTiled: public MapDrawer
{
    public:
        MapDrawerTiled();
        virtual ~MapDrawerTiled();

        virtual void Draw(sf::RenderTarget & target, sf::RenderStates states, const Map & map);

    private:
        sf::Texture * m_texture;
        sf::VertexArray m_vertices;
        int32_t m_width, m_height;

        void ResizeIfNeeded(int32_t width, int32_t height);
        void SetVerticesFor(int32_t x, int32_t y, bool isWall);
};



#endif
