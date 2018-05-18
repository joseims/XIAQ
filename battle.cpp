#include <bits/stdc++.h>
#include "main-character.cpp"
#include "monster-generator.cpp"

using namespace std;

struct hero_in_battle {
    main_character hero;
    int consecutive_defending;
    // The hero in battle also has another attribute to 
    // check whatever was his last action. But, this
    // attribute can be derive from the consecutive 
    // rounds defending: if > 0, last action was a defense
};

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

int get_battle_action() {
    int action;
    cout << "Choose your action:" << endl;
    cout << "1 for Attack, 2 for Defend, 3 for Super Attack" << endl;
    cout << "Action: ";
    cin >> action;
    cout << endl;
}

int hero_attacks(hero_in_battle hero, monster enemy) {
    int action;

    while (1) {
        action = get_battle_action();
        if (action == 1) {
            enemy.health -= hero.hero.strength;
            return 1;
        } else if (action == 3) {
            if (hero.consecutive_defending > 2) {
                enemy.health -= hero.hero.strength * 3;
                hero.consecutive_defending -= 3;
                return 1;
            } else {
                cout << "You cannot use your super attack yet." << endl;
            }
        } else {
            return 0;
        }
    }
}

void monster_attacks(hero_in_battle hero, monster enemy) {
    int damage = enemy.strength;
    if (hero.consecutive_defending > 0) {
        damage -= hero.hero.defense;
    }
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
    hero_in_battle hero_battle;
    hero_battle.hero = hero;
    hero_battle.consecutive_defending = 0;

    int result = coin_toss();
    int round = 1;

    while (hero.health > 0 && enemy.health > 0) {
        
        cout << "THE " << round << term(round) << " ROUND BEGINS!" << endl;
        if (result) {
            hero_attacks(hero_battle, enemy);
            monster_attacks(hero_battle, enemy);
        } else {
            monster_attacks(hero_battle, enemy);
            hero_attacks(hero_battle, enemy);
        }

    }
}