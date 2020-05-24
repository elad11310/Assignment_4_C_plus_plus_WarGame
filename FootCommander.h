//
// Created by elad on 24/05/2020.
//

#ifndef MATALA4_WARGAME_FOOTCOMMANDER_H
#define MATALA4_WARGAME_FOOTCOMMANDER_H

#endif //MATALA4_WARGAME_FOOTCOMMANDER_H

#include "Soldier.h"

class FootCommander : public Soldier {

private:
    int _damage;

public:

    FootCommander(int player) : Soldier(150, "FootCommander", player), _damage(20) {}

    virtual void move(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> _currentPos) override;

    virtual ~FootCommander();

    int getDamge();

};
