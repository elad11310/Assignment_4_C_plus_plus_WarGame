//
// Created by elad on 24/05/2020.
//

#ifndef MATALA4_WARGAME_GAME_H
#define MATALA4_WARGAME_GAME_H

#endif //MATALA4_WARGAME_GAME_H

#pragma once
/**
 * This is a game that demonstrates how to use the Board class.
 * You can modify it and build your own games.
 *
 * @author Oz Levi
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "Board.h"

namespace WarGame {
    class Game {
    private:
        const int numRows = 8;
        const int numCols = 8;
        Board board;
    public:

        /**
        * The constructor initilizes the board and places the soldiers.
        */
        Game();

        /**
         * This function runs a sample play of the game and returns the winner (1 or 2, or 0 in case of tie).
         */
        uint play();

        // for deleting all the allocations we made in the sub vectors.
        ~Game();

        std::pair<int, int> showSoldiers(int turn);

        Board::MoveDIR chooseDirection();
    };
}