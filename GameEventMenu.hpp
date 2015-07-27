#if !defined(_GAMEEVENTMENU_HPP)
#define _GAMEEVENTMENU_HPP

#include <prg/app_event_loop.hpp>
#include <prg/app.hpp>
#include <prg/font.hpp>
#include <iostream>
#include <string>
#include "file.hpp"

using namespace std;
using namespace prg;

class GameEventMenu : public IAppEventLoop {
    public:

    GameEventMenu();
    ~GameEventMenu();
    virtual BOOL init();
     virtual BOOL uninit();
        virtual BOOL onEntry();
         virtual BOOL onExit();
        virtual BOOL onUpdate();
        virtual BOOL onRender(Canvas& canvas);
        virtual BOOL onRenderHUD(Canvas& hud);
        virtual BOOL onIdle();
        virtual BOOL onKey(const KeyEvent& key_event);
       virtual BOOL onButton(const  MouseEvent& mouse_event);

        private:
        string com_name;
        string play_name;
        char hold[3];
        File information;
        bool letter,number;
        bool blitz;
};

#endif
