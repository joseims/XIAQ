#include <bits/stdc++.h>
using namespace std;
#include "item-generator.cpp"

//representação do personagem
//os atributos dele em geral são 
struct main_character {
    int strength;
    int defense;
    int health;
    int maxHealth;
    item weapon;
    item armor;
    int game_progress_multiplyer;
    int coins;
    int potion;
};