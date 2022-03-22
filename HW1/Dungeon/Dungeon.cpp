#include <iostream>
#include <vector>
#include <string>
#include "Dungeon.h"
using namespace std;

Dungeon::Dungeon(){}

void Dungeon::createPlayer(){
    string name;
    int ans;
    cout << "Enter your name: " << endl;
    cin >> name;
    cout << endl;
    cout << "[Choose the character]" << endl;
    cout << "   1. Villager  [ Maxhealth=100, Attack=100, Defense=10, Money=100 ]" << endl;
    cout << "   2. Seer      [ Maxhealth=100, Attack=150, Defense=10, Money=120 ]" << endl;
    cout << "   3. Hunter    [ Maxhealth=150, Attack=100, Defense=10, Money=100 ]" << endl;
    cout << "   4. Witch     [ Maxhealth=150, Attack= 50, Defense=10, Money=120 ]" << endl;
    cin >> ans;
    cout << endl;
    switch(ans){
        case 1:
            player = Player(name,100,100,10,100);
            break;
        case 2:
            player = Player(name,100,150,10,120);
            break;
        case 3:
            player = Player(name,150,100,10,100);
            break;
        case 4:
            player = Player(name,150,50,10,120);
            break;
    }
}

void Dungeon::createMap(){
    int roomnum = 10;
    vector<Object*> obj0,obj1,obj2,obj3,obj4,obj5,obj6,obj7,obj8,obj9;
    vector<Item> item0,item2,item5,item8;
    for(int i=0; i<roomnum; i++){
        Room r;
        r.setIndex(i);
        rooms.push_back(r);
    }

    Item* Jelly = new Item("Jelly",50,-10,-10,0);
    Item* Dizzing_Glasses = new Item("Dizzing_Glasses",10,10,10,0);
    Item* Magicball = new Item("Magicball",40,-10,0,0);
    Item* Airplane = new Item("Airplane",0,0,10,0);
    Item* Mask = new Item("Mask",30,-10,10,0);
    Item* Helmet = new Item("Helmet",20,10,0,0);
    Item* Shield = new Item("Shield",0,10,20,0);
    Item* Parachute = new Item("Parachute",-20,40,10,0);
    Item* Sword = new Item("Sword",0,30,0,0);
    Item* Arrow = new Item("Arrow",-30,50,10,0);
    Item* Stick = new Item("Stick",10,40,-20,0);
    Item* Grenade = new Item("Grenade",10,0,10,0);

    Item* Machin_Gun = new Item("Machin_Gun",-10,-20,-10,100);
    Item* Shotgun = new Item("Shotgun",-20,-10,10,30);
    Item* Assault_Rifle = new Item("Assault_Rifle",40,-20,10,-30);
    Item* Medcine = new Item("Medcine",50,-10,-10,-50);
    Item* Potion = new Item("Potion",40,-10,-10,-20);
    Item* Nurse = new Item("Nurse",100,0,0,-100);
    Item* Handgun = new Item("Handgun",10,30,10,-70);
    Item* Bubblegun = new Item("Bubblegun",0,-40,-10,50);
    Item* Broom = new Item("Broom",-30,50,-10,-10);
    Item* Cookie = new Item("Cookie",-30,30,10,-30);
    Item* Can = new Item("Can",0,30,10,-60);
    Item* Milk = new Item("Milk",-20,-10,-10,60);


    obj0.push_back(Arrow);
    obj1.push_back(Jelly);
    obj2.push_back(Helmet);
    obj3.push_back(Dizzing_Glasses);
    obj4.push_back(Shield);
    obj4.push_back(Grenade);
    obj5.push_back(Magicball);
    obj5.push_back(Parachute);
    obj7.push_back(Airplane);
    obj7.push_back(Mask);
    obj7.push_back(Stick);
    obj8.push_back(Sword);

    item0.push_back(*Handgun);
    item0.push_back(*Bubblegun);
    item0.push_back(*Broom);
    item2.push_back(*Can);
    item2.push_back(*Milk);
    item2.push_back(*Cookie);
    item5.push_back(*Assault_Rifle);
    item5.push_back(*Shotgun);
    item5.push_back(*Machin_Gun);
    item8.push_back(*Nurse);
    item8.push_back(*Potion);
    item8.push_back(*Medcine);

    NPC* Lon = new NPC("Lon","GOGO! Follow me! Let's kill them all!",item0);
    NPC* Pipi = new NPC("Pipi","Wong! Wong!",item2);
    NPC* Soldier = new NPC("Soldier","Hey ,I can share you guys some gun.",item5);
    NPC* Doctor = new NPC("Doctor","Hello! May I help you?",item8);

    obj0.push_back(Lon);
    obj2.push_back(Pipi);
    obj5.push_back(Soldier);
    obj8.push_back(Doctor);

    Monster* Butterfly = new Monster("Butterfly",50,50,10,0);
    Monster* Housefly = new Monster("Housefly",150,100,10,0);
    Monster* Dragonfly = new Monster("Dragonfly",150,100,10,0);
    Monster* Firefly = new Monster("Firefly",150,150,15,0);
    Monster* Boss_Rose = new Monster("Rose",200,200,20,0);

    obj1.push_back(Butterfly);
    obj3.push_back(Housefly);
    obj6.push_back(Dragonfly);
    obj8.push_back(Firefly);
    obj9.push_back(Boss_Rose);

    rooms[0] = Room(false,0,obj0);
    rooms[1] = Room(false,1,obj1);
    rooms[2] = Room(false,2,obj2);
    rooms[3] = Room(false,3,obj3);
    rooms[4] = Room(false,4,obj4);
    rooms[5] = Room(false,5,obj5);
    rooms[6] = Room(false,6,obj6);
    rooms[7] = Room(false,7,obj7);
    rooms[8] = Room(false,8,obj8);
    rooms[9] = Room(true,9,obj9);

    rooms[0].setRightRoom(&rooms[1]);
    rooms[1].setLeftRoom(&rooms[0]);
    rooms[1].setDownRoom(&rooms[2]);
    rooms[2].setUpRoom(&rooms[1]);
    rooms[2].setDownRoom(&rooms[3]);
    rooms[3].setUpRoom(&rooms[2]);
    rooms[3].setLeftRoom(&rooms[4]);
    rooms[3].setRightRoom(&rooms[5]);
    rooms[4].setRightRoom(&rooms[3]);
    rooms[5].setLeftRoom(&rooms[3]);
    rooms[5].setUpRoom(&rooms[6]);
    rooms[6].setDownRoom(&rooms[5]);
    rooms[6].setUpRoom(&rooms[7]);
    rooms[6].setRightRoom(&rooms[8]);
    rooms[7].setDownRoom(&rooms[6]);
    rooms[8].setLeftRoom(&rooms[6]);
    rooms[8].setRightRoom(&rooms[9]);
    rooms[9].setLeftRoom(&rooms[8]);
}

void Dungeon::handleMovement(){
    int ans;
    cout << "[Choose the direction]" << endl;
    switch(player.getCurrentRoom()->getIndex()){
        case 0:
            while(1){
                cout << "   1.go right" << endl;
                cin >> ans;
                cout << endl;
                if(ans == 1){
                    player.changeRoom(player.getCurrentRoom()->getRightRoom());
                    break;
                }
                else
                    continue;
            }
            break;

        case 1:
            while(1){
                cout << "   1.go left " << endl;
                cout << "   2.go down" << endl;
                cin >> ans;
                cout << endl;
                if(ans == 1){
                    player.changeRoom(player.getCurrentRoom()->getLeftRoom());
                    break;
                }
                else if(ans == 2){
                    player.changeRoom(player.getCurrentRoom()->getDownRoom());
                    break;
                }
                else
                    continue;
            }
            break;

         case 2:
            while(1){
                cout << "   1.go up" << endl;
                cout << "   2.go down" << endl;
                cin >> ans;
                cout << endl;
                if(ans == 1){
                    player.changeRoom(player.getCurrentRoom()->getUpRoom());
                    break;
                }
                else if(ans == 2){
                    player.changeRoom(player.getCurrentRoom()->getDownRoom());
                    break;
                }
                else
                    continue;
            }
            break;

         case 3:
             while(1){
                cout << "   1.go up" << endl;
                cout << "   2.go left" << endl;
                cout << "   3.go right" << endl;
                cin >> ans;
                cout << endl;
                if(ans == 1){
                    player.changeRoom(player.getCurrentRoom()->getUpRoom());
                    break;
                }
                else if(ans == 2){
                    player.changeRoom(player.getCurrentRoom()->getLeftRoom());
                    break;
                }
                else if(ans == 3){
                    player.changeRoom(player.getCurrentRoom()->getRightRoom());
                    break;
                }
                else
                    continue;
            }
            break;

            case 4:
                while(1){
                    cout << "   1.go right" << endl;
                    cin >> ans;
                    cout << endl;
                    if(ans == 1){
                        player.changeRoom(player.getCurrentRoom()->getRightRoom());
                        break;
                    }
                    else
                        continue;
                }
                break;

            case 5:
                while(1){
                    cout << "   1.go left" << endl;
                    cout << "   2.go up" << endl;
                    cin >> ans;
                    cout << endl;
                    if(ans == 1){
                        player.changeRoom(player.getCurrentRoom()->getLeftRoom());
                        break;
                    }
                    else if(ans == 2){
                        player.changeRoom(player.getCurrentRoom()->getUpRoom());
                        break;
                    }
                    else
                        continue;
                }
                break;

            case 6:
                while(1){
                    cout << "   1.go down" << endl;
                    cout << "   2.go up" << endl;
                    cout << "   3.go right" << endl;
                    cin >> ans;
                    cout << endl;
                    if(ans == 1){
                        player.changeRoom(player.getCurrentRoom()->getDownRoom());
                        break;
                    }
                    else if(ans == 2){
                        player.changeRoom(player.getCurrentRoom()->getUpRoom());
                        break;
                    }
                    else if(ans == 3){
                        player.changeRoom(player.getCurrentRoom()->getRightRoom());
                        break;
                    }
                    else
                        continue;
                }
                break;

            case 7:
                while(1){
                    cout << "   1.go down" << endl;
                    cin >> ans;
                    cout << endl;
                    if(ans == 1){
                        player.changeRoom(player.getCurrentRoom()->getDownRoom());
                        break;
                    }
                    else
                        continue;
                }
                break;

            case 8:
                while(1){
                    cout << "   1.go left" << endl;
                    cout << "   2.go right" << endl;
                    cin >> ans;
                    cout << endl;
                    if(ans == 1){
                        player.changeRoom(player.getCurrentRoom()->getLeftRoom());
                        break;
                    }
                    else if(ans == 2){
                        player.changeRoom(player.getCurrentRoom()->getRightRoom());
                        break;
                    }
                    else
                        continue;
                }
                break;

            case 9:
                while(1){
                    cout << "  1.go left" << endl;
                    cin >> ans;
                    cout << endl;
                    if(ans == 1){
                        player.changeRoom(player.getCurrentRoom()->getLeftRoom());
                        break;
                    }
                    else
                        continue;
                }
                break;
    }
}

void Dungeon::handleEvent(Object* obj){
    if(Item* item = dynamic_cast<Item*>(obj)){
        if(item->triggerEvent(&player)){
            player.getCurrentRoom()->popObject(item);
        }
    }
    if(Monster* monster = dynamic_cast<Monster*>(obj)){
        if(monster->triggerEvent(&player)){
            if(!checkGameLogic()){
                cout << endl << "GAME OVER" << endl;
                Sleep(5000);
                exit(1);
            }
            player.getCurrentRoom()->popObject(monster);
        }
        else
            return chooseAction(player.getCurrentRoom()->getObjects());
    }

    if(NPC* npc = dynamic_cast<NPC*>(obj)){
        npc->triggerEvent(&player);
    }
}

void Dungeon::startGame(){
    int ans;
    cout << "----------[ Welcome ]----------" << endl << endl;
    cout << "1.New Game   2.Load previous save" << endl;
    cin >> ans;
    cout << endl;
    if(ans == 1){
        createPlayer();
        createMap();
        player.setCurrentRoom(&rooms[0]);
    }
    else if(ans == 2){
        createMap();
        Record record;
        record.loadFromFile(&player,rooms);
    }

}

void Dungeon::chooseAction(vector<Object* >obj){
    if(!obj.empty()){
        int ans;
        int save;
        for(int i=0;i<obj.size();i++){
            if(Monster* monster = dynamic_cast<Monster*>(obj[i])){
                handleEvent(obj[i]);
            }
        }
        cout << "[Choose the action]" << endl;
        cout << "   1.Check the status" << endl;
        cout << "   2.Move to the other room" << endl;
        cout << "   3.Logout" << endl;
        for(int i=0;i<obj.size();i++){
            if(Item* item = dynamic_cast<Item*>(obj[i]))
                cout << "   " << i+4 << ".Pick up the item: " << item->getName() << endl;
            if(NPC* npc = dynamic_cast<NPC*>(obj[i]))
                cout << "   " << i+4 << ".Talk to the NPC: " << npc->getName() << endl;
        }
        cin >> ans;
        cout << endl;
        switch(ans){
            case 1:
                player.triggerEvent(&player);
                break;
            case 2:
                handleMovement();
                break;
            case 3:
                cout << "Do you want to save the file? [ 1.yes / 2.no ]" << endl;
                cin >> save;
                cout << endl;
                if(save == 1){
                    Record record;
                    record.saveToFile(&player,rooms);
                    exit(1);
                }
                else if(save == 2)
                    exit(1);
            case 4:
                handleEvent(obj[0]);
                break;
            case 5:
                handleEvent(obj[1]);
                break;
            case 6:
                handleEvent(obj[2]);
                break;
        }
    }
    else if(obj.empty()){
        cout << "---The room is empty. Go to the other room.---" << endl;
        handleMovement();
    }
}

bool Dungeon::checkGameLogic(){
    if(player.getCurrentHealth()<=0)
        return false;
    else
        return true;
}

void Dungeon::runDungeon(){
    startGame();
    while(checkGameLogic()){
        chooseAction(player.getCurrentRoom()->getObjects());
    }
}
