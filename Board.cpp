//
// Created by elad on 23/05/2020.
//


#include "Board.h"
#include "Paramedic.h"
#include "ParamedicCommander.h"
#include <iostream>


// checking if there are any soldiers on the board regarding to the player's number
bool WarGame::Board::has_soldiers(uint player_number) const {
    for (int i = 0; i < this->board.size(); i++) {
        for (int j = 0; j < this->board[i].size(); j++) {
            if (board[i][j] != nullptr) {
                if (board[i][j]->getPlayer() == player_number) {
                    return true;
                }
            }
        }

    }
    return false;

}

Soldier *&WarGame::Board::operator[](std::pair<int, int> location) {
    if (board[location.first][location.second] == nullptr)
        return board[location.first][location.second];
    else {
        std::invalid_argument("this place is already been taken by another soldier");
    }

}

Soldier *WarGame::Board::operator[](std::pair<int, int> location) const {
    return board[location.first][location.second];
}

void WarGame::Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction) {
    int i = source.first;
    int j = source.second;
    // checking if a soldier placed on this source
    if(board[i][j]!= nullptr){
    //if ((*this)[source] != nullptr) {
        // checking if we can make a move
        std::pair<int, int> loc = checkMove(i, j, direction);
        int x = loc.first;
        int y = loc.second;
        // if we can make a move
        if (x != -1 && y != -1) {
            // making the recent place to null because we moved.
            board[i][j] = nullptr;
            //(*this)[source] = nullptr;
            // making polymorphism move - which means each soldier makes his own ability.
            //(*this)[loc]->move(board, loc);
            board[x][y]->move(board,loc);


        }
        else{
           // std::cout << "not a valid move" << std::endl;
           throw std:: invalid_argument("Not a vaild a move");
        }
    }
    else{
        std::cout << "there is already a soldier there" << std::endl;
    }


}

std::pair<int, int> WarGame::Board::checkMove(int i, int j, MoveDIR dir) {

    switch (dir) {
        case Up:
            if (i + 1 < Rows) {
                if (board[i + 1][j] == nullptr) {
                    board[i + 1][j] = board[i][j];
                    return {i + 1, j};
                }
            }
            break;

        case Down:
            if (i - 1 >= 0) {
                if (board[i - 1][j] == nullptr) {
                    board[i - 1][j] = board[i][j];
                    return {i - 1, j};
                }
            }

            break;
        case Right:
            if (j + 1 < Cols) {
                if (board[i][j + 1] == nullptr) {
                    board[i][j + 1] = board[i][j];
                    return {i, j + 1};
                }
            }

            break;
        case Left:
            if (j - 1 >= 0) {
                if (board[i][j - 1] == nullptr) {
                    board[i][j - 1] = board[i][j];
                    return {i, j - 1};
                }
            }

            break;

    }
    // if its not possible to move
    return {-1, -1};
}



int& WarGame::Board:: getTurn() {return this->turn;}

std::vector<std::vector<Soldier*>> WarGame::Board:: getBoard(){
    return this->board;
}

bool WarGame::Board:: has_only_paramedics(uint player_number) const{

    for (int i = 0; i < this->board.size(); i++) {
        for (int j = 0; j < this->board[i].size(); j++) {
            if (board[i][j] != nullptr) {
                if (board[i][j]->getPlayer() == player_number) {
                    // checking if the current solder is not paramedic and not paramedic commander
                   if(typeid(board[i][j])!=typeid(Paramedic*) && typeid(board[i][j])!=typeid(ParamedicCommander*)){
                       return true;
                   }
                }
            }
        }

    }
    return false;


}