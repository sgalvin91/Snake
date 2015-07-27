#include "GameEventAggre.hpp"

using namespace std;

        GameEventAggre::GameEventAggre():t1(42,100,this)
        {
            App::instance().add_key_observer(*this);
        }

        GameEventAggre::~GameEventAggre()
        {
        }

        BOOL GameEventAggre::init()
        {
            crash=false;
            com_win=false;
            play_win=false;
            name1="Snake 1";
            name2="Snake 2";
            keyinput_1=1;
            keyinput_2=2;
            ticker=149;
            food_count=0;
            return True;
        }

        BOOL GameEventAggre::uninit()
        {
            S1_.~Snake();
            S2_.~Snake();
            return True;
        }

        BOOL GameEventAggre::onEntry()
        {
            cout<<names.get_total();
            if (names.get_total() == 0){play_type_1 = 2;play_type_2=2;}
            if (names.get_total() == 1){play_type_1=1;play_type_2 = 2;}
            if (names.get_total() == 2){play_type_1=1;play_type_2 = 1;}
            S1_.selection(play_type_1, S1_, 1);
            S2_.selection(play_type_2, S2_, 2);
            cout<<names.get_name(1);
            if (play_type_1==1){name1=names.get_name(1);}else{name1="computer";}
            if (play_type_2==1){name2=names.get_name(2);}else{name2="computer";}
            t1.start();
            return True;
        }

       BOOL GameEventAggre::onExit()
        {
            t1.stop();
            return True;
        }

        BOOL  GameEventAggre::onUpdate()
        {
            return True;
        }

        BOOL GameEventAggre::onRender(Canvas& canvas)
        {
            display.display_world(canvas);
             for(int i=0; i<5; i++){display.display_food(fruit.getx(i),fruit.gety(i),fruit.getz(i),canvas);}
             int pic;
                for (unsigned int item=0; item<=S1_.sprite.size(); item++)
                {
                    pic=1;
                    display.display_snakes(S1_.sprite.show_x(item),S1_.sprite.show_y(item),pic,canvas);
                }
                for (unsigned int item=0; item<=S2_.sprite.size(); item++)
                {
                    pic=2;
                    display.display_snakes(S2_.sprite.show_x(item),S2_.sprite.show_y(item),pic,canvas);
                }
                display.draw_eyes(S2_.sprite.show_x(1),S2_.sprite.show_y(1),S2_.direction_,canvas);
                display.draw_eyes(S1_.sprite.show_x(1),S1_.sprite.show_y(1),S1_.direction_,canvas);
            return True;
        }

        BOOL GameEventAggre::onRenderHUD(Canvas& hud)
        {
            char play_total[3];
            char com_total[3];
            sprintf(play_total,"%d",S1_.score_);
            sprintf(com_total,"%d",S2_.score_);
           App::sysfont_huge.print(hud,60,35,App::syscol_blue,name1+" :");
           App::sysfont_huge.print(hud,170,35,App::syscol_blue,play_total);
           App::sysfont_huge.print(hud,700,35,App::syscol_red,name2+" :");
            App::sysfont_huge.print(hud,850,35,App::syscol_red,com_total);
            App::sysfont_medium.print(hud,350,35,App::syscol_black,"Press space to pause game");//instructions on screen to the player

        if (crash == true)
            {
                App::sysfont_massive.print(hud,390,600,App::syscol_green,"GAME OVER");
                    if ((com_win==false && play_win==false) || (com_win==true && play_win==true) ){App::sysfont_massive.print(hud,400,350,App::syscol_white,"DRAW");}
                    else{
                    if (com_win==true){App::sysfont_massive.print(hud,360,350,App::syscol_red,name2+" WINS");}
                    if (play_win==true){App::sysfont_massive.print(hud,370,350,App::syscol_blue,name1+" WINS");}
                    }
            }
            return True;
        }


       BOOL GameEventAggre::onIdle()
        {
            return True;
        }

        BOOL GameEventAggre::onKey(const KeyEvent& key_event)
        {
            if (crash == false)
            {
                if (turn1 == false)
                {
            if(key_event.key == 'w') {keyinput_1=3;};
            if(key_event.key == 'a') {keyinput_1=2;};
            if(key_event.key == 's') {keyinput_1=4;};
            if(key_event.key == 'd') {keyinput_1=1;};
            turn1=true;
                }

                if (turn2 == false)
                {
            if(key_event.key == 'u') {keyinput_2=3;};
            if(key_event.key == 'h') {keyinput_2=2;};
            if(key_event.key == 'j') {keyinput_2=4;};
            if(key_event.key == 'k') {keyinput_2=1;};
            turn2=true;
                }
            if(key_event.key == 32) {App::instance().set_event_loop("demo");}
            }
            if(key_event.key_state == key_event.KB_DOWN && key_event.key == key_event.KB_ESC_KEY) {t1.stop();App::instance().exit();};
            return True;
        }

        BOOL GameEventAggre::onTimer(Timer&    t1)
        {

            if (crash == false)
            {
                turn1 = false;
                turn2 =false;
                int selection=fruit.find_food();
                S1_.movement(fruit.getx(selection),fruit.gety(selection),keyinput_1);
                S2_.movement(fruit.getx(selection),fruit.gety(selection),keyinput_2);
                S2_.move();
                S1_.move();
                for (int i=0; i<5; i++)
                {
                if (S1_.chew(fruit.getx(i),fruit.gety(i),fruit.getz(i)) || S2_.chew(fruit.getx(i),fruit.gety(i),fruit.getz(i)))
                {
                    do{
                        fruit.spawn_food(i);
                        }
                        while(S1_.food_merge(fruit.getx(i),fruit.gety(i)) || S2_.food_merge(fruit.getx(i),fruit.gety(i)));
                        };
                }
                if (S2_.crashed_){play_win=true;}
                if (S1_.crashed_){com_win=true;}

                ticker++;
                if (ticker == 150 && food_count < 6)
                {
                    fruit.spawn_food(food_count);
                    ticker=0;
                    food_count++;
                }
            }


                if (!play_win){play_win=S1_.enemy_collision(S2_.sprite.show_x(1),S2_.sprite.show_y(1));}
                if (!com_win) {com_win=S2_.enemy_collision(S1_.sprite.show_x(1), S1_.sprite.show_y(1));}
                if (play_win || com_win)
                {
                S1_.direction_=0;
                S2_.direction_=0;
                crash=true;
                names.load_scores();
                    for(int i=0; i<10;i++)
                    {
                        if ((S1_.score_ > names.get_points(i) && play_type_1) || (S2_.score_ > names.get_points(i) && play_type_2))
                        {
                            for(int j=8; j>i;j--)
                            {
                                names.set_person(j+1,names.get_person(j));
                                names.set_points(j+1,names.get_points(j));
                            }
                            if (S1_.score_ > names.get_points(i))
                            {
                                names.set_person(i,name1);
                                names.set_points(i,S1_.score_);
                            }
                            if (S2_.score_ > names.get_points(i))
                            {
                                names.set_person(i, name2);
                                names.set_points(i,S2_.score_);
                            }
                        }
                    }
                names.store_scores();
                }

            return True;
        }


