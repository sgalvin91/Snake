#include "food.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;


Food::Food()
{
};

Food::~Food()
{
}
//this is done after the food is given an x and y position and determines the food value
void Food::set_food(int c)
{
    //c is the number in the array of food
    //s is the size about to be set
    int s;
     if ((s=rand()%2) == 1) //value of 0 or 1
            {
               if((s=rand()%2) == 1) // value of 0 or 1
               {
                   if((s=rand()%2) == 1) //value of 0 or 1
                            {
                                foodz[c]= 4;//12.5% chance of size 4 (1,1,1)
                            }
                        else
                        {
                            foodz[c]= 3;//12.5% chance of size 3  (1,1,0)
                        }
               }
                    else
                    {
                        foodz[c]= 2;//25% chance of being size 2 (1,0)
                    }
            }
                else
                {
                    foodz[c]= 1;//50% chance of being size 1 (0)
                }
}

//creates food with random x and y positions
void Food::spawn_food(int a)
{
    foodx[a]=((rand()% 40)+3)*20;//gives a minimum of 60 and a max of 860
    foody[a]=((rand()% 40)+4)*20;//gives a minimum of 80 and a max of 880
    set_food(a);
}

//gets the x value of a certain food with the array
int Food::getx(int a)
{
    return foodx[a];
}

//gets the y value of a certain food with the array
int Food::gety(int b)
{
    return foody[b];
}

//gets the size of a certain food with the array
int Food::getz(int c)
{
    return foodz[c];
}

//used for the AI so it finds the largest food avaliable
int Food::find_food()
    {
        for(int i=0; i<5; i++)
        {
            for (int j=4; j>0; j--)
            {
             if (foodz[i] == j)
             {return i;}
            }
        }
        return 0;
    }
