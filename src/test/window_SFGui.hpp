#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFML/Graphics.hpp>

struct Datamap;

class sfgwin
{
    public:
        sfgwin();

        Datamap * data;

        void GetEvent(sf::Event event);
        void Delay(double dt);
        void Draw(sf::RenderWindow & target);

    private:
        void SizeXChanged();
        void SizeYChanged();
        void OnButtonClick();

        sfg::SFGUI m_sfgui;
        sfg::Desktop desktop;

        sfg::Window::Ptr window;
        sfg::Box::Ptr horizontalBox, box_mapdim, box_mapdimx, box_mapdimy, box_mapgen;
        sfg::Button::Ptr button;
        sfg::Scrollbar::Ptr scrollbar_mapdimx, scrollbar_mapdimy;
        sfg::Adjustment::Ptr adjustment_mapdimx, adjustment_mapdimy;
        sfg::Label::Ptr label_mapdimx, label_mapdimy, label_mapdimxv, label_mapdimyv, label_mapgen;
};

