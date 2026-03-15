#include "Hero.h"

//parameterized constructor
Hero::Hero(string n,int h,int p){
    //initializing parameters to private attributes
    if(h>=0){
        health = h;
    }
    else{
        health = 0;

    }

    heroName = n;
    basePower = p;
}

//destructor
Hero::~Hero(){}

//***getters***
string Hero::getName() const{
    return heroName;    //returning private attribute heroName
}
int Hero::getHealth() const{
    return health;    //returning private attribute health
}
int Hero::getPower() const{
    return basePower;    //returning private attribute basePower
}

//***Member functions***
void Hero::takeDamage(int damage){
    if(health-damage>0){    //making sure health should never be below 0
        health -= damage;    //reducing damage from health
        cout<<"Damage Has been made successfully!"<<endl;    //displaying success statement
    }
    else{              //in case health will be reduced to less than 0 after reducing damage
        health = 0;    //setting health to 0
        cout<<"Due to high level Damage health is going below 0. Hence, setting health to 0"<<endl;    //displaying warning statement
    }
}
bool Hero::operator>(const Hero &other) const{    //> operator overloading
    if(basePower>other.basePower){    //if the current hero’s basePower is strictly greater than the other hero’s basePower
        return true;                  //then return true
    }
    else                              //otherwise
        return false;                 //return false
}

int Hero::operator+(const Hero &other) const{    //+ operator overloading
    return health+other.health;            //returning the sum of the current hero's health and the other hero's health
}