//
// Created by elad on 24/05/2020.
//

#ifndef MATALA4_WARGAME_SNIPER_H
#define MATALA4_WARGAME_SNIPER_H

#endif //MATALA4_WARGAME_SNIPER_H


#include "Soldier.h"

class Sniper : public Soldier {

private:
    int _damage;

public:

    Sniper(int player) : Soldier(100, "Sniper", player), _damage(50) {}

    virtual void move(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> _currentPos) override;

    virtual ~Sniper();

    int getDamge();

};
