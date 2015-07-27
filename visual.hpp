#if !defined(_VISUAL_HPP)
#define _VISUAL_HPP

#include <iostream>
#include <prg/image.hpp>
#include <prg/image_file.hpp>
#include <string>

using namespace prg;
using namespace std;

class Visual{

    public:

    Visual();
    ~Visual();
    void display_world(Canvas&);
    void display_food(int x, int y, int z,Canvas&);
    void display_snakes(int x, int y, int z,Canvas&);
    void player_collision();
    void computer_collision();
    void Draw_star(int X,int Y,int Z,int i,Canvas&);
    void draw_eyes(int x,int y, int z, Canvas&);


//    Canvas graphics;
    private:
    Image food01_image;
    Image food02_image;
    Image food03_image;
    Image food04_image;
    Image demo1_image;
    Image demo2_image;
    Image playbody_image;
    Image combody_image;
    int length;
    int width;
    int eye_Distance;
    int num_stars;
    int starX[1000];
    int starY[1000];
    int starZ[1000];
    };

#endif

