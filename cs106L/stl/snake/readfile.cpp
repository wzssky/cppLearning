#include <iostream>
#include <string>
#include <fstream>
#include "untils.h"
#include "data_struture.h"
using namespace std;

void open_configfile(ifstream& input){
    while(true){
        cout << " enter filename!" << endl;
        string filename = getline(); 
        input.open(filename.c_str());
        if(input.is_open()) return;

        cout << "can't open the file" << filename << endl;
        input.clear();
    }
}

void load_world(Game_board& game, ifstream& input){
    input >> game.sizeR >> game.sizeC;
    game.world.resize(game.sizeR);
    input >> game.dx >> game.dy;

    // string dummy;
    // getline(input, dummy);
    input.ignore();

    for(size_t row = 0; row < game.sizeR; ++row){
        getline(input, game.world[row]);
        cout << game.world[row] << endl;
        int col = game.world[row].find('*');
        if (col != string::npos){
            Point head;
            head.row = row;
            head.col = col;
            game.snake.push_back(head);
        }
    }

    game.num_eaten = 0;

}

void initialize(Game_board& game){
    ifstream input;
    open_configfile(input);
    load_world(game, input);
}

int main(){
    Game_board main_game;
    initialize(main_game);
}

