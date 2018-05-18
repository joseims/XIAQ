#include <bits/stdc++.h>
#include "main-character.cpp"
#include "monster-generator.cpp"

using namespace std;

int coin_toss() {
    // Method to decide who attacks first
    // Input value

    string chosen;
    cout << "Choose 'heads' or 'tails': ";
    cin >> chosen;
    cout << endl;

    // Calculate result
    // if 1, heads wins

    int result = rand() % 2;
    if (result == 1 && !chosen.compare("heads")) {
        return 1; // Hero won
    } else if (result == 0 && !chosen.compare("tails")) {
        return 1; // Hero won
    } 
    return 0; // Hero lost
}

void hero_attacks(main_character hero, monster enemy) {

}

void monster_attacks(main_character hero, monster enemy) {

}

string term(int round) {
    string terms[4] = {"st", "nd", "rd", "th"};
    if (round > 3) round = 3;
    return terms[round];
}

void initial_message(main_character hero) {
    cout << "THE BATTLE IS ABOUT TO BEGIN!!" << endl;
    cout << "Remember Hero, your status is: " << endl;
    cout << "Attack: " << hero.strength << endl;
    cout << "Defense: " << hero.defense << endl;
    cout << "Health: " << hero.health << "/" << hero.max_health << endl << endl;
}

void battle_workflow(main_character hero, monster enemy) {
    initial_message(hero);

    int result = coin_toss();
    int round = 1;

    while (hero.health > 0 && enemy.health > 0) {
        
        cout << "THE " << round << term(round) << " ROUND BEGINS!" << endl;
        if (result) {
            hero_attacks(hero, enemy);
            monster_attacks(hero, enemy);
        } else {
            monster_attacks(hero, enemy);
            hero_attacks(hero, enemy);
        }

    }
}