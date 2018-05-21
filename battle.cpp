#include <bits/stdc++.h>
#include "main-character.cpp"
#include "monster-generator.cpp"

using namespace std;

struct in_battle {
    int consecutive_defending;
    // The hero in battle also has another attribute to 
    // check whatever was his last action. But, this
    // attribute can be derive from the consecutive 
    // rounds defending: if > 0, last action was a defense
};

struct hero_in_battle : in_battle {
    main_character hero;
};

struct monster_in_battle : in_battle {
    monster enemy;
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
    cout << "1 for Attack, 2 for Defend, 3 for Super Attack, 4 to use a potion" << endl;
    cout << "Action: ";
    cin >> action;
    cout << endl;
}

int hero_attacks(hero_in_battle hero, monster enemy) {
    int action;

    cout << "Choose your action:" << endl;
    while (1) {
        action = get_battle_action();
        if (action == 1) {
            enemy.health -= hero.hero.strength;
            return 1;
        } else if (action == 2) {
            return 0;
        } else if (action == 3) {
            if (hero.consecutive_defending > 2) {
                enemy.health -= hero.hero.strength * 3;
                hero.consecutive_defending = 0;
                return 1;
            } else {
                cout << "You cannot use your super attack yet." << endl;
            }
        } else if (action == 4) {
            if (hero.hero.potion > 0) {
                hero.hero.potion -= 1;
                hero.hero.health += 15;
            } else {
                cout << "You don't have any more potions. Try something else." << endl;
            }
        } else {
            cout << "Invalid action." << endl;
        }
    }
}

void monster_attacks(hero_in_battle hero, monster_in_battle monster) {
    int damage = monster.enemy.strength;
    if (monster.enemy.defense > monster.enemy.strength) {
        if (monster.consecutive_defending > 2) {
            hero.hero.health -= damage * 3;
            monster.consecutive_defending = 0;
        } else {
            monster.consecutive_defending++;
        }
    } else {
        hero.hero.health -= damage;
        if (hero.consecutive_defending > 0) {
            hero.hero.health += hero.hero.defense;
        }
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
    cout << "Health: " << hero.health << "/" << hero.max_health << endl;
    cout << "You have " << hero.potion << " potions. Use them wisely!" << endl << endl;
}

void battle_workflow(main_character hero, monster enemy) {
    initial_message(hero);
    hero_in_battle hero_battle;
    hero_battle.hero = hero;
    hero_battle.consecutive_defending = 0;

    monster_in_battle monster_battle;
    monster_battle.enemy = enemy;
    monster_battle.consecutive_defending = 0;

    int round = 1;
    int result = coin_toss();

    while (hero.health > 0 && enemy.health > 0) {
        if (round % 2 == 1) {
            cout << "THE " << round << term(round / 2) << " ROUND BEGINS!" << endl;
        }
        if (result) {
            hero_attacks(hero_battle, enemy);
            monster_attacks(hero_battle, monster_battle);
        } else {
            monster_attacks(hero_battle, monster_battle);
            hero_attacks(hero_battle, enemy);
        }
        result = !result;
        round++;
    }
}