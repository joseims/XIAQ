#ifndef ITEM_CPP
#define ITEM_CPP
#include "alterer-generator.cpp"
using namespace std;

struct item {
    string name;
    int strength;
    int defense;
    int health;
    string attack;
    string type;
    int price;
};

// Types of weapons
item sword;// atk++
item mace;// atk+, health+
item gauntlet;// atk+,def+, health+
item sword_shield;// atk+, def+

const int N_WEAPONS = 4;
item weapons[N_WEAPONS] = {sword,mace,gauntlet,sword_shield};
string weapon_names[N_WEAPONS] = {"Espada", "Maça","Manopla", "Espada e escudo"};

// Types of armors
item light_armor;// +health
item medium_armor;// +health, +def
item heavy_armor;// +def
item spikey_armor;// +atk, +def
item kimono;// +atk, +health

const int N_ARMORS = 5;
item armors[N_ARMORS] = {light_armor,medium_armor,heavy_armor,spikey_armor,kimono};
string armor_names[N_ARMORS] = {"Armadura Leve","Armadura média","Armadura pesada","Armadura espinhosa","Kimono"};

// Initial
item stick;// Initial weapon
item potato_sack;// Initial armor

item get_random_weapon() {
    int random = rand() % N_WEAPONS;
    return weapons[random];
}

item get_random_armor() {
    int random = rand() % N_ARMORS;
    return armors[random];
}

int multiplyer_item(int attribute, int game_progress_multiplier) {
    return attribute * game_progress_multiplier;
}

item join_item_alterer(item i, alterer a, int game_progress_multiplier) {
    item new_item;
    new_item.name = i.name + a.text;
    new_item.strength = multiplyer_item((i.strength + a.strength), game_progress_multiplier);
    new_item.defense = multiplyer_item((i.defense + a.defense), game_progress_multiplier);
    new_item.health = multiplyer_item((i.health + a.health), game_progress_multiplier);
    new_item.attack = i.attack + " " + a.text;
    new_item.type = i.type;
    new_item.price = multiplyer_item(i.price, game_progress_multiplier)/4;
    return new_item;
}

item generate_weapon(int game_progress_multiplier) {
    item random_weapon = get_random_weapon();
    alterer random_alterer = get_random_item_alterer();
    return join_item_alterer(random_weapon, random_alterer, game_progress_multiplier);
}

item generate_armor(int game_progress_multiplier) {
    item random_armor = get_random_armor();
    alterer random_alterer = get_random_item_alterer();
    return join_item_alterer(random_armor, random_alterer, game_progress_multiplier);
}

item generate_rand_item(int game_progress_multiplier) {
    int random = rand() % 2;
    if (random) return generate_weapon(game_progress_multiplier);
    else return generate_armor(game_progress_multiplier);
}

void generate_initial_items() {
    potato_sack.name = "potato_sack";
    potato_sack.strength = 10 + (rand() % 50);
    potato_sack.defense = 10 + (rand() % 50);
    potato_sack.health = 10 + (rand() % 50);
    potato_sack.attack = "attack";
    potato_sack.type = "type";
    potato_sack.price = 10 + (rand() % 5);

    stick.name = "stick";
    stick.strength = 10 + (rand() % 50);
    stick.defense = 10 + (rand() % 50);
    stick.health = 10 + (rand() % 50);
    stick.attack = "attack";
    stick.type = "type";
    stick.price = 10 + (rand() % 5);
}

// For temporary testing until we have defined the final values
item generate_generic_item() {
    item i;
    i.strength = 10 + (rand() % 5);
    i.defense = 10 + (rand() % 5);
    i.health = 10 + (rand() % 5);
    i.attack = "attack";
    i.price = 3;
    return i;
}

void generate_all_items() {
    for (int i = 0; i < N_WEAPONS; i++) {
        item it = generate_generic_item();
        it.type = "weapon";
        it.name = weapon_names[i];
        weapons[i] = it;
    }
    for (int i = 0; i < N_ARMORS; i++) {
        item it = generate_generic_item();
        it.type = "armor";
        it.name = armor_names[i];
        armors[i] = it;
    }
}

#endif