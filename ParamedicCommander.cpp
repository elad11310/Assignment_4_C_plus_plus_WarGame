//
// Created by elad on 24/05/2020.
//

#include "ParamedicCommander.h"
#include "Paramedic.h"

void ParamedicCommander::move(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> _currentPos) {

    int x = _currentPos.first;
    int y = _currentPos.second;
    // checking the current soldier's player
    int player = board[x][y]->getPlayer();

    for (int i = x + 1; i >= x - 1; i--) {
        for (int j = y - 1; j < y + 1; j++) {
            if(i >= 0 && i < board.size() && j >= 0 && j < board[i].size() && !board[x][y]){
                if(board[i][j]!= nullptr && board[i][j]->getPlayer()==player){
                    board[i][j]->setHealth();
                }
            }

        }
    }
    // now making all the paramedics to only heal.
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            // checking if its Paramedic and if its mine.
            if(typeid(board[i][j])==typeid(Paramedic) &&board[i][j]->getPlayer()==player){
                // if its Paramedic make cast to it
                board[i][j]=(dynamic_cast<Paramedic *>(board[i][j]));
                board[i][j]->move(board,_currentPos);

            }
        }
    }



}

ParamedicCommander::~ParamedicCommander() {

}
