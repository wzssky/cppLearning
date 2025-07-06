#include <iostream>
#include <string>
#include <deque>
#include <vector>
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

#endif