#include <iostream>

using namespace std;

void start_game_display() {
    cout << " ****************************************" << endl;
    cout << " 1) -> START GAME " << endl; 
    cout << " 2) -> STORY OF GAME " << endl; 
    cout << " 3) -> CREDIT " << endl; 
    cout << " 4) -> EXIT " << endl; 
    cout << " 5) -> SPECIAL MESSAGE TO AJ " << endl;
    cout << " ****************************************" << endl;
}

void function_display() {
   cout << " =================================== " << endl; 
   cout << "              FUNCTIONS              " << endl;
   cout << " =================================== " << endl;
   cout << "  1) -> HEALING ? " << endl; 
   cout << "  2) -> ATTACK  ? " << endl; 
   cout << "  3) -> RANDOMIZED MONSTER ? " << endl; 
   cout << "  4) -> MONSTER LIST ? " << endl;
   cout << "  5) -> DIED MONSTER ? " << endl;
   cout << " =================================== " << endl; 
}

void raid_function_display() {
      cout << " =================================== " << endl; 
      cout << "           **** RAID ****            " << endl;
      cout << " =================================== " << endl;
      cout << "  1) -> HEALING MONSTER ? " << endl; 
      cout << "  2) -> ATTACK BOSS  ? " << endl; 
      cout << "  3) -> RANDOMIZED ? " << endl; 
      cout << "  4) -> MONSTER LIST ? " << endl;
      cout << "  5) -> DIED MONSTER ? " << endl;
      cout << " =================================== " << endl; 
}

void raiding_begin() {
     cout << " =================================== " << endl; 
     cout << "            RAIDING BEGIN            " << endl;
     cout << " =================================== " << endl;
}

void story() {
   cout << " ******* THE STORY HERE ******* " << endl;
   cout << " In the last few decades, the stars in the galaxy have been protected by a group of powerful and loyal monsters. These monsters have been able to keep the galaxy safe from any invaders that may want to cause harm." << endl;
   cout << " However, one day, a Gigantic Boss suddenly appeared in the galaxy and began moving towards the star that the monsters were protecting." << endl;
   cout << " The monsters knew that they had to act fast to stop the Gigantic Boss from destroying the star and causing chaos in the galaxy." << endl;
   cout << " They quickly gathered their strength and prepared for battle. The fate of the star and the entire galaxy was now in their hands." << endl;
   cout << " As the Gigantic Boss approached, the monsters charged forward to meet it. The battle was intense, with both sides fiercely attacking each other." << endl;
   cout << " The monsters fought with all their might, determined to protect the star and save the galaxy" << endl;
   cout << " It was a long and grueling battle, but in the end, the monsters emerged victorious. The Gigantic Boss had been defeated, and the star and the galaxy were once again safe." << endl; 
   cout << " The monsters returned to their duties, protecting the galaxy and its stars with renewed vigor and determination. They knew that they would always be ready to fight any invaders that threatened the safety of the galaxy." << endl; 
   cout << " ******* END OF STORY ******* " << endl;
    
}

void who_dev() {
   cout << " ================================== " << endl;
   cout << " THIS GAME WAS CREATED BY PEAM MAHANNOP " << endl;
   cout << " UID : 6513136" << endl; 
   cout << " ================================== " << endl;
}

void out_game() {
   cout << " ================================== " << endl;
   cout << " THANK YOU FOR PLAYING, HAVE A GOOD DAY ! " << endl;
   cout << endl;
   cout << " ================================== " << endl;
}

void wrong_choice() {
   cout << " ================================== " << endl;
   cout << " !!! THE CHOICE DOESN'T EXIST !!!" << endl;
   cout << " ================================== " << endl;
}

void everymons_die_dis() {
   cout << " =================================== " << endl;
   cout << "              GAME OVER              " << endl; 
   cout << "          EVERY MONSTER DIE          " << endl; 
   cout << " =================================== " << endl; 
}

void boss_die_dis() {
   cout << " ================================== " << endl;
   cout << "         *** BOSS DIED ***          " << endl; 
   cout << " ============ YOU WIN =============  " << endl; 
   cout << " ================================== " << endl;
}