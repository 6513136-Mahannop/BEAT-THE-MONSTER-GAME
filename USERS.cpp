#include <iostream>
#include <ctime> 
#include <cstdlib> 

using namespace std; 

#include "NODE.h"
#include "LL.h"

void NODE_monster::healing_by_users(string name,int healing_amount) {

      srand(time(NULL));
      healing_amount = rand() % 10 + 15; //range of healing in range 10 - 25
      
      if(this->name == name) {
         hp = hp + healing_amount;
         cout << " HEAL AMOUNT : " << healing_amount << endl; 
         cout << " " << name << " WAS HEALING " << endl;
         potion -= 1;
      }
      else {
         cout << "*** INVALID MONSTER *** " << endl; 
      }
}

void NODE_monster::attack_by_users(string name,int dmg_atk) {

     srand(time(NULL));
     dmg_atk = atk; //range of damage in range 10 - 25

     if(this->name == name) {
         hp = hp - dmg_atk; 
         cout << " ATK AMOUNT : " << dmg_atk << endl;  
         cout << " " << name << " WAS ATTACKING " << endl;
      }
     else {
         cout << " *** INVALID MONSTER *** " << endl;
      }

}
