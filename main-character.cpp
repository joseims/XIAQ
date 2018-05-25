#ifndef CHARACTER_CPP
#define CHARACTER_CPP
#include "item-generator.cpp"
using namespace std;

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

void set_initial_attributes() {
    character.strength = stick.strength + potato_sack.strength;
    character.defense = stick.defense + potato_sack.defense;
    character.health = stick.health + potato_sack.health;
}

void set_initial_items() {
    generate_initial_items();
    character.weapon = stick;
    character.armor = potato_sack;
    set_initial_attributes();
}

#endif