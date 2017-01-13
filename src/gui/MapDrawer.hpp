#ifndef CHICKNLAB_GUI_MAPDRAWER_HPP
#define CHICKNLAB_GUI_MAPDRAWER_HPP

#include "../ker/Map.hpp"

namespace sf
{
    class RenderStates;
    class RenderTarget;
}

class MapDrawer
{
    public:
        MapDrawer();
        virtual ~MapDrawer();

        virtual void Draw(sf::RenderTarget & target, sf::RenderStates states, const Map & map);
};



#endif
