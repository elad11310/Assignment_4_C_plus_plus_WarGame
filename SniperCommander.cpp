//
// Created by elad on 24/05/2020.
//


#include "SniperCommander.h"
#include "Sniper.h"

void SniperCommander:: move(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> _currentPos) {
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
    if(!isAlive()){
        delete (board[maxI][maxJ]);
        board[maxI][maxJ] = nullptr;
    }

    // now looking for all my snipers to shot.

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            // checking if its Sniper and if its mine.
            if(typeid(board[i][j])==typeid(Sniper) &&board[i][j]->getPlayer()==player){
                // if its Sniper make cast to it
                board[i][j]=(dynamic_cast<Sniper*>(board[i][j]));
                board[i][j]->move(board,_currentPos);

            }
        }
    }

}

SniperCommander:: ~SniperCommander(){

}

int SniperCommander::getDamge(){
    return this->getDamge();
}