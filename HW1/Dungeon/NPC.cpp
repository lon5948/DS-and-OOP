#include <iostream>
#include <string>
#include <vector>
#include "NPC.h"
using namespace std;

NPC::NPC():GameCharacter(){}

NPC::NPC(string name, string script, vector<Item> commodity):GameCharacter(name,"NPC",0,0,0,0){
    this->script = script;
    this->commodity = commodity;
}

void NPC::listCommodity(){
    for(int i=0;i<commodity.size();i++){
        cout << commodity[i].getName() << endl;
    }
}

bool NPC::triggerEvent(Object* object){
    int ans;
    Player* player = dynamic_cast<Player*>(object);
    cout << "[" << getName() << "] " << getScript() << endl;
    cout << "[Which one do you want to equip?]" << endl;
    for(int i=0;i<commodity.size();i++){
        int a;
        a = i + 1;
        cout << "   " << a << "." << commodity[i].getName() << endl;
    }
    cin >> ans;
    cout << endl;
    switch(ans){
        case 1:
            player->addItem(commodity[0]);
            player->increaseStates(commodity[0].getHealth(),commodity[0].getAttack(),commodity[0].getDefense(),commodity[0].getMoney());
            break;
        case 2:
            player->addItem(commodity[1]);
            player->increaseStates(commodity[1].getHealth(),commodity[1].getAttack(),commodity[1].getDefense(),commodity[1].getMoney());
            break;
        case 3:
            player->addItem(commodity[2]);
            player->increaseStates(commodity[2].getHealth(),commodity[2].getAttack(),commodity[2].getDefense(),commodity[2].getMoney());
            break;
    }

}

void NPC::setScript(string script){
    this->script = script;
}

void NPC::setCommodity(vector<Item> commodity){
    this->commodity = commodity;
}

string NPC::getScript(){
    return this->script;
}

vector<Item> NPC::getCommodity(){
    return this->commodity;
}
