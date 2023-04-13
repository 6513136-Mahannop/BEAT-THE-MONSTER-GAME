#include <iostream>

using namespace std;

#include "NODE.h"
#include "LL.h"
#include "display.h"
//#include "BOSS.h"
// ./game Peam 50 20 5 Nene 50 20 5 Haerin 50 20 5 Minji 50 20 5 Yujin 50 20 5 
int main(int argc, const char * argv[]) {

    LL mons;
    string u_name;
    int u_hp,u_potion,u_atk;
    NODE_monster *summon;
    BOSS* boss;

    int i,choice,cases,boss_cases,count = 6;
    
    cout << " ==== WELCOME TO BEAT THE MONSTER GAME ==== " << endl;  
    bool DuringGame = true; 
    bool head_died = false;
   
    while(DuringGame != false) {
      //Part of Menu_Game Interface 
      start_game_display(); 
      cout << " Enter Your Choice : " ;
      cin >> choice; 
      //Part of Client is selecting choice 
      switch(choice) {
        case 1: 
           cout << " *** LET'S START *** " << endl;
           for(i=1;i<argc;i+=4) {
             summon = new NODE_monster(argv[i],atoi(argv[i+1]),atoi(argv[i+2]),atoi(argv[i+3])); //create monster 
             mons.add_node(summon); //append Node 
             //attack was set default because equilibrium system
             //temp = summon;
           }
             do{ 
               if(mons.is_everymons_die()) {
                    everymons_die_dis();
                    goto out;
                }
                function_display();
                cout << " SELECT CHOICE : ";
                cin >> cases;
                if(cases == 3) goto rand_monster;
                if(cases == 4) goto show;
                if(cases == 5) goto who_away;
                cout << " SELECT MONSTER : ";
                cin >> u_name;
                cout << " =================================== " << endl;
                switch(cases) {

                    case 1:
                       while(summon != NULL && !head_died) {

                        if(summon->find_name(u_name) && summon->is_potion()) {
                           summon->healing_by_users(u_name,u_hp);
                           if(!summon->is_potion()) summon->out_of_potion();
                           summon = mons.to_head();
                           count--;
                           //cout << " REMAINING : " << count << endl;
                           break;
                        }

                         while(summon && !(summon->find_name(u_name))) {
                            summon = summon->move_next(); 
                          }

                         if(summon && !(summon->is_dead()) && summon->is_potion()) {
                          summon->healing_by_users(u_name,u_hp);
                          if(!summon->is_potion()) summon->out_of_potion();
                          summon = mons.to_head();         
                          count--; 
                          //cout << " REMAINING : " << count << endl;
                          break;
                          } 

                         else if(summon && !(summon->is_dead()) && !summon->is_potion()) {
                            summon->out_of_potion();
                            summon = mons.to_head();
                            break;
                         }

                         else if(summon && summon->is_dead()) { 
                           summon->mons_dead();
                           summon = mons.to_head(); 
                           break; 
                        }

                         else {
                          cout << " *** MONSTER NOT FOUND *** " << endl;
                          summon = mons.to_head();
                         break;
                            }
                          summon->out_of_potion();
                          summon = mons.to_head();
                          break;
                         } 
                    break; 

                    case 2:
                       while(summon != NULL && !mons.is_everymons_die()) {

                        if(summon->find_name(u_name) && !head_died) { //if find the name of monsters 
                           summon->attack_by_users(u_name,u_atk); 
                           if(summon->is_dead()) summon->mons_dead();
                           summon = mons.to_head(); 
                           count--;
                           //cout << " REMAINING : " << count << endl;
                           head_died = true;
                           break;
                          }

                         while(summon && !(summon->find_name(u_name))) {
                             summon = summon->move_next(); 
                             }

                         if(summon && !(summon->is_dead())) {
                            summon->attack_by_users(u_name,u_hp);
                            if(summon->is_dead()) summon->mons_dead();
                            summon = mons.to_head();       
                            count--; 
                            //cout << " REMAINING : " << count << endl;
                            break;
                          } 

                         else if(summon && summon->is_dead()) { 
                           summon->mons_dead();
                           summon = mons.to_head(); 
                           break; }
                         
                         else {
                           cout << " *** MONSTER NOT FOUND *** " << endl;
                           summon = mons.to_head();
                           break;
                            }
                         }

                        break; 

                    case 3: rand_monster:
                        mons.monster_manip(mons); 
                        count--;
                        //cout << " REMAINING : " << count << endl;
                        break; 

                    case 4: show:
                        mons.show_all(); 
                        break;

                    case 5: who_away:
                        mons.printlist_pass_away();
                        break;

                    default: 
                        cout << " ***** INVALID CHOICES *****" << endl;
                        break;
                    } 

              }while(count > 0 && mons.get_count() < 1);
              // boss appeared
                 boss = new BOSS(); 
                 mons.add_boss(); 
                 raiding_begin();
                 boss->boss_status();
     
                do{
                 raid_function_display();
                 cout << " SELECT CHOICE : ";
                 cin >> boss_cases;

                 if(boss_cases == 3) goto rand_boss;
                 if(boss_cases == 4) goto b_show;
                 if(boss_cases == 5) goto b_who_away;

                 switch(boss_cases) {

                       case 1: //selecting heal monster by users
                        cout << " SELECT MONSTER : ";
                        cin >> u_name;
                        cout << " =================================== " << endl;
                        while(summon != NULL && !head_died) {

                        if(summon->find_name(u_name) && summon->is_potion()) {
                           summon->healing_by_users(u_name,u_hp);
                           if(!summon->is_potion()) summon->out_of_potion();
                           summon = mons.to_head();
                           break;
                        }

                         while(summon && !(summon->find_name(u_name))) {
                            summon = summon->move_next(); 
                          }

                         if(summon && !(summon->is_dead()) && summon->is_potion()) {
                          summon->healing_by_users(u_name,u_hp);
                          if(!summon->is_potion()) summon->out_of_potion();
                          summon = mons.to_head();         
                          break;
                          } 

                         else if(summon && !(summon->is_dead()) && !summon->is_potion()) {
                            summon->out_of_potion();
                            summon = mons.to_head();
                            break;
                         }

                         else if(summon && summon->is_dead()) { 
                           summon->mons_dead();
                           summon = mons.to_head(); 
                           break; 
                        }
                         else {
                          cout << " *** MONSTER NOT FOUND *** " << endl;
                          summon = mons.to_head();
                         break;
                            }
                          summon->out_of_potion();
                          summon = mons.to_head();
                          break;
                         } 
                         break;

                       case 2: //all monster attacking boss
                          mons.boss_attack_all(mons);
                          mons.all_attack_boss(mons);
                         break;

                       case 3: rand_boss:
                         mons.monster_manip(mons); 
                           break;

                       case 4: b_show:
                         mons.show_all(); 
                         break;

                       case 5: b_who_away:
                         mons.printlist_pass_away();
                         break;

                       default:
                         cout << " *** INVALID *** " << endl;
                         break;
                   }
                 }while(!mons.is_everymons_die_in_raid() && !mons.is_boss_dead());
                 
                  if(mons.is_boss_dead()) {
                     boss_die_dis(); 
                     goto out; 
                   }
                   else if(mons.is_everymons_die_in_raid()) {
                     everymons_die_dis();
                     goto out;
                   } 

              break;

             case 2: 
             story();
             break;

             case 3: 
             who_dev();
             break;

             case 4: out:
             out_game();
             DuringGame = false;
              break;
             
             case 5: 
              cout << " Could I get extra points ? :) :) :)" << endl;
              break;

             default : 
            wrong_choice();
              break;
      }
    }    
    return 0;
}
