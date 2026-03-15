#ifndef SPELLBLADE_H
#define SPELLBLADE_H
#include <iostream>
#include <string>
#include "Warrior.h"
#include "MagicalEntity.h"
using namespace std;

class Spellblade:public Warrior,public MagicalEntity{
public:
    Spellblade(string,int,int,int,int,int);
    ~Spellblade();
    int calculateHybridDamage() const;
};

#endif