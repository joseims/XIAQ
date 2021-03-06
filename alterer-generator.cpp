#ifndef ALTERER_CPP
#define ALTERER_CPP
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

// default: there is as much for monsters as for weapons and armor
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

const int N_ITEMS_ALTERERS = 9;
alterer item_alterer[N_ITEMS_ALTERERS] = {enraged, shiny, tought, legendary, irreparable, weak, dirty, soft, default_};
string item_alterer_names[N_ITEMS_ALTERERS] = {" Furioso", " Brilhante"," Resistente"," Lendário"," Irreparavel"," Fraco"," Sujo"," Macio",""};

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

const int N_MONSTERS_ALTERERS = 13;
alterer monster_alterer[N_MONSTERS_ALTERERS] = {pacifist, dumb, blind, imaginary, legless,
    invisible, gigantic, three_headed, terrifying, hairy, stony, murderer, default_};
string monster_alterer_names[N_MONSTERS_ALTERERS] = {" Pacifista"," Burro"," Cego"," Imaginário"," Sem Pernas", " Invisivel", " Gigantesco",
    " de 3 cabeças", " Aterrorizante"," Cabeludo"," Rochoso"," Assassino", ""};

alterer get_random_item_alterer() {
    int random = rand() % N_ITEMS_ALTERERS;
    return item_alterer[random];
}

alterer get_random_monster_alterer() {
    int random = rand() % N_MONSTERS_ALTERERS;
    return monster_alterer[random];
}

// For temporary testing until we have defined the final values
alterer generate_generic_alterer() {
    alterer a;
    a.strength = 10 + ((rand() % 11) - 5);
    a.defense = 10 + ((rand() % 11) - 5);
    a.health = 10 + ((rand() % 11) - 5);
    return a;
}

void generate_all_alterers() {
    for (int i = 0; i < N_ITEMS_ALTERERS; i++) {
         alterer a = generate_generic_alterer();
         a.text = item_alterer_names[i];
         item_alterer[i] = a;
    }
    for (int i = 0; i < N_MONSTERS_ALTERERS; i++) {
        alterer a = generate_generic_alterer();
        a.text = monster_alterer_names[i];
        monster_alterer[i] = a;
    }   
}

#endif