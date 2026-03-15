#include "Warrior.h"

//Parameterized constructor
Warrior::Warrior(string n,int h,int p,int r):Hero(n,h,p){	//using serial initialization
//initializing parameters to private attributes
    armorRating = r;
    cout<<"Warrior Constructor Activated!"<<endl;
}

//Destructor
Warrior::~Warrior(){
    cout<<"Warrior Distructor Activated!"<<endl;
}

//***getter***
int Warrior::getArmor() const{
    return armorRating;
}

int Warrior::calculateEffectiveHealth() const{
    return getHealth() + (armorRating * 2);	//returning the calculated effective health
}