#include <iostream>
#include <string>
#include <vector>
#include "Object.h"

Object::Object(){}

Object::Object(string name,string tag){
    this->name = name;
    this->tag = tag;
}

void Object::setName(string name){
    this->name = name;
}

void Object::setTag(string tag){
    this->tag = tag;
}

string Object::getName(){
    return this->name;
}

string Object::getTag(){
    return this->tag;
}
