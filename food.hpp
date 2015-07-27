#if !defined(_FOOD_HPP)
#define _FOOD_HPP

#include <iostream>

using namespace std;

class Food{

    public:

    Food();
    ~Food();
    int getx(int a);
    int gety(int b);
    int getz(int c);
    bool getstatus();
    void spawn_food(int i);
    void set_food(int c);
    void set_avl(bool a);
    int find_food();



    private:
    int foodx[5];
    int foody[5];
    int foodz[5];
    bool available;

};

#endif
