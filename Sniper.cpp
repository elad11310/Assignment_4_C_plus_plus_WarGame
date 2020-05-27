//
// Created by elad on 24/05/2020.
//


#include "Sniper.h"

void Sniper:: move(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> _currentPos) {
    // looking for the player with the maximum hp in the rival players.
    int x = _currentPos.first;
    int y = _currentPos.second;
    int maxI=0;
    int maxJ=0;
    // checking the current soldier's player
    int player = board[x][y]->getPlayer();
    int maxHealth=0;

    for(x=0;x<board.size();x++){
        for(y=0;y<board[x].size();y++){
            if(board[x][y]!= nullptr && board[x][y]->getPlayer()!=player){
                if(board[x][y]->getHealth()>maxHealth){
                    maxHealth=board[x][y]->getHealth();
                    // saving this current max health soldier indices to know where to attack.
                    maxI=x;
                    maxJ=y;
                }
            }
        }
    }
    // now hit the player with the maximum health in the rival soldiers.
    board[maxI][maxJ]->setDamge(getDamge());
    // if its dead.
    if(!board[maxI][maxJ]->isAlive()){
        delete (board[maxI][maxJ]);
        board[maxI][maxJ] = nullptr;
    }
}

Sniper:: ~Sniper(){

}

int Sniper::getDamge(){
    return this->_damage;
}