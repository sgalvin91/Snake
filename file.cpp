#include "file.hpp"

using namespace std;

    File::File()
    {
    }

    File::~File()
    {
    }

//saves the players name to a file
void File::save_name(string name_01,string name_02)
{

    ofstream output;

   output.open("files/players.txt",ios::trunc);

    output<<name_01<<endl;
	output<<name_02<<endl;

    output.close();

}


// loads the player's name into a different event loop
string File::get_name(int i)
{
    ifstream input("files/players.txt",ios::in);

    string name_02;
    input>>name_02;
    if (i!=1)
    {
    while(!input.eof()){input>>name_02;}
    }

    input.close();
    return name_02;
}

//saves the scores to a file
void File::store_scores()
{
    ofstream output;

    output.open("files/scores.txt",ios::trunc);

    output<<person[0]<<" "<< points[0] <<endl;
    output<<person[1]<<" "<< points[1] <<endl;
    output<<person[2]<<" "<< points[2] <<endl;
    output<<person[3]<<" "<< points[3] <<endl;
    output<<person[4]<<" "<< points[4] <<endl;
    output<<person[5]<<" "<< points[5] <<endl;
    output<<person[6]<<" "<< points[6] <<endl;
    output<<person[7]<<" "<< points[7] <<endl;
    output<<person[8]<<" "<< points[8] <<endl;
    output<<person[9]<<" "<< points[9] <<endl;

    output.close();
}


//loads the scores for displaying and editing
void File::load_scores()
{
    ifstream input("files/scores.txt",ios::in);
    int count=0;
    while(!input.eof())
    {
        input>>person[count]>>points[count];
        count++;
    }
    input.close();
}

//find a person in the hi-scores table
string File::get_person(int i)
{
    return person[i];
}

//used simultaniously to get their score
int File::get_points(int j)
{
    return points[j];
}

//chnages the Hi-score table to include someone else
void File::set_person(int k, string l)
{
    person[k]=l;
}

//again they also need their score saved
void File::set_points(int m, int n)
{
    points[m]=n;
}

void File::set_total(bool i)
{
    if(i == true && play_total >0){play_total--;}
    else if (play_total < 2){play_total++;}

    ofstream output;

    output.open("files/settings.txt",ios::trunc);

    output<<play_total<<endl;

    output.close();
}

int File::get_total()
{
    ifstream input("files/settings.txt",ios::in);

        input>>play_total;

    input.close();

    return play_total;
}
