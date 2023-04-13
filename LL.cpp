#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "NODE.h"
#include "LL.h"
//#include "BOSS.h"

LL::LL() { //if not create anything , define the following instruction below
   head = NULL;
   size = 0;
}

LL::~LL() {
   NODE_monster* temp = head; 
   cout << " !! CLEARING SYSTEM !! " << endl;; 
   for(int i=0;i<size;i++) {
      temp = head->move_next(); 
      delete(head); 
      head = temp; 
   } cout << endl; 
   cout << " !! SUCCESSFULLY CLEANED !! " << endl;
   size = 0; 
}

void LL::show_all() {

     NODE_monster* t = head;
     int i;
     
      cout << " ================================== " << endl;
      cout << "            MONSTER LIST            " << endl;
      cout << " ================================== " << endl;
     
     for(i=0;i<size;i++) {
        t->display();
        t=t->move_next();
     } cout << endl; 

}

void LL::printlist_pass_away() {

    NODE_monster *temp = head; 
    bool header_died = false;

    while(temp != NULL) {
        if(temp->is_dead()) {
            if(!header_died) {
                cout << " =================================== " << endl; 
                cout << "             DIED MONSTER           " << endl;
                cout << " =================================== " << endl;
                header_died = true;
                 }
           cout << "  " << temp->mons_name() << " "; 
           }
        temp = temp->move_next(); 
    }
    //cout << endl;

    if (!header_died) {
        cout << " ================================== " << endl; 
        cout << "         !! NO MONSTER DIE !!       " << endl;
        cout << " ================================== " << endl;  
    }
    cout << endl;
}

void LL::add_node(NODE_monster *&new_monster) {
     head->summon(new_monster); //แทรกข้างหน้า hol 
     head = new_monster;
     size++;
 }

void LL::add_boss() {
    NODE_monster* current = head;
    while(current->move_next() != NULL) {
        current = current->move_next();
    }
    BOSS* boss = new BOSS();
    current->set_next(boss); // !!! that was tricky bro, it's worked !!! 
    size++;
}


NODE_monster* LL::move_to_id(int num) {
     NODE_monster* temp = head; 
     for(int i=0;i<num;i++) {
        temp = temp->move_next();
    }
     return temp;
}

NODE_monster* LL::to_head() {
     NODE_monster *temp;
     temp = head;
     return temp;
}

int LL::get_count() {
     return size; 
} 

bool LL::is_everymons_die() {

   NODE_monster *temp = head; 
   while(temp != NULL) {
      if(!(temp->is_dead())) {
           return false; //if any mons wasn't die
      }
      temp = temp->move_next();
   }
   return true; //if all mons die 

}