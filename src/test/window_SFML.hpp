#ifndef CHICKNLAB_TEST_SFWIN_HPP
#define CHICKNLAB_TEST_SFWIN_HPP

#include "gui/MyWindow.hpp"

class Map;
class MapDrawer;

class sfwin: public MyWindow
{
    public:
        sfwin();
        sfwin(sf::VideoMode mode, const sf::String &title, sf::Uint32 style=sf::Style::Default, const sf::ContextSettings &settings=sf::ContextSettings());
        virtual ~sfwin();

        Map * map;
        MapDrawer * mapDrawer;

    protected:
        virtual void Draw();
        virtual void Delay(double dt);
        virtual void GetEvent(const sf::Event & event);
};

#endif // CHICKNLAB_TEST_SFWIN_HPP
