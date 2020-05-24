//
// Created by elad on 24/05/2020.
//

#ifndef MATALA4_WARGAME_PARAMEDICCOMMANDER_H
#define MATALA4_WARGAME_PARAMEDICCOMMANDER_H

#endif //MATALA4_WARGAME_PARAMEDICCOMMANDER_H


#include "Soldier.h"

class ParamedicCommander : public Soldier {


public:

    ParamedicCommander(int player) : Soldier(200, "ParamedicCommander", player){}

    virtual void move(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> _currentPos) override;

    virtual ~ParamedicCommander();



};