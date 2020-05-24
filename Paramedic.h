//
// Created by elad on 24/05/2020.
//

#ifndef MATALA4_WARGAME_PARAMEDIC_H
#define MATALA4_WARGAME_PARAMEDIC_H

#endif //MATALA4_WARGAME_PARAMEDIC_H

#include "Soldier.h"

class Paramedic : public Soldier {


public:

    Paramedic(int player) : Soldier(100, "Paramedic", player){}

    virtual void move(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> _currentPos) override;

    virtual ~Paramedic();



};
