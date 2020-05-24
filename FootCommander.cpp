//
// Created by elad on 24/05/2020.
//



#include "FootCommander.h"
#include "FootSoldier.h"


int FootCommander::getDamge() {
    return this->_damage;
}

void FootCommander::move(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> _currentPos) {

    bool isHit = false;
    int offSet = 1;
    int x = _currentPos.first;
    int y = _currentPos.second;
    // checking the current soldier's player
    int player = board[x][y]->getPlayer();

    while (!isHit) {
        for (int i = x + offSet; i >= x - offSet && !isHit; i--) {
            for (int j = y - offSet; j < y + offSet && !isHit; j++) {
                if (i >= 0 && i < board.size() && j >= 0 && j < board[i].size()) {
                    // if any soldier exisits here, and if its there other player soldier
                    if (board[i][j] != nullptr && board[i][j]->getPlayer() != player) {
                        // cast  our soldier to FootCommanderSoldier
                        //board[i][j]->setDamge(dynamic_cast<FootCommander *>(board[x][y])->getDamge());
                        board[i][j]->setDamge(getDamge());
                        if(!isAlive()){
                            delete (board[i][j]);
                            board[i][j] = nullptr;
                        }
                        isHit = true;
                    }
                }
            }
        }
        offSet++;
    }

    // now making all the foot soldiers to only shoot.
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            // checking if its footsoldier and if its mine.
            if(typeid(board[i][j])==typeid(FootSoldier) &&board[i][j]->getPlayer()==player){
                // if its footsoldier make cast to it
                board[i][j]=(dynamic_cast<FootSoldier*>(board[i][j]));
                board[i][j]->move(board,_currentPos);

            }
        }
    }

}

// distructor for foot soldier object
FootCommander::~FootCommander() {

}

