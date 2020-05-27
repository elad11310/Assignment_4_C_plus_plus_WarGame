//
// Created by elad on 23/05/2020.
//

#ifndef MATALA4_WARGAME_BOARD_H
#define MATALA4_WARGAME_BOARD_H

class Soldier;

#endif //MATALA4_WARGAME_BOARD_H


#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.h"


namespace WarGame {

    class Board {
    private:
        std::vector<std::vector<Soldier *>> board;
        // for saving the players current soldiers
        int Rows, Cols;
        int turn;

    public:
        enum MoveDIR {
            Up, Down, Right, Left
        };


        Board(uint numRows, uint numCols) :
                board(numRows, std::vector<Soldier *>(numCols, nullptr)), Rows(numRows), Cols(numCols),
                turn(2) {}

        int& getTurn();

        std::vector<std::vector<Soldier *>> getBoard();


        // operator for putting soldiers on the game-board during initialization.
        Soldier *&operator[](std::pair<int, int> location);

        // operator for reading which soldiers are on the game-board.
        Soldier *operator[](std::pair<int, int> location) const;

        // The function "move" tries to move the soldier of player "player"
        //     from the "source" location to the "target" location,
        //     and activates the special ability of the soldier.
        // If the move is illegal, it throws "std::invalid_argument".
        // Illegal moves include:
        //  * There is no soldier in the source location (i.e., the soldier pointer is null);
        //  * The soldier in the source location belongs to the other player.
        //  * There is already another soldier (of this or the other player) in the target location.
        // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
        // Your code should be generic. All handling of different types of soldiers
        //      must be handled by polymorphism.
        void move(uint player_number, std::pair<int, int> source, MoveDIR direction);


        // returns true iff the board contains one or more soldiers of the given player.
        bool has_soldiers(uint player_number) const;

        std::pair<int, int> checkMove(int i, int j, MoveDIR dir);

        bool has_only_paramedics(uint player_number) const;


    };

}
