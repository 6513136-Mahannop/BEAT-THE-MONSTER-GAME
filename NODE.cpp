#include <iostream>
#include <ctime> 

using namespace std;

#include "NODE.h"
#include "LL.h"

NODE_monster::NODE_monster(string name,int hp,int atk,int potion) {
      this->name = name;
      this->hp = hp;  
      this->atk = atk; 
      this->potion = potion;
      next = NULL;
      cout << " ================================== " << endl; 
      cout << " The monster is : " << name << endl;
      cout << " HP : " << hp << endl;
      cout << " Attack : " << atk << endl; 
      cout << " Potion : " << potion << endl;
      cout << " Status : " << "ALIVE" << endl;
      cout << " ================================== " << endl; 
}

NODE_monster::~NODE_monster(){
      cout << " ********************************** " << endl; 
      cout << " THE MONSTER IS : " << name << endl;
      cout << " HP : " << hp << endl;
      cout << " Attack : " << atk << endl; 
      cout << " Potion : " << potion << endl;
      cout << "    !!!! WAS DELETED !!!!    " << endl;   
      cout << " ********************************* " << endl; 
      cout << endl;
}

NODE_monster* NODE_monster::move_next() {
      return next;
}

bool NODE_monster::find_name(string name) {
      return this->name == name;
}

void NODE_monster::display() { 
      if(is_dead()) {
      cout << " ================================== " << endl; 
      cout << " THE MONSTER IS : " << name << endl;
      cout << " HP : " << "0" << endl;
      cout << " Attack : " << atk << endl; 
      cout << " Potion : " << potion << endl;
      cout << " STATUS : " << "DEAD" << endl; 
      cout << " ================================== " << endl; 
      }
      else {
      cout << " ================================== " << endl; 
      cout << " The monster is : " << name << endl;
      cout << " HP : " << hp << endl;
      cout << " Attack : " << atk << endl; 
      cout << " Potion : " << potion << endl;
      cout << " STATUS : " << "ALIVE" << endl; 
      cout << " ================================== " << endl;
      }

}

void NODE_monster::summon(NODE_monster*& x){
      x->next = this;
}

bool NODE_monster::is_dead() {
      return this->hp <= 0; 
}

void NODE_monster::mons_dead() {
     if(is_dead()) {
         cout << " *********************************** " << endl;
         cout << " " << name << " WAS DIED " << endl;
         cout << " *********************************** " << endl;
     }
}

string NODE_monster::mons_name() {
      return this->name; 
}

int NODE_monster::mons_hp() {
      return this->hp;
}

void NODE_monster::deducted_potion() {
      this->potion = potion - 1;
}

bool NODE_monster::is_potion() {
      return this->potion > 0;
}

void NODE_monster::out_of_potion() {
      if(!(is_potion())) {
      cout << " *********************************** " << endl;
      cout << " " << name << " OUT OF POTION " << endl;
      cout << " *********************************** " << endl;
      }
}

void NODE_monster::set_next(NODE_monster* node) {
     next = node;
}
