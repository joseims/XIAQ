#include <bits/stdc++.h>
#include "alterer-generator.cpp"

using namespace std;

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

monster monsters[7] = {thief, dragon, golem, blob, vampire, werewolf, giant_mouse};

monster get_random_monster() {
    int random = rand() % monsters.size();
    return monsters[random];
}

int multiplyer_monster(int attribute, int gameProgressMultiplyer) {
    return attribute * gameProgressMultiplyer;
}

monster join_monster_alterer(monster m, alterer a, int gameProgressMultiplyer) {
    monster new_monster;
    new_monster.name = m.name + " " + a.text;
    new_monster.strength = multiplyer_monster((m.strength + a.strength), gameProgressMultiplyer);
    new_monster.defense = multiplyer_monster((m.defense + a.defense), gameProgressMultiplyer);
    new_monster.health = multiplyer_monster((m.health + a.health), gameProgressMultiplyer);
    new_monster.attack = m.attack + " " + a.text;
    new_monster.progressMultiplier = m.progressMultiplier;
    new_monster.coins = multiplyer_monster(m.cois, gameProgressMultiplyer);
    return new_monster;
}

monster generate_monster(bool isBoss, int gameProgressMultiplyer) {
    monster random_monster = get_random_monster();
    alterer alterer_monster = get_random_monster_alterer();
    return join_monster_alterer(random_monster, alterer_monster, gameProgressMultiplyer);
}