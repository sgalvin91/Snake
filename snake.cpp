#include "snake.hpp"
#include <iostream>

#include "Controller.hpp"
#include "PlayerController.hpp"
#include "AIController.hpp"
#include "DemoController.hpp"

using namespace std;

Snake::Snake(): score_(0)
{

}

Snake::~Snake()
{

}

void Snake::selection(int snake_type, Snake item, int num)
{
    create(num);
     if (snake_type==1)
     {
         PlayerController* Pthing=new PlayerController();
         control=Pthing;
         control->Initialise(this);
    }else if(snake_type == 2)
    {
        AIController* Pthing=new AIController();
        control=Pthing;
        control->Initialise(this);
     }else if(snake_type == 3)
     {
         DemoController* Pthing=new DemoController();
         control=Pthing;
         control->Initialise(this);
     }
}

void Snake::create(int i)
{
    if (i == 1)
    {
        direction_=1;
        sprite.push_front(60,80);
        sprite.push_front(80,80);
        sprite.push_front(100,80);
        sprite.push_front(120,80);
    }
    else
    {
        direction_=2;
        sprite.push_front(840,860);
        sprite.push_front(820,860);
        sprite.push_front(800,860);
        sprite.push_front(780,860);
    }
}

void Snake::move()
{
    if (control->change_direction(sfx,sfy,ski) == 1){sprite.push_front(sprite.show_x(1)+20,sprite.show_y(1));sprite.pop_back();}
    if (control->change_direction(sfx,sfy,ski) == 2){sprite.push_front(sprite.show_x(1)-20,sprite.show_y(1));sprite.pop_back();}
    if (control->change_direction(sfx,sfy,ski) == 3){sprite.push_front(sprite.show_x(1),sprite.show_y(1)+20);sprite.pop_back();}
    if (control->change_direction(sfx,sfy,ski) == 4){sprite.push_front(sprite.show_x(1),sprite.show_y(1)-20);sprite.pop_back();}
    if (control->change_direction(sfx,sfy,ski) != 0)  {crashed_ = wall_collision();}
    if (crashed_ == false){crashed_ = self_collision();};
}

void Snake::grow()
{
    sprite.push_back(sprite.show_x(sprite.size()),sprite.show_y(sprite.size()));
}

bool Snake::chew(int x,int y,int z)
{
    if (x == sprite.show_x(1) && y == sprite.show_y(1))
    {
        for (int f=0; f<z; f++)
        {
        grow();
        score_++;
        }
        return true;
    }

    return false;
}

bool Snake::wall_collision()
{
    if (sprite.show_x(1) < 60)
    {
        return true;
    }
    if (sprite.show_x(1) > 840)
    {
        return true;
    }
    if (sprite.show_y(1) < 80)
    {
        return true;
    }
    if (sprite.show_y(1) > 860)
    {
        return true;
    }
    return false;
}

bool Snake::food_merge(int x, int y)
{
    for (unsigned int i=0; i<sprite.size(); i++)
                {
                    if(x==sprite.show_x(i) && y==sprite.show_y(i))
                    {
                        return true;
                    }

                }
    return false;
}

bool Snake::self_collision()
{
    for(unsigned int i=2; i<=sprite.size(); i++)
    {
        if (sprite.show_x(1) == sprite.show_x(i) && sprite.show_y(1) == sprite.show_y(i))
        {
            return true;
        }
    }
    return false;

}

bool Snake::enemy_collision(int x,int y)
{
    for(unsigned int i=0; i<=sprite.size(); i++)
    {
        if (x == sprite.show_x(i) && y == sprite.show_y(i))
        {
            return true;
        }
    }
    return false;

}

void Snake::movement(int x,int y, int z)
{
    sfx=x;
    sfy=y;
    ski=z;
}
