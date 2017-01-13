#ifndef CHICKNLAB_GUI_MYWINDOW_HPP
#define CHICKNLAB_GUI_MYWINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace sf
{
    class Mutex;
}

class MyWindow: public sf::RenderWindow
{
    public:
        MyWindow();
        MyWindow(sf::VideoMode mode, const sf::String &title, sf::Uint32 style=sf::Style::Default, const sf::ContextSettings &settings=sf::ContextSettings());
        virtual ~MyWindow();

        double GetTime() const;
        double GetRealTime() const;
        double GetTimeAcceleration() const;
        void SetTimeAcceleration(double K);

        void Run();

    protected:
        virtual void Draw() = 0;
        virtual void Delay(double dt) = 0;
        virtual void GetEvent(const sf::Event & event) = 0;

    private:
        void Drawing();

        double time, realTime, K;
        sf::Mutex * mutex;
        sf::Event event;
};

#endif
