#include <bits/stdc++.h>
using namespace std;


struct monster {
    string name;
    int strength;
    int defense;
    int health;
    string atack;
    int progressMultiplier;
    int coins;
};


//Tipos de monstro;
monster thief;
monster dragon;
monster golem;
monster knight;
monster angel;
monster living_wall;
monster blob;
monster Knight;
monster demon;
monster puppet;
monster vampire;
monster werewolf;
monster living_furniture;
monster giant_mouse;



void generateRandomMonster(bool isBoss, int gameProgressMultiplyer)