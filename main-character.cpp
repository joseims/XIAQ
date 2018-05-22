#include <bits/stdc++.h>
using namespace std;
#include "item-generator.cpp"

// Character representation
struct main_character {
    int strength;
    int defense;
    int health;
    int max_health;
    item weapon;
    item armor;
    int game_progress_multiplier;
    int coins;
    int potion;
};

main_character character;
