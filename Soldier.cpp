//
// Created by elad on 23/05/2020.
//

#include "Soldier.h"


// when hitted
void Soldier::setDamge(int damge) {
    this->_current_health-=damge;


}
// checking if current soldier alive
bool Soldier::isAlive() {
    if(_current_health<=0){
        return true;
    }
    else return false;
}

// when get healed by a paramedic
void Soldier::setHealth(){
    this->_current_health=_health;
};

int Soldier:: getPlayer() {return this->_player;}

Soldier::~Soldier() {};