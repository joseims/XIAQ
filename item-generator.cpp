#include <bits/stdc++.h>
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

item weapons[4] = {sword,mace,gauntlet,sword_shield};


// Types of armors
item light_armor;// +health
item medium_armor;// +health, +def
item heavy_armor;// +def
item spikey_armor;// +atk, +def
item kimono;// +atk, +health

item armors[5] = {light_armor,medium_armor,heavy_armor,spikey_armor,kimono};

// Initial
item stick;// Initial weapon
item potato_sack;// Initial armor

item get_random_weapon() {
    int random = rand() % 4;
    return weapons[random];
}

item get_random_armor() {
    int random = rand() % 5;
    return armors[random];
}

int multiplyer_item(int attribute, int gameProgressMultiplyer) {
    return attribute * gameProgressMultiplyer;
}

item join_item_alterer(item i, alterer a, int gameProgressMultiplyer) {
    item new_item;
    new_item.name = i.name + " " + a.text;
    new_item.strength = multiplyer_item((i.strength + a.strength), gameProgressMultiplyer);
    new_item.defense = multiplyer_item((i.defense + a.defense), gameProgressMultiplyer);
    new_item.health = multiplyer_item((i.health + a.health), gameProgressMultiplyer);
    new_item.attack = i.attack + " " + a.text;
    new_item.type = i.type;
    new_item.price = multiplyer_item(i.price, gameProgressMultiplyer);
    return new_item;
}

item generate_weapon(int gameProgressMultiplyer) {
    item random_weapon = get_random_weapon();
    alterer random_alterer = get_random_item_alterer();
    return join_item_alterer(random_weapon, random_alterer, gameProgressMultiplyer);
}

item generate_armor(int gameProgressMultiplyer) {
    item random_armor = get_random_armor();
    alterer random_alterer = get_random_item_alterer();
    return join_item_alterer(random_armor, random_alterer, gameProgressMultiplyer);
}

item generate_randItem(int gameProgressMultiplyer) {
    int random = rand() % 1;
    if (random) return generate_weapon(gameProgressMultiplyer);
    else return generate_armor(gameProgressMultiplyer);
}

void generate_generic_item(item &i) {
    i.name = "name";
    i.strength = 10;
    i.defense = 11;
    i.health = 12;
    i.attack = "attack";
    i.type = "type";
    i.price = 13;
}

void generate_all_items() {
    for (int i = 0; i < 4; i++) {
        generate_generic_item(weapons[i]);
    }
    for (int i = 0; i < 5; i++) {
        generate_generic_item(armors[i]);
    }
}