#ifndef KNIGHT_H
#define KNIGHT_H
#include <iostream>
#include <string>
#include "Warrior.h"
using namespace std;

class Knight:public Warrior{
    int chargeBonus;
public:
    Knight(string,int,int,int,int);
    ~Knight();
    int getChargeBonus() const;
    int calculateBurstDamage() const;
};

#endif