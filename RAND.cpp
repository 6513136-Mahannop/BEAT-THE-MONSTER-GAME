#include <iostream>
#include <ctime> 
#include <cstdlib> 

using namespace std;

#include "NODE.h"
#include "LL.h"

void NODE_monster::healing_manip(string name,int num) {
      this->hp += num; 
}

void NODE_monster::attack_manip(string name,int num) {
      this->hp -= num; 
} 

void LL::monster_manip(LL &mons) {

       int count = mons.get_count();
       if(count == 0) {
            return ;
       }

       srand(time(NULL)); 

       int num_manip = rand() % count; 
       NODE_monster *rand_monster_1 = mons.move_to_id(num_manip); //main monster which randomized
       //case of name monster was repeated
       int action = rand() % 2; //1) Healing 2) Attack

       while(!mons.is_everymons_die()) {
       if(action == 1 && rand_monster_1->is_potion() && !rand_monster_1->is_dead()) {

          int hp_h1 = rand_monster_1->mons_hp();

          rand_monster_1->healing_manip(rand_monster_1->mons_name(),rand()%21 + 10); 

          if(!rand_monster_1->is_potion()) rand_monster_1->out_of_potion();

          int hp_h2 = rand_monster_1->mons_hp();

          rand_monster_1->deducted_potion();

          cout << " " << rand_monster_1->mons_name() << " WAS HEALING ITSELF AMOUNT : " << hp_h2 - hp_h1 << endl; 
          break;
       }

       else { 
            
            if(!rand_monster_1->is_dead()) {
            NODE_monster *rand_monster_2; //case of name monster was repeated 

            do{
               num_manip = rand() % count; 
               rand_monster_2 = mons.move_to_id(num_manip);
            }while(rand_monster_1->mons_name() == rand_monster_2->mons_name() && !rand_monster_2->is_dead()); 
            
            int hp_a1 = rand_monster_1->mons_hp();

            rand_monster_1->attack_manip(rand_monster_1->mons_name(),rand()%21 + 15);

            int hp_a2 = rand_monster_1->mons_hp(); 

            if(!rand_monster_2->is_dead()) cout << " " << rand_monster_1->mons_name() << " WAS ATTACKED BY " << rand_monster_2->mons_name() << " AMOUNT : " << hp_a1 - hp_a2 << endl;
            else rand_monster_2->mons_dead();

            if(rand_monster_1->is_dead()) { rand_monster_1->mons_dead();
               break; }
           }

           else rand_monster_1->mons_dead();  
           rand_monster_1 = mons.to_head(); 
           break;
       }
   }
}



