#include <bits/stdc++.h>
using namespace std;
#include "weapon-generator.cpp"
#include "main-character"

item itens[3];

void seeStore(main_character character) {
int game_progress_multiplyer = character.gameProgressMultiplyer;
itens[0] = generate_weapon();
itens[1] = generate_armor();

};

void exitStore();

void buyItem(main_character characte, item item);