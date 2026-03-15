#include "catch.hpp"
#include "Hero.h"
#include "Warrior.h"
#include "MagicalEntity.h"
#include "Spellblade.h"
#include "Knight.h"
#include "Guild.h"
#include <iostream>
using namespace std;

int main()
{
    int choice;

    string guildName;
    cout<<"Enter Guild Name: ";
    cin>>guildName;
	Guild g(guildName);

    do{
        cout<<"========================================="<<endl;
        cout<<"                 MENU"<<endl;
        cout<<"========================================="<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"1. Add Hero"<<endl;
        cout<<"2. Add Warrior"<<endl;
        cout<<"3. Add Magical Entity"<<endl;
        cout<<"4. Add Speelblade"<<endl;
        cout<<"5. Add Knight"<<endl;
        cout<<"6. Total Guild Power"<<endl;
        cout<<"7. View Guild Stats"<<endl;
		cout<<"8. Print Entire Guild using operator <<"<<endl;
        cin>>choice;

        switch(choice){
            case 0:
{
                cout<<"Exiting..."<<endl;
                break;
}

            case 1:
{
                cout<<"========================================="<<endl;
                cout<<"             ADD Hero"<<endl;
                cout<<"========================================="<<endl;
                string heroName;
                int health, power;
                cout<<"Enter Hero Name: ";
                cin>>heroName;
                cout<<"Enter Hero Health: ";
                cin>>health;
                cout<<"Enter Hero Power: ";
                cin>>power;
                Hero* h = new Hero(heroName,health,power);
                g += h;
 			    cout<<"Hero added! Current members: "<<g.getMemberCount()<<endl;

				int task;
                cout<<"1. Take Damage"<<endl;
                cout<<"2. Compare Strength using > of Two heros"<<endl;
                cout<<"3. Find Combined Vitality"<<endl;
				cout<<"0. Exit"<<endl;
    			cin>>task;

				if(task == 0){
					break;
				}
    			else if(task == 1){
					int damage;
					cout<<"Enter Damage: "<<endl;
					cin>>damage;
					h->takeDamage(damage);
					cout<<"After applying damage "<<h->getName()<<" health is"<<h->getHealth()<<endl;
				}
    			else if(task == 2){
					string name;
					int healths, powers;

                	cout<<"Enter Hero Name: ";
                	cin>>name;
                	cout<<"Enter Hero Health: ";
                	cin>>healths;
               		cout<<"Enter Hero Power: ";
                	cin>>powers;
					Hero secHero(name,healths,powers);

					if(*h>secHero){
						cout<<h->getName()<<" is stronger than "<<secHero.getName()<<endl;
					}
					else
						cout<<h->getName()<<" is stronger than "<<secHero.getName()<<endl;
					}

    			else if(task == 3){
					string n;
					int hlth, pwer;

                	cout<<"Enter Hero Name: ";
                	cin>>n;
                	cout<<"Enter Hero Health: ";
                	cin>>hlth;
                	cout<<"Enter Hero Power: ";
                	cin>>pwer;

					Hero secHeros(n,hlth,pwer);
					int result = *h + secHeros;
					cout<<"Combined Vitality is: "<<result<<endl;
					}
				else
					cout<<"Invalid option selected!"<<endl;
                break;
}

            case 2:
{
                cout<<"========================================="<<endl;
                cout<<"               Add Warrior"<<endl;
                cout<<"========================================="<<endl;
                string warriorName;
                int health, power, armorRating;

                cout<<"Enter Warrior Name: ";
                cin>>warriorName;
                cout<<"Enter Warrir Health: ";
                cin>>health;
                cout<<"Enter Warrior Power: ";
                cin>>power;
                cout<<"Enter Warrior Armor Rating: ";
                cin>>armorRating;
                Warrior* w = new Warrior(warriorName, health, power, armorRating);
                g += w;
 				cout<<"Warrior added! Current members: "<<g.getMemberCount()<<endl;

                int x;
                cout<<"Would Like to Calculate Warrior Effective Health?\nIf Yes then Enter 1 and anyother Number for No!"<<endl;
                cin>>x;
                if(x==1){
                    cout<<w->calculateEffectiveHealth()<<endl;
                }
                else{
                    break;
                }

                break;
}

            case 3:
{
                cout<<"========================================="<<endl;
                cout<<"             Add Magical Entity"<<endl;
                cout<<"========================================="<<endl;
int manaPool, spellPower;
cout<<"Enter Magical Entity ManaPool: ";
cin>>manaPool;
cout<<"Enter Magical Entity SpellPower: ";
cin>>spellPower;
	MagicalEntity* m = new MagicalEntity(spellPower, manaPool);

int task;
cout<<"Magical Entity has been added successfully!"<<endl;
cout<<"1. View ManaPool"<<endl;
cout<<"2. View SpellPower"<<endl;
cout<<"0. Exit"<<endl;
cin>>task;

if(task == 1){
    cout<<"ManaPool of Magical Entity is: "<<m->getMana()<<endl;
}

else if(task == 1){
    cout<<"SpellPower of Magical Entity is: "<<m->getSpellPower()<<endl;
}

else if(task == 0){
	delete m;
    break;
}
else
cout<<"Invalid option selected!"<<endl;

delete m;
break;
}

            case 4:
{
                cout<<"========================================="<<endl;
                cout<<"             Add Speelblade"<<endl;
                cout<<"========================================="<<endl;

				string name;
                int health, power, armorRating, spellPower, manaPool;

                cout<<"Enter Spellblade Name: ";
                cin>>name;
                cout<<"Enter Health: ";
                cin>>health;
                cout<<"Enter Base Power: ";
                cin>>power;
                cout<<"Enter Armor Rating: ";
                cin>>armorRating;
				cout<<"Enter ManaPool: ";
                cin>>manaPool;
                cout<<"Enter SpellPower: ";
                cin>>spellPower;

				Spellblade* s = new Spellblade(name, health, power, armorRating,manaPool, spellPower);
				g += s;
 				cout<<"Speelblade added! Current members: "<<g.getMemberCount()<<endl;

				int task;
				cout<<"1. Calculate Hybrid Damage"<<endl;
				cout<<"Any Number to exit"<<endl;

					if(task == 1){
						 cout<<"Hypride Damag for SpeelBlade "<<name<<"is: "<<s->calculateHybridDamage();
					}
					else
						break;
                break;
}

 			case 5:
{
                cout<<"========================================="<<endl;
                cout<<"             Add Knight"<<endl;
                cout<<"========================================="<<endl;

                string name;
                int health, power, armorRating, chargeBonus;

                cout<<"Enter Knight Name: ";
                cin>>name;
                cout<<"Enter Health: ";
                cin>>health;
                cout<<"Enter Base Power: ";
                cin>>power;
                cout<<"Enter Armor Rating: ";
                cin>>armorRating;
                cout<<"Enter Charge Bonus: ";
                cin>>chargeBonus;
                Knight* k = new Knight(name,health,power,armorRating,chargeBonus);
                g += k;
 				cout<<"Knight added! Current members: "<<g.getMemberCount()<<endl;

                int x;
                cout<<"1. Calculate Charge Burst Damage"<<endl;
				cout<<"Any other number to exit"<<endl;
                cin>>x;
                if(x == 1) {
                    cout<<"Burst Damage: "<<k->calculateBurstDamage()<<endl;
                }
				else
					break;
                break;
            }

           case 6:
{
                cout<<"========================================="<<endl;
                cout<<"           Total Guild Power"<<endl;
                cout<<"========================================="<<endl;
                cout<<"Total Guild Power: "<<g.calculateTotalGuildPower()<<endl;
                break;
}

            case 7:
{
                cout<<"========================================="<<endl;
                cout<<"             Guild Stats"<<endl;
                cout<<"========================================="<<endl;
                g.displayGuildStats();
                break;
}

            case 8:
{
                cout<<"========================================="<<endl;
                cout<<"            Print Guild"<<endl;
                cout<<"========================================="<<endl;
                cout<<g;
                break;
}

        }
    }while(choice != 0);
    return 0;
}