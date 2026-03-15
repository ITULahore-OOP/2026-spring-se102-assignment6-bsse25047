#ifndef WARRIOR_H
#define WARRIOR_H
#include <iostream>
#include <string>
#include "Hero.h"
using namespace std;

class Warrior:public Hero{
    int armorRating;
public:
    Warrior(string,int,int,int);
    ~Warrior();
    int getArmor() const;
    int calculateEffectiveHealth() const;
};

#endif