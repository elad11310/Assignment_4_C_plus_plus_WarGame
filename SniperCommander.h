//
// Created by elad on 24/05/2020.
//

#ifndef MATALA4_WARGAME_SNIPERCOMMANDER_H
#define MATALA4_WARGAME_SNIPERCOMMANDER_H

#endif //MATALA4_WARGAME_SNIPERCOMMANDER_H

#include "Soldier.h"

class SniperCommander : public Soldier {

private:
    int _damage;

public:

    SniperCommander(int player) : Soldier(120, "SniperCommander", player), _damage(100) {}

    virtual void move(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> _currentPos) override;

    virtual ~SniperCommander();

    int getDamge();

};
