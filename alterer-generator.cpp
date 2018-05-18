#include <bits/stdc++.h>
using namespace std;

// Alterers are adjectives
// Change armor, weapons and monsters
// The set of items alterers are different from the monster alterers
struct alterer {
    string text;
    int strength;
    int defense;
    int health;
};

// defautl: there is as much for monsters as for weapons and armor
alterer default_;

// Types of alterers for items
// Positive alterers
alterer enraged;// +atk
alterer shiny;// +health
alterer tought;// +def
alterer legendary;// +atk, +def, +health

// Negative alterers
alterer irreparable;// -atk, -def, -health
alterer weak;// -def
alterer dirty;// -health
alterer soft;// -atk

alterer item_alterer[9] = {enraged, shiny, tought, legendary, irreparable, weak, dirty, soft, default_};

// Types of alterers for monsters
// Positive alterers
alterer invisible;
alterer gigantic;
alterer three_headed;
alterer terrifying;
alterer hairy;
alterer stony;
alterer murderer;

// Negative alterers
alterer pacifist;
alterer dumb;
alterer blind;
alterer imaginary;
alterer legless;

alterer monster_alterer[13] = {pacifist, dumb, blind, imaginary, legless,
    invisible, gigantic, three_headed, terrifying, hairy, stony, murderer, default_};

alterer get_random_item_alterer() {
    int random = rand() % 9;
    return item_alterer[random];
}

alterer get_random_monster_alterer() {
    int random = rand() % 13;
    return monster_alterer[random];
}

void generate_generic_alterer(alterer &a) {
    a.text = "text";
    a.strength = 10;
    a.defense = 11;
    a.health = 12;
}

void generate_all_alterers() {
    for (int i = 0; i < 9; i++) {
        generate_generic_alterer(item_alterer[i]);
    }
    for (int i = 0; i < 13; i++) {
        generate_generic_alterer(monster_alterer[i]);
    }
}