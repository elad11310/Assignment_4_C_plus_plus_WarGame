//
// Created by elad on 23/05/2020.
//

#include "FootSoldier.h"
#include <iostream>

int FootSoldier::getDamge() {
    return this->_damage;
}

void FootSoldier::move(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> _currentPos) {

    bool isHit = false;
    int offSet = 1;
    int x = _currentPos.first;
    int y = _currentPos.second;
    // checking the current soldier's player
    int player = board[x][y]->getPlayer();

// 1,1 ----- i = 2 , j=0
    while (!isHit) {
        for (int i = x + offSet; i >= x - offSet && !isHit; i--) {
            for (int j = y - offSet; j < y + offSet && !isHit; j++) {
                if (i >= 0 && i < board.size() && j >= 0 && j < board[i].size()) {
                    // if any soldier exisits here, and if its there other player soldier
                    if (board[i][j] != nullptr && board[i][j]->getPlayer() != player) {
                        // cast  our soldier to FootSoldier
                        //board[i][j]->setDamge(dynamic_cast<FootSoldier *>(board[x][y])->getDamge());
                        board[i][j]->setDamge(getDamge());
                        if(!board[i][j]->isAlive()){
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

}

// distructor for foot soldier object
FootSoldier::~FootSoldier() {

}
