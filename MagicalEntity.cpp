#include "MagicalEntity.h"

//Parameterized constructor
MagicalEntity::MagicalEntity(int m,int s){
//initializing parameters to private attributes
    manaPool = m;
    spellPower = s;
    cout<<"MagicalEntity Constructor Activated!"<<endl;
}

//Destructor
MagicalEntity::~MagicalEntity(){
    cout<<"MagicalEntity Destructor Activated!"<<endl;
}

//***getters***
int MagicalEntity::getMana() const{
    return manaPool;	//returning private attribute manaPool
}
int MagicalEntity::getSpellPower() const{
    return spellPower;	//returning private attribute spellPower
}