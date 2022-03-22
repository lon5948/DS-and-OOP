#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

Item::Item():Object(){}

Item::Item(string name,int health,int attack,int defense,int money):Object(name,"Item"){
	this->health = health;
	this->attack = attack;
	this->defense = defense;
	this->money = money;
}

int Item::getHealth(){
	return this->health;
}

 int Item::getAttack(){
	return this->attack;
}

int Item::getDefense(){
	return this->defense;
}

void Item::setHealth(int health){
	this->health = health;
}

void Item::setAttack(int attack){
	this->attack = attack;
}

void Item::setDefense(int defense){
	this->defense = defense;
}

void Item::setMoney(int money){
    this->money = money;
}

int Item::getMoney(){
    return money;
}

bool Item::triggerEvent(Object *object){
    int ans;
    Player* player = dynamic_cast<Player*>(object);
    cout << "[" << getName() << "]" << endl;
    if(getHealth()<0)
        cout << "   Health " << getHealth() << endl;
    else
        cout << "   Health +" << getHealth() << endl;
    if(getAttack()<0)
        cout << "   Attack " << getAttack() << endl;
    else
        cout << "   Attack +" << getAttack() << endl;
    if(getDefense()<0)
        cout << "   Defense " << getDefense() << endl;
    else
        cout << "   Defense +" << getDefense() << endl;
    cout << "EQUIP? [ 1.yes / 2.no ]" << endl;
    cin >> ans;
    cout << endl;
    if(ans == 1){
        cout << getName() << " is yours now." << endl;
        player->addItem(*this);
        player->increaseStates(getHealth(),getAttack(),getDefense(),getMoney());
        cout << endl;
        return true;
    }
    else if(ans == 2){
        cout << "OK! Have a nice day!" << endl;
        cout << endl;
        return false;
    }
}



