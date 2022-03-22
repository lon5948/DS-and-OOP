#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
using namespace std;

GameCharacter::GameCharacter():Object(){}

GameCharacter::GameCharacter(string name,string tag,int maxHealth,int attack,int defense,int money):Object(name,tag){
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    this->attack = attack;
    this->defense = defense;
    this->money = money;
}

bool GameCharacter::checkIsDead(){
    if(getCurrentHealth()<=0)
        return true;
    else
        return false;
}

int GameCharacter::takeDamage(int damage){
    if(damage >= getDefense()){
        setCurrentHealth(getCurrentHealth()-(damage-getDefense()));
        cout << getName() << ": " << getDefense()-damage << endl;
        if(getCurrentHealth()>0){
            cout << "Current Health:" << getCurrentHealth() << endl;
        }
        else
            cout << "Current Health:0" << endl;
        cout << "------------------------------" << endl;
    }
    else{
        cout << getName() << ": -0" << endl;
        if(getCurrentHealth()>0){
            cout << "Current Health:" << getCurrentHealth() << endl;
        }
        else
            cout << "Current Health:0" << endl;
        cout << "------------------------------" << endl;
    }
}

void GameCharacter::setMaxHealth(int maxHealth){
    this->maxHealth = maxHealth;
}

void GameCharacter::setCurrentHealth(int currentHealth){
    this->currentHealth = currentHealth;
}

void GameCharacter::setAttack(int attack){
    this->attack = attack;
}

void GameCharacter::setDefense(int defense){
    this->defense = defense;
}

void GameCharacter::setMoney(int money){
    this->money = money;
}
int GameCharacter::getMaxHealth(){
    return maxHealth;
}

int GameCharacter::getCurrentHealth(){
    return currentHealth;
}

int GameCharacter::getAttack(){
    return attack;
}

int GameCharacter::getDefense(){
    return defense;
}

int GameCharacter::getMoney(){
    return money;
}
