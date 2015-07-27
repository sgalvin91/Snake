#if !defined(_FILE_HPP)
#define _FILE_HPP

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class File{
    public:

    File();
    ~File();
    void save_name(string name_01,string name_02);
    string get_name(int i);
    void store_scores();
    void load_scores();
    void reset_scores();
    string get_person(int i);
    int get_points(int j);
    void set_person(int k, string l);
    void set_points(int m,int n);
    int get_total();
    void set_total(bool i);


private:
    string person[10];
    int points[10];
    int play_total;


};

#endif
