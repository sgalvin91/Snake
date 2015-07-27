
#if !defined(_PLAYER_SNAKE_HPP)
#define _PLAYER_SNAKE_HPP

#include "snake.hpp"

class player_snake : public snake {

    public:

    void create()
        {
            direction_=1;
            sprite.push_front(60,100);
            sprite.push_front(80,100);
            sprite.push_front(100,100);
            sprite.push_front(120,100);
        }

    void change_direction(int z)
    {
        if(z == 1 && direction_ !=2){direction_=1;}
        if(z == 2 && direction_ !=1){direction_=2;};
        if(z == 3 && direction_ !=4){direction_=3;};
        if(z == 4 && direction_ !=3){direction_=4;};


    }
};

#endif  //_PLAYER_SNAKE_HPP
