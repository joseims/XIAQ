#ifndef MONSTER_CPP
#define MONSTER_CPP
#include "alterer-generator.cpp"
using namespace std;

struct monster {
    string name;
    int strength;
    int defense;
    int health;
    string attack;
    int progress_multiplier;
    int coins;
};

// Types of monsters
monster thief;
monster dragon;
monster golem;
monster blob;
monster vampire;
monster werewolf;
monster giant_mouse;

const int N_MONSTERS = 7;
monster monsters[N_MONSTERS] = {thief, dragon, golem, blob, vampire, werewolf, giant_mouse};

monster get_random_monster() {
    int random = rand() % N_MONSTERS;
    return monsters[random];
}

int multiplyer_monster(int attribute, int game_progress_multiplier) {
    return attribute   + (attribute * game_progress_multiplier)/10;
}

monster join_monster_alterer(monster m, alterer a, int game_progress_multiplier) {
    monster new_monster;
    new_monster.name = m.name + " " + a.text;
    new_monster.strength = multiplyer_monster((m.strength + a.strength), game_progress_multiplier);
    new_monster.defense = multiplyer_monster((m.defense + a.defense), game_progress_multiplier);
    new_monster.health = multiplyer_monster((m.health + a.health), game_progress_multiplier);
    new_monster.attack = m.attack + " " + a.text;
    new_monster.progress_multiplier = m.progress_multiplier;
    new_monster.coins = multiplyer_monster(m.coins, game_progress_multiplier);
    return new_monster;
}

monster generate_monster(bool isBoss, int game_progress_multiplier) {
    monster random_monster = get_random_monster();
    alterer alterer_monster = get_random_monster_alterer();
    return join_monster_alterer(random_monster, alterer_monster, game_progress_multiplier);
}

// For temporary testing until we have defined the final values
void generate_generic_monster(monster *m) {
    m->name = "name";
    m->strength = 10 + (rand() % 5);
    m->defense = 10 + (rand() % 5);
    m->health = 10 + (rand() % 5);
    m->attack = "attack";
    m->progress_multiplier = 10 + (rand() % 5);
    m->coins = 10 + (rand() % 5);
}

void generate_all_monsters() {
    for (int i = 0; i < N_MONSTERS; i++) {
        generate_generic_monster(&monsters[i]);
    }
}

#endif