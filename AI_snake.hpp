
#if !defined(_AI_SNAKE_HPP)
#define _AI_SNAKE_HPP

#include "snake.hpp"

class AI_snake : public snake {

    public:

    void change_direction(int x,int y)
    {
        if (x > sprite.show_x(1)&& direction_ != 2)
        {
            direction_=1;
            }
            else{
                        if (x < sprite.show_x(1) && direction_ !=1)
                    {
                        direction_=2;
                    }
                    else {
                        if (y > sprite.show_y(1) && direction_ !=4)
                        {
                        direction_=3;
                        }
                            else{
                                    if (y < sprite.show_y(1) && direction_ !=3)
                                    {
                                    direction_=4;
                                    }
                                }
                        }
                }
    }

};

#endif  //_AI_SNAKE_HPP
