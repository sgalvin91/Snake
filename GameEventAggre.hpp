#if !defined(_GAMEEVENTAGGRE_HPP)
#define _GAMEEVENTAGGRE_HPP

#include <prg/app_event_loop.hpp>
#include <prg/timer.hpp>
#include <prg/app.hpp>
#include <prg/font.hpp>

#include "PlayerController.hpp"
#include "AIController.hpp"
#include "DemoController.hpp"
#include "visual.hpp"
#include "food.hpp"
#include "file.hpp"

using namespace std;

class GameEventAggre : public IAppEventLoop {
    public:

    GameEventAggre();
    ~GameEventAggre();
    virtual BOOL init();
     virtual BOOL uninit();
        virtual BOOL onEntry();
         virtual BOOL onExit();
        virtual BOOL onUpdate();
        virtual BOOL onRender(Canvas& canvas);
        virtual BOOL onRenderHUD(Canvas& hud);
        virtual BOOL onIdle();
        virtual BOOL onKey(const KeyEvent& key_event);
        virtual BOOL onTimer(Timer&    t1);

        protected:
        Snake S1_;
        Snake S2_;
        Visual display;
        Food fruit;
        File names;

        private:
        Timer t1;
        string name1,name2;
        int keyinput_1, keyinput_2;
        int ticker, food_count;
        bool com_win, play_win;
        bool crash;
        int play_type_1,play_type_2;
        bool turn1, turn2;

};
#endif
