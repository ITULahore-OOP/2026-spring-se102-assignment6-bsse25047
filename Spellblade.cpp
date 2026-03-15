#include "Spellblade.h"

//Parameterized constructor
Spellblade::Spellblade(string n,int h,int p,int r,int m,int s):Warrior(n,h,p,r),MagicalEntity(m,s){
    cout<<"Spellblade constructor Activated!"<<endl;
}

//Destructor
Spellblade::~Spellblade(){
    cout<<"Spellblade Distructor Activated!"<<endl;
}

//calculating function
int Spellblade::calculateHybridDamage() const{
    return getPower() + getSpellPower();	//returning hyprid damage found by using formula
}