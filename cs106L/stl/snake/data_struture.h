#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <cstdlib>
using namespace std;
#ifndef DATA_H
#define DATA_H
struct Point {
    int row, col;
};

struct Game_board{
    vector<string> world;
    int sizeR, sizeC;
    deque<Point> snake;
    int dx, dy; //direction
    int num_eaten; 
};

string get_strline();

void load_world(Game_board& game, ifstream& input);

void open_configfile(ifstream& input);

void initialize(Game_board& game);

#endif