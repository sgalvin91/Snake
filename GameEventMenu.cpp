#include "GameEventMenu.hpp"

using namespace std;
using namespace prg;

        GameEventMenu::GameEventMenu()
        {
            App::instance().add_key_observer(*this);
        }

        GameEventMenu::~GameEventMenu()
        {
        }

        BOOL GameEventMenu::init()
        {
            return True;
        }

        BOOL GameEventMenu::uninit()
        {
            return True;
        }

        BOOL GameEventMenu::onEntry()
        {
            play_name="";
            com_name="";
            letter=false;
            blitz=true;
            information.load_scores();
            return True;
        }

       BOOL GameEventMenu::onExit()
        {
            return True;
        }

        BOOL  GameEventMenu::onUpdate()
        {
            return True;
        }

        BOOL GameEventMenu::onRender(Canvas& canvas)
        {
            return True;
        }

        BOOL GameEventMenu::onRenderHUD(Canvas& hud)
        {
            App::sysfont_huge.print(hud,300,700,App::syscol_black,"Hi-Scores");
            for( int i=0; i<10; i++)
            {
            App::sysfont_huge.print(hud,100,650-(i*25),App::syscol_black,information.get_person(i));
            sprintf(hold,"%d",information.get_points(i));
            App::sysfont_huge.print(hud,600,650-(i*25),App::syscol_black,hold);
            }
           App::sysfont_huge.print(hud,60,200,App::syscol_blue,"Player Name:");
          App::sysfont_huge.print(hud,60,150,App::syscol_blue,play_name);
           App::sysfont_huge.print(hud,700,200,App::syscol_red,"Computer :");
            App::sysfont_huge.print(hud,700,150,App::syscol_red,com_name);
            sprintf(hold,"%d",information.get_total());
            App::sysfont_huge.print(hud,300,200,App::syscol_black,"Human Players");
            App::sysfont_huge.print(hud,350,150,App::syscol_black,hold);
            App::sysfont_medium.print(hud,275,100,App::syscol_black,"press enter to start the game");//instructions to the player
            App::sysfont_medium.print(hud,50,50,App::syscol_black,"left click to increase number of human players");//instructions to the player
            App::sysfont_medium.print(hud,500,50,App::syscol_black,"right click to decrease number of human players");//instructions to the player
            return True;
        }

        BOOL GameEventMenu::onIdle()
        {
        return True;
        }

        BOOL GameEventMenu::onKey(const KeyEvent& key_event)
        {
            if (key_event.key_state == key_event.KB_DOWN)
            {
                if (!letter)
                {
                    if (blitz)
                    {
                    if (key_event.key == 8 || key_event.key == 127)

                    {play_name= "";}
                    else{play_name+=key_event.key;}
                    letter=true;
                }
                else{
                    if (key_event.key == 8 || key_event.key == 127)

                    {com_name= "";}
                    else{com_name+=key_event.key;}
                    letter=true;
                }

                if (key_event.key == 13){information.save_name(play_name,com_name);}
                }
            }
            else{letter=false;}
            return True;
        }

        BOOL GameEventMenu::onButton(const MouseEvent& mouse_event)
        {
            if (mouse_event.button_state == mouse_event.MB_DOWN)
            {
                if(!number)
                {
                    if (mouse_event.button == mouse_event.LM_BTN)
                    {
                        blitz=true;
                        information.set_total(blitz);
                        number=true;
                    }
                    if (mouse_event.button == mouse_event.RM_BTN)
                    {
                        blitz=false;
                        information.set_total(blitz);
                        number=true;
                    }
                }
            }
            else{number=false;}
            return True;
        }
