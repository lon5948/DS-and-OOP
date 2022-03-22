#include <iostream>
#include <string>
#include <vector>
#include "Monster.h"
using namespace std;

Monster::Monster():GameCharacter(){}

Monster::Monster(string name,int maxHealth,int attack,int defense,int money):GameCharacter(name,"Monster",maxHealth,attack,defense,0){}

bool Monster::triggerEvent(Object* object){
    int ans;
    Player* player = dynamic_cast<Player*>(object);
    cout << "[" << getName() << "]: Health = " << getCurrentHealth() << " , Attack = " << getAttack() << " , Defense = " << getDefense() << endl;

    while(1){
        cout << "DO you want to fight with the monster? [ 1.check status / 2.yes / 3.retreat ]" << endl;
        cin >> ans;
        cout << endl;
        if(ans == 1){
            player->triggerEvent(player);
            cout <<  endl ;
            continue;
        }
        else if(ans == 2){

            while(player->getCurrentHealth()>0 && getCurrentHealth()>0){
                takeDamage(player->getAttack());
                if(!checkIsDead()){
                    player->takeDamage(getAttack());
                }
            }
            if(checkIsDead()){
                cout << "Good! You beat " << getName() << "!" << endl;
                cout << endl;
                if(getName() == "Rose"){
                    cout << "-----------------------------------" << endl;
                    cout << "-You are a winner! Congratulation!-" << endl;
                    cout << "-----------------------------------" << endl;
                }
            }
            else{
                cout << "You are dead!" << endl;
                cout << getName() << " beats you!" << endl;
            }
            return true;
        }
        else if(ans == 3){
            player->changeRoom(player->getPreviousRoom());
            cout << endl;
            return false;
        }
    }
}
