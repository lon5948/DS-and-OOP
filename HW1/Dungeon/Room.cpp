#include <iostream>
#include <string>
#include <vector>
#include "Room.h"

Room::Room(){}

Room::Room(bool isExit,int index,vector<Object*> objects){

    this->isExit = isExit;
    this->index = index;
    this->objects = objects;
    this->upRoom = nullptr;
    this->downRoom = nullptr;
    this->leftRoom = nullptr;
    this->rightRoom = nullptr;
}

bool Room::popObject(Object* obj){
    for(int i=0;i<objects.size();i++){
        if(obj->getName()==objects[i]->getName()){
            objects.erase(objects.begin()+i);
        }
    }
}


void Room::setUpRoom(Room* upRoom){
    this->upRoom = upRoom;
}

void Room::setDownRoom(Room* downRoom){
    this->downRoom = downRoom;
}

void Room::setLeftRoom(Room* leftRoom){
    this->leftRoom = leftRoom;
}

void Room::setRightRoom(Room* rightRoom){
    this->rightRoom = rightRoom;
}

void Room::setIsExit(bool isExit){
    this->isExit = isExit;
}

void Room::setIndex(int index){
    this->index = index;
}

void Room::setObjects(vector<Object*> objects){
    this->objects = objects;
}

bool Room::getIsExit(){
    return this->isExit;
}

int Room::getIndex(){
    return this->index;
}

vector<Object*> Room::getObjects(){
    return this->objects;
}

Room* Room::getUpRoom(){
    return this->upRoom;
}

Room* Room::getDownRoom(){
    return this->downRoom;
}

Room* Room::getLeftRoom(){
    return this->leftRoom;
}

Room* Room::getRightRoom(){
    return this->rightRoom;
}
