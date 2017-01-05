#include "window_SFGui.hpp"
#include "Datamap.hpp"

using namespace sf;

sfgwin::sfgwin()
{
    horizontalBox = sfg::Box::Create( sfg::Box::Orientation::HORIZONTAL, 5.0f );

    label_mapgen = sfg::Label::Create("Map generation");
    button = sfg::Button::Create("Ready!");
    button->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&sfgwin::OnButtonClick, this));
    box_mapgen = sfg::Box::Create( sfg::Box::Orientation::VERTICAL, 5.0f );
    box_mapgen->Pack(label_mapgen, false);
    box_mapgen->Pack(button);

    box_mapdim = sfg::Box::Create( sfg::Box::Orientation::HORIZONTAL, 5.0f );
    box_mapdimx = sfg::Box::Create( sfg::Box::Orientation::VERTICAL, 5.0f );
    box_mapdimy = sfg::Box::Create( sfg::Box::Orientation::VERTICAL, 5.0f );
    scrollbar_mapdimx = sfg::Scrollbar::Create( sfg::Scrollbar::Orientation::VERTICAL );
    scrollbar_mapdimy = sfg::Scrollbar::Create( sfg::Scrollbar::Orientation::VERTICAL );
    scrollbar_mapdimx->SetRequisition(Vector2f(0.f, 80.f));
    scrollbar_mapdimy->SetRequisition(Vector2f(0.f, 80.f));
    adjustment_mapdimx = scrollbar_mapdimx->GetAdjustment();
    adjustment_mapdimy = scrollbar_mapdimy->GetAdjustment();
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
    label_mapdimx = sfg::Label::Create("x");
    label_mapdimy = sfg::Label::Create("y");
    label_mapdimxv = sfg::Label::Create("10");
    label_mapdimyv = sfg::Label::Create("10");
    adjustment_mapdimx->GetSignal(sfg::Adjustment::OnChange).Connect(std::bind(&sfgwin::SizeXChanged, this));
    adjustment_mapdimy->GetSignal(sfg::Adjustment::OnChange).Connect(std::bind(&sfgwin::SizeYChanged, this));
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
    window = sfg::Window::Create();
    //
    //NO_STYLE  	Transparent window.
    //TITLEBAR  	Titlebar.
    //BACKGROUND	Background.
    //RESIZE    	Resizable.
    //SHADOW    	Display Shadow.
    //CLOSE     	Display close button.
    //TOPLEVEL  	Toplevel window.
    //
    window->SetStyle(sfg::Window::BACKGROUND+sfg::Window::CLOSE+sfg::Window::TITLEBAR);
    window->SetTitle( "Hello world!" );
    window->Add(horizontalBox);
    // Create a desktop and add the window to it.
    //sfg::Desktop desktop;
    desktop.Add(window);
}

void sfgwin::OnButtonClick()
{
    data->map.Create(data->w, data->h);
    data->map.Generate(data->mapgen);
    printmap(data->map);printf("\n");
}

void sfgwin::SizeXChanged()
{
    data->w = int(adjustment_mapdimx->GetValue());
    std::stringstream sstr;
    sstr << data->w;
    label_mapdimxv->SetText(sstr.str());
}

void sfgwin::SizeYChanged()
{
    data->h = int(adjustment_mapdimy->GetValue());
    std::stringstream sstr;
    sstr << data->h;
    label_mapdimyv->SetText(sstr.str());
}


void sfgwin::GetEvent(Event event)
{
    desktop.HandleEvent(event);
}

void sfgwin::Delay(double dt)
{
    desktop.Update(dt);
}

void sfgwin::Draw(RenderWindow & target)
{
    m_sfgui.Display(target);
}
