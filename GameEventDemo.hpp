#if !defined(_GAMEEVENTDEMO_HPP)
#define _GAMEEVENTDEMO_HPP

#include <prg/app_event_loop.hpp>
#include <prg/timer.hpp>
#include <prg/app.hpp>
#include <prg/font.hpp>


#include "PlayerController.hpp"
#include "AIController.hpp"
#include "DemoController.hpp"
#include "visual.hpp"

using namespace std;

class GameEventDemo : public IAppEventLoop {
    public:

    GameEventDemo();
    ~GameEventDemo();
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
        Snake demo_1;
        Snake demo_2;
        Visual display;

        private:
        Timer t1;
        int textpos;
};

#endif
