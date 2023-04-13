#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "NODE.h"
#include "LL.h"
//#include "BOSS.h"

void BOSS::boss_status() {
    cout << " ================================== " << endl; 
    cout << " ********* BOSS APPEARED ********** " << endl;
    cout << " HP : " << hp << endl;
    cout << " Attack : " << atk << endl; 
    cout << " Potion : " << potion << endl;
    cout << " Status : " << "ALIVE" << endl;
    cout << " ================================== " << endl; 
}

BOSS::~BOSS() {
    cout << " ================================== " << endl; 
    cout << " ********* BOSS DISAPPEARED ********** " << endl;
    cout << " HP : " << hp << endl;
    cout << " Attack : " << atk << endl; 
    cout << " Potion : " << potion << endl;
    cout << " Status : " << "DELETED" << endl;
    cout << " ================================== " << endl; 
}

bool LL::is_boss_dead() {
    NODE_monster* temp = head; 
    while(temp != NULL) {
        if(temp->mons_name() == "BOSS" && temp->is_dead()) {
            return true;
        }
        temp = temp->move_next(); 
    }
    return false;
}

bool LL::is_everymons_die_in_raid() {

    NODE_monster* current = head;
    int num_monsters_defeated = 0;

    while (current != NULL) {

        if (current->mons_name() != "BOSS" && !current->is_dead()) {
            return false;
        } else if (current->mons_name() != "BOSS" && current->is_dead()) {
            num_monsters_defeated++;
        } /*else if (current->mons_name() == "BOSS" && !current->is_dead()) {
            return false;
        }*/
        current = current->move_next();
    }
    
    return num_monsters_defeated == size - 1;
}

void LL::boss_attack_all(LL &mons) {
    NODE_monster* monster = head;

    srand(time(NULL)); 

    int boss_dmg = rand()%10 + 25; 
    while(monster != NULL) {
      if(monster->mons_name() == "BOSS" && !monster->is_dead()) {
         break;
      }
      else if(monster->mons_name() != "BOSS" && !monster->is_dead()) {
        monster->attack_manip("BOSS",boss_dmg);
        if(monster->is_dead()) monster->mons_dead(); 
      }
      monster = monster->move_next();
    }
    cout << " =============== URGENT ================ " << endl;
    cout << " BOSS ATTACK EVERY MONSTER BY AMOUNT : " << boss_dmg << endl;
    monster = mons.to_head();
}

void LL::all_attack_boss(LL& mons) {

    NODE_monster* monster = head;
    NODE_monster* boss = tail;

    // ** GOING TO FIND BOSS NODE ** 
    NODE_monster* current = mons.to_head();
    cout << " ========== UNITED MONSTER ============= " << endl;
    cout << " =========! ATTACK TO BOSS !=========== " << endl;

    while (current != NULL) {
    // ** IF FIND BOSS **
        if(current->mons_name() == "BOSS") {
            boss = static_cast<BOSS*>(current);
            break;
        }
        current = current->move_next();
    }

    // ** IF BOSS NOT FOUND , RETURN VOID
    if(boss == NULL) {
        cout << "Boss not found" << endl;
        return;
    }

    // ** ATTACK TO BOSS ** 
    while(monster != NULL) {
        if (monster->is_dead()) {
            monster = monster->move_next();
            continue;
        }

        if(monster != boss && monster->mons_name() != "BOSS") {
            int hp_boss1 = boss->mons_hp();
            boss->attack_manip("BOSS", rand()%10 + 10);
            int hp_boss2 = boss->mons_hp();
            cout << " BOSS WAS ATTACKED BY " << monster->mons_name() << " AMOUNT : " << hp_boss1 - hp_boss2 << endl;
        }

        monster = monster->move_next();
    }
    monster = mons.to_head();
}


