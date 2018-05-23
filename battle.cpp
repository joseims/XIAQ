#ifndef BATTLE_CPP
#define BATTLE_CPP
#include "main-character.cpp"
#include "monster-generator.cpp"
#include <bits/stdc++.h>

using namespace std;

struct hero_in_battle {
    main_character *hero;
    int consecutive_defending;
    // The hero in battle also has another attribute to 
    // check whatever was his last action. But, this
    // attribute can be derive from the consecutive 
    // rounds defending: if > 0, last action was a defense
};

struct enemy_in_battle {
    monster *enemy;
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
    cout << "Escolha 'cara' or 'coroa': ";
    cin >> chosen;

    // Calculate result
    // if 1, heads wins

    int result = rand() % 2;
    if (result == 1 && chosen.compare("cara")) {
        cout << "Você ganhou o 'cara ou coroa'. A primeira ação é sua!" << endl;
        return 1; // Hero won
    } else if (result == 0 && chosen.compare("coroa")) {
        cout << "Você ganhou o 'cara ou coroa'. A primeira ação é sua!" << endl;
        return 1; // Hero won
    } 
    cout << "Você perdeu o 'cara ou coroa'. A primeira ação é do inimigo!" << endl;
    return 0; // Hero lost
}

int get_battle_action() {
    // Get user's input for action
    int action;
    cout << "[1] Atacar\n[2] Defender\n[3] Super Ataque\n[4] Usar uma poção\n";
    cout << "Ação: ";
    cin >> action;
    cout << endl;

    return action;
}

void heros_turn(hero_in_battle *hero_battle, enemy_in_battle *enemy_battle) {
    int action;
    cout << "Escolha sua ação:" << endl;
    bool done = true;
    while (done) {
        action = get_battle_action();

        switch (action) {
            case 1: {
                // Enemy's HP is damaged by hero's strength
                int damage_a = hero_battle->hero->strength;
                cout << "Você causou " << damage_a << " de dano ao inimigo." << endl;
                enemy_battle->enemy->health -= damage_a;
                hero_battle->consecutive_defending = 0;
            }
            done = false;
            break;

            case 2: {
                // Hero's consecutive rounds defending increases by 1
                cout << "Você está em posição defensiva!";
                hero_battle->consecutive_defending += 1;
            }
            done = false;
            break;

            case 3: {
                if (hero_battle->consecutive_defending > 2) {
                    // Enemy's HP is damaged by hero's strength * 3
                    int damage_b = hero_battle->hero->strength * 3;
                    cout << "Você causou " << damage_b << " de dano ao inimigo." << endl;
                    enemy_battle->enemy->health -= damage_b;
                    hero_battle->consecutive_defending = 0;
                    done = false;
                } else {
                    cout << "Você ainda não pode usar o super ataque." << endl;
                }
            }
            break;
            case 4: {
                // Hero uses potion if he has any
                if (hero_battle->hero->potion > 0) {
                    cout << "Você usou uma poção e recuperou 15 de vida!" << endl;
                    hero_battle->hero->potion -= 1;
                    hero_battle->hero->health += 15;
                    done = false;
                } else {
                    cout << "Você não tem mais poções. Tente algo diferente." << endl;
                }
            }
            break;

            default: {
                cout << "Ação Inválida." << endl;
            }
            break;
        }
    }
}

void enemys_turn(hero_in_battle *hero_battle, enemy_in_battle *enemy_battle) {
    // Enemy's attacks can follow 2 different strategies:
    // The first occurs when the monster's defense is higher than
    // his strength, the second occurs otherwise
    int damage = enemy_battle->enemy->strength;

    if (enemy_battle->enemy->defense > enemy_battle->enemy->strength) {
        // First strategy: Monster prioritizes super attack
        if (enemy_battle->consecutive_defending > 2) {
            cout << "O inimigo usou o super ataque! Você sofreu " << damage * 3 << " de dano!" << endl;
            hero_battle->hero->health -= damage * 3;
            if (hero_battle->consecutive_defending > 0) {
                hero_battle->hero->health += hero_battle->hero->defense;
            }
            enemy_battle->consecutive_defending = 0;
        } else {
            cout << "O inimigo ficou em posição defensiva." << endl;
            enemy_battle->consecutive_defending++;
        }
    } else {
        // Second strategy: monster always attacks
        cout << "O inimigo te atacou! Você sofreu " << damage << " de dano!" << endl;
        hero_battle->hero->health -= damage;
        if (hero_battle->consecutive_defending > 0) {
            hero_battle->hero->health += hero_battle->hero->defense;
        }
    }
}

void initial_message(main_character& hero) {
    cout << "A BATALHA ESTÁ PRESTES A COMEÇAR!!" << endl;
    cout << "Lembre-se, seus status são: " << endl;
    cout << "Força: " << hero.strength << endl;
    cout << "Defesa: " << hero.defense << endl;
    cout << "Vida: " << hero.health << "/" << hero.max_health << endl;
    cout << "Você tem " << hero.potion << " Poções. Use-as sabiamente!!" << endl << endl;
}

int battle_workflow(main_character& hero, monster& enemy) {
    // Displays initial message
    initial_message(hero);

    // Sets hero in battle
    hero_in_battle hero_battle;
    hero_battle.hero = &hero;
    hero_battle.consecutive_defending = 0;

    // Sets enemy in battle
    enemy_in_battle enemy_battle;
    enemy_battle.enemy = &enemy;
    enemy_battle.consecutive_defending = 0;

    int round = 3;
    int result = coin_toss();

    while (hero_battle.hero->health > 0 && enemy_battle.enemy->health > 0) {
        if (round % 2 == 1) {
            cout << "Inicia-se o " << round/2 << "° round!" << endl << endl;
        }
        if (result) {
            heros_turn(&hero_battle, &enemy_battle);
        } else {
            enemys_turn(&hero_battle, &enemy_battle);
        }
        
        result = !result;
        round++;
    }
    cout << "Situação do HP: " << hero_battle.hero->health << "/" << hero_battle.hero->max_health << endl;
    if (hero.health > 0) {
        return 1;
    }
    return 0;
}

#endif
