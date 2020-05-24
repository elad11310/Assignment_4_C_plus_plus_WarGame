//
// Created by elad on 23/05/2020.
//

#ifndef MATALA4_WARGAME_SOLDIER_H
#define MATALA4_WARGAME_SOLDIER_H

#endif //MATALA4_WARGAME_SOLDIER_H
#pragma once
#include <string>
#include <vector>


class Soldier {

private:
    int _health;
    int _current_health;
    std::string _name;
    int _player;

public:
     Soldier(int health, std::string name,int player) :
            _health(health), _current_health(health), _name(name), _player(player) {}

    // when the soldier under attack
    void setDamge(int damge);
    // check if the soldier is still alive
    bool isAlive();
    // when a paramedic heals the soldier
    void setHealth();
    // each soldier has a different mover method so override it
    virtual void move(std::vector<std::vector<Soldier*>> &board,std::pair<int, int> _currentPos)=0;
    // virtual distructor
    virtual ~Soldier();

    int getPlayer();
    int getHealth();
    std::string getName();
    std::pair<int,int> getPos();


};