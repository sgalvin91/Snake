#if !defined(_DEMO_SNAKE_HPP)
#define _DEMO_SNAKE_HPP

#include "snake.hpp"

class Demo_Snake : public Snake {

    public:

    void change_direction()
    {
        if (direction_ == 1 && sprite.show_x(1) == 840){direction_ = 3;}
        if (direction_ == 3 && sprite.show_y(1) == 860){direction_ = 2;}
        if (direction_ == 2 && sprite.show_x(1) == 60) {direction_ = 4;}
        if (direction_ == 4 && sprite.show_y(1) == 80){direction_ = 1;}

    }

};

#endif  //_DEMO_SNAKE_HPP
