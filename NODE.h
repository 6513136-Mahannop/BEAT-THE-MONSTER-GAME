class NODE_monster{
private : 
      int id; 
protected:
      string name;
      int hp;
      int potion;
      int atk; 
      NODE_monster* next;
public:
      NODE_monster(string="newbie",int=100,int=20,int=5);
      void display();
      void summon(NODE_monster *&);
      void healing_by_users(string,int);
      void attack_by_users(string,int);
      void healing_manip(string,int);
      void attack_manip(string,int);
      bool is_dead();
      void mons_dead();
      string mons_name();
      int mons_hp();
      void deducted_potion();
      bool is_potion();
      void out_of_potion();
      NODE_monster* move_next();
      bool find_name(string s);
      void set_next(NODE_monster* node);
      ~NODE_monster();
};
