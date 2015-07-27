
#if !defined(_SNAKE_HPP)
#define _SNAKE_HPP

#include "list.hpp"

class Controller;

class Snake {

    public:

    Snake();
    ~Snake();
    void selection(int snake_type, Snake item, int num);
    void move();
    void create(int i);
    bool wall_collision();
    bool self_collision();
    bool enemy_collision(int x,int y);
    void grow();
    bool chew(int x,int y,int z);
    bool food_merge(int x, int y);
    void movement(int x,int y, int z);


    protected:
    friend class GameEventAggre;
    friend class AIController;
    friend class DemoController;
    friend class PlayerController;
    friend class GameEventDemo;
    friend class Controller;
    List sprite;
    int direction_;

    private:
    int score_;
    int sfx,sfy,ski;
    bool crashed_;
    Controller* control;
    //Snake* snakes_;
};

#endif  //_SNAKE_H
