#include "MyWindow.hpp"

#include <SFML/System.hpp>

using namespace sf;

MyWindow::MyWindow():
time(0), realTime(0), K(1), mutex(00), event()
{
    mutex = new Mutex();
    setFramerateLimit(60);
    //create(VideoMode(640, 480), "Window", Style::Default);
}

MyWindow::MyWindow(VideoMode mode, const String &title, Uint32 style, const ContextSettings &settings):
RenderWindow(mode, title, style, settings),
time(0), realTime(0), K(1), mutex(00), event()
{
    mutex = new Mutex();
    setFramerateLimit(60);
    //create(VideoMode(640, 480), "Window", Style::Default);
}

MyWindow::~MyWindow()
{
    if (mutex != 00)
    {
        delete(mutex);
    }
}

double MyWindow::GetTime() const
{
    return time;
}
double MyWindow::GetRealTime() const
{
    return realTime;
}

double MyWindow::GetTimeAcceleration() const
{
    return K;
}

void MyWindow::SetTimeAcceleration(double K)
{
    if (K > 0)
    {
        this->K = K;
    }
}

void MyWindow::Run()
{
    setActive(false);
    {
        Thread thread (&MyWindow::Drawing, this);
        thread.launch();
        while (isOpen())
        {
            if (waitEvent(event))
            {
                mutex->lock();
                GetEvent(event);
                mutex->unlock();
            }
        }
        thread.wait();
    }
}

void MyWindow::Drawing()
{
    Clock clock;
    double dt;
    while (isOpen())
    {
        mutex->lock();
        dt = clock.restart().asSeconds();
        time += dt*K;
        realTime += dt;
        Delay(dt);
        Draw();
        mutex->unlock();
        display();
    }
}
