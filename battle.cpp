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

struct enemy_in_battle : in_battle {
    monster enemy;
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
    // Get user's input for action
    int action;
    cout << "1 for Attack, 2 for Defend, 3 for Super Attack, 4 to use a potion" << endl;
    cout << "Action: ";
    cin >> action;
    cout << endl;

    return action;
}

void heros_turn(hero_in_battle hero_battle, enemy_in_battle enemy_battle) {
    int action;
    cout << "Choose your action:" << endl;

    while (1) {
        action = get_battle_action();

        switch (action) {
            case 1:
                // Enemy's HP is damaged by hero's strength
                enemy_battle.enemy.health -= hero_battle.hero.strength;
                hero_battle.consecutive_defending = 0;
                break;

            case 2:
                // Hero's consecutive rounds defending increases by 1
                hero_battle.consecutive_defending += 1;
                break;

            case 3:
                if (hero_battle.consecutive_defending > 2) {
                    // Enemy's HP is damaged by hero's strength * 3
                    enemy_battle.enemy.health -= hero_battle.hero.strength * 3;
                    hero_battle.consecutive_defending = 0;
                } else {
                    cout << "You cannot use your super attack yet." << endl;
                }
                break;
            case 4:
                // Hero uses potion if he has any
                if (hero_battle.hero.potion > 0) {
                    hero_battle.hero.potion -= 1;
                    hero_battle.hero.health += 15;
                } else {
                    cout << "You don't have any more potions. Try something else." << endl;
                }
                break;

            default:
                cout << "Invalid action." << endl;
                break;
        }
    }
}

void enemys_turn(hero_in_battle hero_battle, enemy_in_battle enemy_battle) {
    // Enemy's attacks can follow 2 different strategies:
    // The first occurs when the monster's defense is higher than
    // his strength, the second occurs otherwise
    int damage = enemy_battle.enemy.strength;

    if (enemy_battle.enemy.defense > enemy_battle.enemy.strength) {
        // First strategy: Monster prioritizes super attack
        if (enemy_battle.consecutive_defending > 2) {
            hero_battle.hero.health -= damage * 3;
            enemy_battle.consecutive_defending = 0;
        } else {
            enemy_battle.consecutive_defending++;
        }
    } else {
        // Second strategy: monster always attacks
        hero_battle.hero.health -= damage;
        if (hero_battle.consecutive_defending > 0) {
            hero_battle.hero.health += hero_battle.hero.defense;
        }
    }
}

string term(int round) {
    // Method to get the termination to the round counter
    string terms[4] = {"st", "nd", "rd", "th"};
    if (round > 3) round = 3;
    return terms[round];
}

void initial_message(main_character hero) {
    cout << "THE BATTLE IS ABOUT TO BEGIN!!" << endl;
    cout << "Remember Hero, your status is: " << endl;
    cout << "Strength: " << hero.strength << endl;
    cout << "Defense: " << hero.defense << endl;
    cout << "Health: " << hero.health << "/" << hero.max_health << endl;
    cout << "You have " << hero.potion << " potions. Use them wisely!" << endl << endl;
}

int battle_workflow(main_character hero, monster enemy) {
    // Displays initial message
    initial_message(hero);

    // Sets hero in battle
    hero_in_battle hero_battle;
    hero_battle.hero = hero;
    hero_battle.consecutive_defending = 0;

    // Sets enemy in battle
    enemy_in_battle enemy_battle;
    enemy_battle.enemy = enemy;
    enemy_battle.consecutive_defending = 0;

    // 
    int round = 1;
    int result = coin_toss();

    while (hero.health > 0 && enemy.health > 0) {
        if (round % 2 == 1) {
            cout << "THE " << round << term(round / 2) << " ROUND BEGINS!" << endl;
        }
        if (result) {
            heros_turn(hero_battle, enemy_battle);
            enemys_turn(hero_battle, enemy_battle);
        } else {
            enemys_turn(hero_battle, enemy_battle);
            heros_turn(hero_battle, enemy_battle);
        }
        result = !result;
        round++;
    }
    if (hero.health > 0) {
        return 1;
    }
    return 0;
}