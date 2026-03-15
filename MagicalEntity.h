#ifndef MAGICALENTITY_H
#define MAGICALENTITY_H
#include <iostream>
#include <string>
using namespace std;

class MagicalEntity{
    int manaPool;
    int spellPower;
public:
    MagicalEntity(int,int);
    ~MagicalEntity();
    int getMana() const;
    int getSpellPower() const;
};

#endif