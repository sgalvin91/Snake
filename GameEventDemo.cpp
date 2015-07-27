#include "GameEventDemo.hpp"

using namespace std;

        GameEventDemo::GameEventDemo():t1(42,100,this)
        {
            App::instance().add_key_observer(*this);
        }

        GameEventDemo::~GameEventDemo()
        {
        }

        BOOL GameEventDemo::init()
        {
            return True;
        }

        BOOL GameEventDemo::uninit()
        {
            demo_1.~Snake();
            demo_2.~Snake();
            return True;
        }

        BOOL GameEventDemo::onEntry()
        {
            demo_1.selection(3, demo_1, 1);
            demo_2.selection(3, demo_2, 2);
            t1.start();
            return True;
        }

       BOOL GameEventDemo::onExit()
        {
            t1.stop();
            return True;
        }

        BOOL  GameEventDemo::onUpdate()
        {
            return True;
        }

        BOOL GameEventDemo::onRender(Canvas& canvas)
        {
             display.display_world(canvas);
             int pic;
                 for (unsigned int item=0; item<=demo_1.sprite.size(); item++)
                {
                    pic=3;
                    display.display_snakes(demo_1.sprite.show_x(item),demo_1.sprite.show_y(item),pic,canvas);
                }
                for (unsigned int item=0; item<=demo_2.sprite.size(); item++)
                {
                    pic=4;
                    display.display_snakes(demo_2.sprite.show_x(item),demo_2.sprite.show_y(item),pic,canvas);
                }
                display.draw_eyes(demo_1.sprite.show_x(1),demo_1.sprite.show_y(1),demo_1.direction_,canvas);
                display.draw_eyes(demo_2.sprite.show_x(1),demo_2.sprite.show_y(1),demo_2.direction_,canvas);
            return True;
        }

        BOOL GameEventDemo::onRenderHUD(Canvas& hud)
        {
          App::sysfont_huge.print(hud,250,35,App::syscol_green,"Press enter to resume game");//instructions to the player
           App::sysfont_massive.print(hud,400,500,App::syscol_green,"Demo Mode");
            return True;
        }


       BOOL GameEventDemo::onIdle()
        {
            return True;
        }

        BOOL GameEventDemo::onKey(const KeyEvent& key_event)
        {
            if(key_event.key == 13) {App::instance().set_event_loop("game");}
            if(key_event.key_state == key_event.KB_DOWN && key_event.key == key_event.KB_ESC_KEY) {t1.stop();App::instance().exit();};
            return True;
        }

        BOOL GameEventDemo::onTimer(Timer&    t1)
        {

                demo_1.movement(0,0,0);
                demo_2.movement(0,0,0);
                demo_1.move();
                demo_2.move();
            return True;
        }
