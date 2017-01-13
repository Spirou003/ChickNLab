#include "window_SFML.hpp"
#include "ker/Map.hpp"
#include "gui/MapDrawer.hpp"

using namespace sf;

sfwin::sfwin(){}
sfwin::sfwin(sf::VideoMode mode, const sf::String &title, sf::Uint32 style, const sf::ContextSettings &settings):
MyWindow(mode, title, style, settings)
{}

sfwin::~sfwin(){}

void sfwin::Draw()
{
    clear(Color(32,32,32));
    mapDrawer->Draw(*this, RenderStates::Default, *map);
}

void sfwin::Delay(double dt)
{
    ;
}

void sfwin::GetEvent(const sf::Event & event)
{
    if (event.type == Event::Closed)
        close();
    else if (event.type == Event::TextEntered)
    {
        if (event.text.unicode == '+')
        {
            View view = getView();
            view.zoom(1/1.1);
            setView(view);
        }
        else if (event.text.unicode == '-')
        {
            View view = getView();
            view.zoom(1.1);
            setView(view);
        }
    }
}


