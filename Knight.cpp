#include "Knight.h"

//Parameterized constructor
Knight::Knight(string n,int h,int p,int r,int b):Warrior(n,h,p,r){	//using serial initialization to call inherited class constructor
//initializing parameters to private attributes
    chargeBonus = b;
    cout<<"Knight Constructor Activated!"<<endl;
}

//Destructor
Knight::~Knight(){
    cout<<"Knight Destructor Activated!"<<endl;
}

//getter
int Knight::getChargeBonus() const{
    return chargeBonus;
}

//calculating functions
int Knight::calculateBurstDamage() const{
   return getPower() + chargeBonus;		//returns the burst damage
}