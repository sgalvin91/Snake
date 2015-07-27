#if !defined(_DEMOCONTROLLER_HPP)
#define _DEMOCONTROLLER_HPP

#include "Controller.hpp"

class DemoController : public Controller {
    public:

    int change_direction(int x,int y,int z)
    {
        if (_thesnake->direction_ == 1 && _thesnake->sprite.show_x(1) == 840){_thesnake->direction_ = 3;}
        if (_thesnake->direction_ == 3 && _thesnake->sprite.show_y(1) == 860){_thesnake->direction_ = 2;}
        if (_thesnake->direction_ == 2 && _thesnake->sprite.show_x(1) == 60) {_thesnake->direction_ = 4;}
        if (_thesnake->direction_ == 4 && _thesnake->sprite.show_y(1) == 80) {_thesnake->direction_ = 1;}

        return _thesnake->direction_;

    }
};
#endif
