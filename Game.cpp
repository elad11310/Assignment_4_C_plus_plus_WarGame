//
// Created by elad on 24/05/2020.
//



#include "Game.h"
#include "FootSoldier.h"
#include "FootCommander.h"
#include "Sniper.h"
#include "SniperCommander.h"
#include "ParamedicCommander.h"
#include "Paramedic.h"
#include <iostream>

#include <cassert>

namespace WarGame {

    Game::Game() : board(8, 8) {
        // Add soldiers for player 1:
        assert(!board.has_soldiers(1));

        board[{0, 1}] = new FootSoldier(1);
        board[{0, 3}] = new FootCommander(1);
        board[{0, 5}] = new FootSoldier(1);

        assert(board.has_soldiers(1));

        // Add soldiers for player 2:
        assert(!board.has_soldiers(2));
        board[{7, 1}] = new Sniper(2);
        board[{7, 3}] = new FootCommander(2);
        board[{7, 5}] = new FootSoldier(2);
        assert(board.has_soldiers(2));

        // In your game, you can put more soldier types, such as the sniper and the paramedic types.
    }

    uint Game::play() {
        std:: pair<int,int> playerChoose;
        Board::MoveDIR directionChoose;

        do {
            playerChoose = showSoldiers(board.getTurn());
            directionChoose = chooseDirection();
            board.move(board.getTurn(), playerChoose, directionChoose);
            // for changing the turn
            board.getTurn() = (  board.getTurn() +   board.getTurn()) % 3;



        } while (board.has_soldiers(1) || board.has_soldiers(2));

//        board.move(1, {0, 1}, Board::MoveDIR::Up);      // FootSoldier of player 1 moves forward and attacks.
//        if (!board.has_soldiers(2)) return 1;
//
//        board.move(2, {7, 1}, Board::MoveDIR::Down);    // FootSoldier of player 2 moves forward and attacks.
//        if (!board.has_soldiers(1)) return 2;
//
//        board.move(1, {0, 3},
//                   Board::MoveDIR::Up);      // FootCommander of player 1 moves forward, and all soldiers of player 1 attack.
//        if (!board.has_soldiers(2)) return 1;
//
//        board.move(2, {7, 3},
//                   Board::MoveDIR::Left);    // FootCommander of player 2 moves left, and all soldiers of player 2 attack.
//        if (!board.has_soldiers(1)) return 2;
//
//        /// Write more moves here..
//        if (board.has_soldiers(1) && board.has_soldiers(2)) {
//            return 3;
//        }

        // If no player won, return "tie":
        return 0;
    }

    std::pair<int, int> Game::showSoldiers(int turn) {
        std::pair<int, int> choose;
        std::cout << "Player " << turn << ", your soldiers are: " << std::endl;
        for (int i = 0; i < board.getBoard().size(); i++) {
            for (int j = 0; j < board.getBoard()[i].size(); j++) {
                // if there is a soldier and its mine.
                if (board.getBoard()[i][j] != nullptr && board.getBoard()[i][j]->getPlayer() == board.getTurn()) {
                    std::cout << board.getBoard()[i][j]->getName() + " Location: ";
                    std::cout << i << " , ";
                    std::cout << j << std::endl;
                }
            }

        }
        std::cout << "choose a location of soldier you want to move with: " << std::endl;
        std::cin >> choose.first >> choose.second;





        return choose;

    }

    Board::MoveDIR Game::chooseDirection() {
        int choose;
        std::cout << "choose a direction(0-up,1-down,2-right,3-left): " << std::endl;
        std::cin >> choose;

        switch (choose) {
            case 0:
                return Board::MoveDIR::Up;
            case 1:
                return Board::MoveDIR::Down;

            case 2:
                return Board::MoveDIR::Right;

            case 3:
                return Board::MoveDIR::Left;

        }

    }

}