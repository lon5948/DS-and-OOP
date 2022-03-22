#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Record.h"
using namespace std;

Record::Record(){}

void Record::savePlayer(Player* player, ofstream& oplayer){
    oplayer << player->getName() << endl;
    oplayer << player->getCurrentHealth() << endl;
    oplayer << player->getAttack() << endl;
    oplayer << player->getDefense() << endl;
    oplayer << player->getMoney() << endl;
    oplayer << player->getCurrentRoom()->getIndex() << endl;
    oplayer << player->getPreviousRoom()->getIndex() << endl;
    oplayer << player->getInventory().size() << endl;
    if(!player->getInventory().empty()){
        for(int i=0;i<player->getInventory().size();i++){
            oplayer << player->getInventory()[i].getName() << endl;
            oplayer << player->getInventory()[i].getHealth() << endl;
            oplayer << player->getInventory()[i].getAttack() << endl;
            oplayer << player->getInventory()[i].getDefense() << endl;
            oplayer << player->getInventory()[i].getMoney() << endl;
        }
    }
}

void Record::saveRooms(vector<Room> &rooms, ofstream& orooms){
    int obj_num=0;
    for(int i=0;i<10;i++){

        obj_num += rooms[i].getObjects().size();
    }
    orooms << obj_num;
    for(int i=0;i<rooms.size();i++){
        //orooms << rooms[i].getIndex() << endl;
        /*orooms << rooms[i].getIsExit() << endl;
        if(rooms[i].getUpRoom()!=NULL)
            orooms << rooms[i].getUpRoom()->getIndex() << endl;
        else
            orooms << "-1" << endl;
        if(rooms[i].getDownRoom()!=NULL)
            orooms << rooms[i].getDownRoom()->getIndex() << endl;
        else
            orooms << "-1"  << endl;
        if(rooms[i].getLeftRoom()!=NULL)
            orooms << rooms[i].getLeftRoom()->getIndex() << endl;
        else
            orooms << "-1" << endl;
        if(rooms[i].getRightRoom()!=NULL)
            orooms << rooms[i].getRightRoom()->getIndex() << endl;
        else
            orooms << "-1" << endl;*/
        //orooms << rooms[i].getObjects().size() << endl;
        for(int j=0;j<rooms[i].getObjects().size();j++){
            if(Item* item = dynamic_cast<Item*>(rooms[i].getObjects()[j])){
                //orooms << item->getTag() << endl;
                orooms << item->getName() << endl;
                //orooms << item->getHealth() << endl;
                //orooms << item->getAttack() << endl;
                //orooms << item->getDefense() << endl;
            }

            if(Monster* monster = dynamic_cast<Monster*>(rooms[i].getObjects()[j])){
                //orooms << monster->getTag() << endl;
                orooms << monster->getName() << endl;
                orooms << monster->getCurrentHealth() << endl;
                //orooms << monster->getAttack() << endl;
                //orooms << monster->getDefense() << endl;
            }

            if(NPC* npc = dynamic_cast<NPC*>(rooms[i].getObjects()[j])){
                //orooms << npc->getTag() << endl;
                orooms << npc->getName() << endl;
                //orooms << npc->getScript() << endl;
                //orooms << npc->getCommodity().size() << endl;
                //for(int k=0;k<npc->getCommodity().size();k++){
                  //  orooms << npc->getCommodity()[k].getName() << endl;
                    //orooms << npc->getCommodity()[k].getHealth() << endl;
                    //orooms << npc->getCommodity()[k].getAttack() << endl;
                    //orooms << npc->getCommodity()[k].getDefense() << endl;
               // }
            }
        }
    }
}

void Record::loadPlayer(Player* player, ifstream& iplayer){
    string name,item_name;
    int current,previous;
    int currenthealth,attack,defense,money,item_num,item_health,item_attack,item_defense,item_money;
    iplayer >> name >> currenthealth >> attack >> defense >> money >>  current >> previous >> item_num;
    player->setName(name);
    player->setCurrentHealth(currenthealth);
    player->setAttack(attack);
    player->setDefense(defense);
    player->setMoney(money);
    currentroom = current;
    previousroom = previous;
    for(int i=0;i<item_num;i++){
        iplayer >> item_name >> item_health >> item_attack >> item_defense >> item_money;
        Item item(item_name,item_health,item_attack,item_defense,item_money);
        player->addItem(item);
    }
}
void Record::loadRooms(vector<Room> &rooms, ifstream& irooms){
    /*int index,isexit,up,down,left,right;
    int obj_num,inventory_num,i_health,i_attack,i_defense;
    int m_currenthealth,m_attack,m_defense;
    int inventory_health,inventory_attack,inventory_defense;
    string tag,i_name,m_name,n_name,n_script,inventory_name;
    for(int i=0;i<10;i++){
        Room r;
        r.setIndex(i);
        rooms.push_back(r);
    }*/
    string name;
    string obj_name;
    vector<string>obj;
    int obj_num,monster_current;
    irooms >> obj_num;
    for(int i=0;i<obj_num;i++){
            irooms >> name;
            obj.push_back(name);
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<rooms[i].getObjects().size();j++){
            if(Item* item = dynamic_cast<Item*>(rooms[i].getObjects()[j])){
                obj_name = item->getName();
            }

            if(Monster* monster = dynamic_cast<Monster*>(rooms[i].getObjects()[j])){
                obj_name = monster->getName();
            }

            if(NPC* npc = dynamic_cast<NPC*>(rooms[i].getObjects()[j])){
                obj_name = npc->getName();
            }
            if(find(obj.begin(), obj.end(),obj_name) != obj.end()){
                cout << "";
            }
            else{
                rooms[i].popObject(rooms[i].getObjects()[j]);
            }
        }
    }

    /*for(int i=0;i<10;i++){
        vector<Object*> obj;
        irooms >> isexit >> up >> down >> left >> right;

        rooms[i].setIsExit(isexit);

        if(up!=-1)
            rooms[i].setUpRoom(&rooms[up]);
        if(down!=-1)
            rooms[i].setDownRoom(&rooms[down]);
        if(left!=-1)
            rooms[i].setLeftRoom(&rooms[left]);
        if(right!=-1)
            rooms[i].setRightRoom(&rooms[right]);

        irooms >> obj_num;
        if(obj_num==0){
            vector<Object*>object(0);
            rooms[i].setObjects(object);
        }
        for(int j=0;j<obj_num;j++){
            irooms >> tag;
            if(tag == "Item"){
                irooms >> i_name >> i_health >> i_attack >> i_defense;
                Item* item = new Item(i_name,i_health,i_attack,i_defense);
                obj.push_back(item);
                rooms[i].setObjects(obj);
            }

            if(tag == "Monster"){
                irooms >> m_name >> m_currenthealth >> m_attack >> m_defense;
                Monster* monster = new Monster(m_name,m_currenthealth,m_attack,m_defense);
                obj.push_back(monster);
                rooms[i].setObjects(obj);
            }

            if(tag == "NPC"){
                irooms >> n_name >> n_script;
                irooms >> inventory_num;
                vector<Item> itemvector;
                for(int k=0;k<inventory_num;k++){
                    irooms >> inventory_name >> inventory_health >> inventory_attack >> inventory_defense;
                    Item item(inventory_name,inventory_health,inventory_attack,inventory_defense);
                    itemvector.push_back(item);
                }
                NPC* npc = new NPC(n_name,n_script,itemvector);
                obj.push_back(npc);
                rooms[i].setObjects(obj);
                //itemvector.clear();
            }
        }
    }*/
}

void Record::saveToFile(Player* player, vector<Room>& rooms){
    ofstream oplayer("player_record.txt");
    ofstream orooms("rooms_record.txt");
    savePlayer(player,oplayer);
    saveRooms(rooms,orooms);
}

void Record::loadFromFile(Player* player, vector<Room>& rooms){
    ifstream iplayer("player_record.txt");
    ifstream irooms("rooms_record.txt");
    loadPlayer(player,iplayer);
    loadRooms(rooms,irooms);
    player->setCurrentRoom(&rooms[currentroom]);
    player->setPreviousRoom(&rooms[previousroom]);
}


