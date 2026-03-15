#include "Guild.h"

//Parameterized constructor
Guild::Guild(string g){
//initializing parameters to private attributes
    guildName = g;
    memberCount = 0;	//initializing memeberCount  to 0 to avoid garbage value
    }

//Destructor
Guild::~Guild(){
    for(int i = 0; i<memberCount;i++){
roster[i] = nullptr;	//setting to nullptr to destroy allocated memory
}
    cout << "The guild " << guildName << " has been disbanded!\n";
}

//***getters***
string Guild::getGuildName() const{
    return guildName;	//returning private attribute guildName
}
int Guild::getMemberCount() const{
    return memberCount;	//returning private attribute memberCount
}

//calculating function
int Guild::calculateTotalGuildPower(){
int totalPower = 0;
    for(int i = 0; i<memberCount; i++){
        totalPower += roster[i]->getPower();	//adding power of each hero
    }
    return totalPower;
}

void Guild::displayGuildStats(){
//displaying required info
    cout<<"Guild Name: "<<guildName<<endl;
    cout<<"Total Members: "<<memberCount<<"/15"<<endl;
    cout<<"Total Guild Power: "<<calculateTotalGuildPower()<<endl;
}
//operator overloading
void Guild::operator+=(Hero* h){
    if(memberCount>=15){	//making sure No. of heros doesnt exceed 15
        cout<<"Guild is at full capacity!\n";
        return;
        }
        roster[memberCount] = h;	//adding hero
        memberCount++;				//incrementing memberCount by 1

}

//operator overloading
ostream& operator<<(ostream& os, const Guild& g){
//displaying info using operator <<
    os<<"Guild: "<<g.guildName<<endl;
    os<<"Total Members: "<<g.memberCount<<endl;
    if(g.memberCount == 0){
        os<<"No Guild Members Registered!"<<endl;
    }
    else{
        for(int i = 0; i < g.memberCount; i++){
            os<<"- "<<g.roster[i]->getName()<<" (Power: "<<g.roster[i]->getPower()<<")"<<endl;
        }
    }
    return os;	//returning os for the info to be displayed correctly

}
