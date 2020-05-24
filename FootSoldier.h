//
// Created by elad on 23/05/2020.
//

#ifndef MATALA4_WARGAME_FOOTSOLDIER_H
#define MATALA4_WARGAME_FOOTSOLDIER_H

#endif //MATALA4_WARGAME_FOOTSOLDIER_H

#include "Soldier.h"

class FootSoldier : public Soldier {

private:
    int _damage;

public:

    FootSoldier(int player) : Soldier(100, "FootSoldier", player), _damage(10) {}

    virtual void move(std::vector<std::vector<Soldier *>> &board , std::pair<int, int> _currentPos) override;

    virtual ~FootSoldier();

    int getDamge();

};
