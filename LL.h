#include "BOSS.h"

class LL{
   private: //private by default if it's invisible
      NODE_monster* head; //head of linked list 
      NODE_monster* tail;
      int size; //size of linked list 
   public:
       void add_node(NODE_monster*&);
       void show_all();
       NODE_monster* to_head();
       NODE_monster* move_to_id(int num);
       void monster_manip(LL &); 
       void printlist_pass_away();
       bool is_everymons_die();
       bool is_everymons_die_in_raid();
       bool is_boss_dead(); 
       int get_count();
       void add_boss();
       void boss_attack_all(LL &mons); //boss attack all monster 
       void all_attack_boss(LL &mons); //all monster attack to boss
      ~LL();
       LL();     
};
