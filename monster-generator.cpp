#include <bits/stdc++.h>
using namespace std;
#include "alterer-generator.cpp"

struct monster {
    string name;
    int strength;
    int defense;
    int health;
    string attack;
    int progressMultiplier;
    int coins;
};


//Tipos de monstro;
monster thief;
monster dragon;
monster golem;
monster blob;
monster vampire;
monster werewolf;
monster giant_mouse;

monster monsters[7] = {thief,dragon,golem,blob,vampire,werewolf,giant_mouse};



void generate_random_monster(bool is_boss, int game_progress_multiplyer) {
}