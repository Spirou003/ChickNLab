#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFML/Graphics.hpp>

#include <ctime>
#include <cstdio>
#include "../ker/Map.hpp"
#include "../ker/MapGenerator/CirclesBased.hpp"
#include "../ker/NumberGenerator/Random.hpp"

using namespace sf;

struct labymap
{
    int w, h;
    Map map;
    MapGeneratorCirclesBased mapgen;
};

void printmap(Map & map)
{
    int i = 0, j = 0, w = map.GetWidth(), h = map.GetHeight();
    while (i < w)
    {
        j = 0;
        while (j < h)
        {
            if (map.IsWall(i, j))
            {
                printf("%c", 219);
            }
            else
            {
                printf(" ");
            }
            j++;
        }
        printf("\n");
        i++;
    }
}

void OnButtonClick(labymap * data)
{printf("%d %d\n", data->w, data->h);
    data->map.Create(data->w, data->h);
    data->map.Generate(data->mapgen);
    printmap(data->map);printf("\n");
}

void SizeXChanged(labymap * data, sfg::Adjustment::Ptr adj, sfg::Label::Ptr label)
{
    data->w = int(adj->GetValue());
    std::stringstream sstr;
    sstr << adj->GetValue();
    label->SetText(sstr.str());
}

void SizeYChanged(labymap * data, sfg::Adjustment::Ptr adj, sfg::Label::Ptr label)
{
    data->h = int(adj->GetValue());
    std::stringstream sstr;
    sstr << data->h;
    label->SetText(sstr.str());
}

class HelloWorld
{
    public:
        void Run();
    private:
        sfg::SFGUI m_sfgui;
};

void HelloWorld::Run()
{
    labymap data;
    data.w = 10;
    data.h = 10;
    data.mapgen.p = 30;
    data.mapgen.q = 100;
    data.mapgen.symetric = false;
    Random rng;
    rng.SetSeed(time(NULL));
    data.mapgen.rng = &rng;
    // Create SFML's window.
    RenderWindow render_window(VideoMode(800, 600), "Hello world!" );
    sfg::Box::Ptr horizontalBox = sfg::Box::Create( sfg::Box::Orientation::HORIZONTAL, 5.0f );

    sfg::Label::Ptr label_mapgen = sfg::Label::Create("Map generation");
    std::shared_ptr<sfg::Button> button = sfg::Button::Create("Ready!");
    button->GetSignal( sfg::Widget::OnLeftClick ).Connect( std::bind(OnButtonClick, &data) );
    std::shared_ptr<sfg::Box> box_mapgen = sfg::Box::Create( sfg::Box::Orientation::VERTICAL, 5.0f );
    box_mapgen->Pack(label_mapgen, false);
    box_mapgen->Pack(button);

    sfg::Box::Ptr box_mapdim = sfg::Box::Create( sfg::Box::Orientation::HORIZONTAL, 5.0f );
    sfg::Box::Ptr box_mapdimx = sfg::Box::Create( sfg::Box::Orientation::VERTICAL, 5.0f );
    sfg::Box::Ptr box_mapdimy = sfg::Box::Create( sfg::Box::Orientation::VERTICAL, 5.0f );
    sfg::Scrollbar::Ptr scrollbar_mapdimx = sfg::Scrollbar::Create( sfg::Scrollbar::Orientation::VERTICAL );
    sfg::Scrollbar::Ptr scrollbar_mapdimy = sfg::Scrollbar::Create( sfg::Scrollbar::Orientation::VERTICAL );
    scrollbar_mapdimx->SetRequisition(Vector2f(0.f, 80.f));
    scrollbar_mapdimy->SetRequisition(Vector2f(0.f, 80.f));
    sfg::Adjustment::Ptr adjustment_mapdimx = scrollbar_mapdimx->GetAdjustment();
    sfg::Adjustment::Ptr adjustment_mapdimy = scrollbar_mapdimy->GetAdjustment();
    adjustment_mapdimx->SetLower(1.f);
    adjustment_mapdimy->SetLower(1.f);
    adjustment_mapdimx->SetUpper(40.f);
    adjustment_mapdimy->SetUpper(40.f);
    adjustment_mapdimx->SetMinorStep(1.f);
    adjustment_mapdimy->SetMinorStep(1.f);
    adjustment_mapdimx->SetMajorStep(1.f);
    adjustment_mapdimy->SetMajorStep(1.f);
    adjustment_mapdimx->SetPageSize(10.f);
    adjustment_mapdimy->SetPageSize(10.f);
    adjustment_mapdimx->SetValue(10.f);
    adjustment_mapdimy->SetValue(10.f);
    sfg::Label::Ptr label_mapdimx = sfg::Label::Create("x");
    sfg::Label::Ptr label_mapdimy = sfg::Label::Create("y");
    sfg::Label::Ptr label_mapdimxv = sfg::Label::Create("10");
    sfg::Label::Ptr label_mapdimyv = sfg::Label::Create("10");
    adjustment_mapdimx->GetSignal(sfg::Adjustment::OnChange).Connect(std::bind(SizeXChanged, &data, adjustment_mapdimx, label_mapdimxv));
    adjustment_mapdimy->GetSignal(sfg::Adjustment::OnChange).Connect(std::bind(SizeYChanged, &data, adjustment_mapdimy, label_mapdimyv));
    box_mapdim->Pack(box_mapdimx);
    box_mapdim->Pack(box_mapdimy);
    box_mapdimx->Pack(label_mapdimx);
    box_mapdimx->Pack(scrollbar_mapdimx);
    box_mapdimx->Pack(label_mapdimxv, false);
    box_mapdimy->Pack(label_mapdimy);
    box_mapdimy->Pack(scrollbar_mapdimy);
    box_mapdimy->Pack(label_mapdimyv, false);

    horizontalBox->Pack(box_mapgen);
    horizontalBox->Pack(box_mapdim);
    // Create a window and add the box layouter to it. Also set the window's title.
    std::shared_ptr<sfg::Window> window = sfg::Window::Create();
    /*
    NO_STYLE 	Transparent window.
    TITLEBAR 	Titlebar.
    BACKGROUND 	Background.
    RESIZE  	Resizable.
    SHADOW  	Display Shadow.
    CLOSE   	Display close button.
    TOPLEVEL 	Toplevel window.
    */
    window->SetStyle(sfg::Window::BACKGROUND+sfg::Window::CLOSE+sfg::Window::TITLEBAR);
    window->SetTitle( "Hello world!" );
    window->Add(horizontalBox);
    // Create a desktop and add the window to it.
    sfg::Desktop desktop;
    desktop.Add(window);
    // We're not using SFML to render anything in this program, so reset OpenGL
    // states. Otherwise we wouldn't see anything.
    render_window.resetGLStates();
    // Main loop!
    Event event;
    Clock clock;
    while( render_window.isOpen() )
    {
        // Event processing.
        while( render_window.pollEvent( event ) )
        {
            desktop.HandleEvent( event );
            // If window is about to be closed, leave program.
            if( event.type == Event::Closed )
            {
                render_window.close();
            }
        }
        // Update SFGUI with elapsed seconds since last call.
        desktop.Update( clock.restart().asSeconds() );
        // Rendering.
        render_window.clear();
        m_sfgui.Display( render_window );
        render_window.display();
    }
}

int main()
{
    HelloWorld hello_world;
    hello_world.Run();
    return 0;
}

