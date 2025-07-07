#include <iostream>
#include <string>
#include <fstream>
#include "untils.h"
#include "data_struture.h"
#include <ctime>
#include <cstdlib>
#define max_eaten 100
using namespace std;


const double wait_time = 0.1;
void pause(){
    clock_t start_time = clock();
    while( static_cast<double>(clock()- start_time)/CLOCKS_PER_SEC < wait_time );
}


const string ClearCommand = "CLS";
void print_world(Game_board& game){
    system(ClearCommand.c_str());
    for(size_t i=0; i< game.sizeR; ++i){
        cout << game.world[i] << endl;
    }
    cout << "food eaten:" << game.num_eaten << endl;
}


void display_result(Game_board& game){
    print_world(game);
    if(game.num_eaten == max_eaten)
        cout << "the snake win" << endl;    
    else
        cout <<  "the snake crashed down" << endl;
}


Point get_nextposition(int dx, int dy, Game_board& game){
    Point snake_head = game.snake.front();
    snake_head.row += dy;
    snake_head.col += dx;
    return snake_head;
}


bool in_world(Point& head, Game_board& game){
    return head.row < game.sizeR && head.col < game.sizeC && head.row >=0 && head.col >=0;
}


bool crashed(Point& head, Game_board& game){
    return !in_world(head, game) || game.world[head.row][head.col] == '#' || game.world[head.row][head.col] == '*';
}

bool turn_head(double probability){
    return (rand() / (RAND_MAX + 1.0)) < probability;
}


const double turn_rate = 0.2;
void ai(Game_board& game){
    Point nextp = get_nextposition(game.dx, game.dy, game);
    if(crashed(nextp, game) || turn_head(turn_rate)){
        int leftdx = -game.dy;
        int leftdy = game.dx;
        int rightdx = game.dy;
        int rightdy = -game.dx;
        Point leftp = get_nextposition(leftdx, leftdy, game);
        bool canleft = !crashed(leftp, game);
        Point rightp = get_nextposition(rightdx, rightdy, game);
        bool canright = !crashed(rightp, game);

        bool mustleft = false;
        if(!canleft && !canright) return;
        else if (canleft && !canright) mustleft = true;
        else if (!canleft && canright) mustleft = false;
        else 
            mustleft = turn_head(0.5);

        game.dx = mustleft ? leftdx : rightdx;
        game.dy = mustleft ? leftdy : rightdy;

    }
}


void place_food(Game_board& game){
    while(true){
        int row = rand() % game.sizeR;
        int col = rand() % game.sizeC;
        if(game.world[row][col] == ' '){
            game.world[row][col]= '$';
            return;
        }
    }
}


bool movesnake(Game_board& game){
    Point nexthead = get_nextposition(game.dx, game.dy, game);
    if(crashed(nexthead,game)) return false;

    bool is_food = (game.world[nexthead.row][nexthead.col] == '$');
    
    game.world[nexthead.row][nexthead.col] = '*';
    game.snake.push_front(nexthead);

    if(!is_food){
        game.world[game.snake.back().row][game.snake.back().col] = ' ';
        game.snake.pop_back();
    }else {
        ++game.num_eaten;
        place_food(game);
    }
    return true;
}


void run_game(Game_board& game){
    while (game.num_eaten < max_eaten){
        print_world(game);
        ai(game);
        if(!movesnake(game))
            break;
        pause();
    }
    display_result(game);
}

int main(){
    Game_board main_game;
    initialize(main_game);
    run_game(main_game);
    return 0;
}

