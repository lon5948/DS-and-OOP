#include <iostream>
#include <string>
#include <vector>
#include "Dungeon.h"
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "Player.h"
#include "Object.h"

using namespace std;

int main(){
    Dungeon finish = Dungeon();
    finish.runDungeon();
    return 0;
}
