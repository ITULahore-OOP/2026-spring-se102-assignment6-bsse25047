#ifndef GUILD_H
#define GUILD_H
#include <iostream>
#include <string>
#include "Hero.h"
using namespace std;

class Guild{
    string guildName;
    Hero* roster[15];
    int memberCount;
public:
    friend ostream& operator<<(ostream& os, const Guild& g);
    Guild(string);
    ~Guild();
    string getGuildName() const;
    int getMemberCount() const;
    int calculateTotalGuildPower();
    void displayGuildStats();
    void operator+=(Hero*);
};

#endif