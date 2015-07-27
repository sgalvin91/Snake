#include "visual.hpp"
#include <string>
#include <cstdlib>
#include <cmath>


using namespace std;
using namespace prg;

Visual::Visual()
{
            width=900;
            length=900;
            eye_Distance=1000;
            num_stars=1000;

	// Create 3 arrays, one for each of the 3D dimensions
	// When looking into the world x is to the right, y is up and z is inward

	// Initialise the stars to random x,y and z positions
	for (int i=0;i<num_stars;i++)
	{
		starX[i]=(rand()%width);
		starY[i]=(rand()%length);
		starZ[i]=(rand()%1000);
	}
            ImageFile("fruit.bmp").load(food01_image);
            ImageFile("banana.bmp").load(food02_image);
            ImageFile("orange.bmp").load(food03_image);
            ImageFile("cherries.bmp").load(food04_image);
            ImageFile("play_circle.bmp").load(playbody_image);
            ImageFile("com_circle.bmp").load(combody_image);
            ImageFile("demo_circle.bmp").load(demo1_image);
            ImageFile("demo_circle2.bmp").load(demo2_image);
            };

Visual::~Visual()
{
};



void Visual::display_world(Canvas& graphics)
        {
            for(int i=40; i < width-40; i++)
            {
                for(int j=60; j<length-20; j++)
                {
                    graphics.set_pixel(i,j,Colour(0,0,0));
                }
            }

		// Draw all the stars and calculate their new positions
		for (int i=0;i<num_stars;i++)
		{
			// To make the code clearer I have moved the drawing into a new function
			Draw_star(starX[i],starY[i],starZ[i],eye_Distance,graphics);

			// Move the star toward the camera by reducing its z (depth) value
			starZ[i]=starZ[i]-4;

			// When the star is behind the camera regenerate it in the distance
			if (starZ[i]<=0)
			{
				starX[i]=(rand()%width);
				starY[i]=(rand()%length);
				starZ[i]=1000;
			}
		}
        };

void Visual::display_food(int x, int y, int z,Canvas& graphics)
        {
            // displays the food
            switch (z)
            {
            case 1:graphics.blit(food01_image,0,0,20,20,x-10,y-10);break;
            case 2:graphics.blit(food02_image,0,0,20,20,x-10,y-10);break;
            case 3:graphics.blit(food03_image,0,0,20,20,x-10,y-10);break;
            case 4:graphics.blit(food04_image,0,0,20,20,x-10,y-10);break;
            }

        };




void Visual::display_snakes(int x, int y, int z,Canvas& graphics)
        {
            switch (z)
            {
            case 1:graphics.blit(playbody_image,0,0,20,20,x-10,y-10);break;
            case 2:graphics.blit(combody_image,0,0,20,20,x-10,y-10);break;
            case 3:graphics.blit(demo1_image,0,0,20,20,x-10,y-10);break;
            case 4:graphics.blit(demo2_image,0,0,20,20,x-10,y-10);break;
            }
        };



void Visual::Draw_star(int X,int Y,int Z,int i,Canvas& graphics)
{
	// Precalculate the centre of the screen
	int Cx=450;
	int Cy=450;

	// Project position from 3D to 2D (see slides)
	// Note that this must be done with floating point calculations
	int Sx=((i*(X-Cx))/(Z+i))+Cx;
	int Sy=((i*(Y-Cy))/(Z+i))+Cy;

    for (int i=Sx; i <=Sx ; i++)
            {
                for(int j=Sy; j<=Sy; j++)
                {
                    graphics.set_pixel(i,j,Colour(255,255,255));
                }
            }
}

void Visual::draw_eyes(int x, int y, int z, Canvas& graphics)
{
    double curve=4;
       switch (z)
       {
       case 1: curve = 4.7;break;
       case 2:curve = 1.5;break;
       case 3: curve = 6.3;break;
       case 4:curve = 3.1;break;
       case 0: curve = 4;break;
       }
       int eye1x=-sin(curve-0.8)*5;
       int eye1y=cos(curve-0.8)*5;
       int eye2x=-sin(curve+0.8)*5;
       int eye2y=cos(curve+0.8)*5;
    graphics.draw_circle(x+eye1x,y+eye1y,2,Colour(255,255,255));
    graphics.draw_circle(x+eye2x,y+eye2y,2,Colour(255,255,255));
};

