#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

Player::Player():GameCharacter(){}

Player::Player(string name,int health,int attack,int defense,int money):GameCharacter(name,"Player",health,attack,defense,money){
    currentRoom = nullptr;
    previousRoom = nullptr;
}

void Player::addItem(Item item){
    inventory.push_back(item);
}

void Player::increaseStates(int increasehealth,int increaseattack,int increasedefense,int increasemoney){
    if(getMoney()+increasemoney>=0){
        if(increasehealth != 0){
            cout << "   [Current Health]  " << getCurrentHealth() << "--->" << getCurrentHealth()+increasehealth << endl;
            setCurrentHealth(getCurrentHealth()+increasehealth);
        }

        if(increaseattack != 0){
            cout << "   [Attack]  " << getAttack() << "--->" << getAttack()+increaseattack << endl;
            setAttack(getAttack()+increaseattack);
        }

        if(increasedefense != 0){
            cout << "   [Defense]  " << getDefense() << "--->" << getDefense()+increasedefense << endl;
            setDefense(getDefense()+increasedefense);
        }

        if(increasemoney != 0){
            cout << "   [Money]  " << getMoney() << "--->" << getMoney()+increasemoney << endl;
            setMoney(getMoney()+increasemoney);
        }
    }
    else{
        cout << "Poor! Not Enough Money!" << endl;
    }
    cout << endl;
}

void Player::changeRoom(Room* current){
    setPreviousRoom(getCurrentRoom());
    setCurrentRoom(current);
}

bool Player::triggerEvent(Object* object){
    Player* player = dynamic_cast<Player*>(object);
    cout << "[Current Status]" << endl;
    cout << "   [Name]  " << getName() << endl;
    cout << "   [Health]  " << getCurrentHealth() << endl;
    cout << "   [Attack]  " << getAttack() << endl;
    cout << "   [Defense]  " << getDefense() << endl;
    cout << "   [Money]  " << getMoney() << endl;
    cout << "   You're in room " << currentRoom->getIndex() << "!" << endl << endl;
    cout << endl;
}

void Player::setCurrentRoom(Room* currentRoom){
    this->currentRoom = currentRoom;
}

void Player::setPreviousRoom(Room* previousRoom){
    this->previousRoom = previousRoom;
}

void Player::setInventory(vector<Item>inventory){
    this->inventory = inventory;
}

Room* Player::getCurrentRoom(){
    return currentRoom;
}

Room* Player::getPreviousRoom(){
    return previousRoom;
}

vector<Item> Player::getInventory(){
    return inventory;
}
