class BOSS : public NODE_monster { //inheritance from monster 
   private:
     bool flag; //to check the boss was died ? 
   public:
     BOSS(string name="BOSS", int hp=150, int atk=15, int potion=5) 
       : NODE_monster(name, hp, atk, potion), flag(false) {}
     ~BOSS();
     void boss_status();
};