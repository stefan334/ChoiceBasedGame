
#ifndef PLAYER_H
#define PLAYER_H
#include <cstring>
#include <iostream>

using namespace std;

class player
{

    public:
    int player_hp;
    float player_dmg;
   player();
      void set_name();
      string name;
      void get_name();

};

#endif // PLAYER_H
