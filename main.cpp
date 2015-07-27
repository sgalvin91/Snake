#include <prg/app.hpp>
#include "GameEventAggre.hpp"
#include "GameEventDemo.hpp"
#include "GameEventMenu.hpp"

using namespace prg;
using namespace std;



int main()
{

    GameEventAggre game_loop;
    GameEventDemo  demo_loop;
    GameEventMenu  menu_loop;

    App::instance().set_clear_colour(Colour(255,255,255,255));
    App::instance().add_event_loop("menu",menu_loop);
    App::instance().add_event_loop("demo",demo_loop);
    App::instance().add_event_loop("game",game_loop).run(900,900,30,"Snake","Simon");

    return 0;
}
