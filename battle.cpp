#ifndef BATTLE_CPP
#define BATTLE_CPP
#include "main-character.cpp"
#include "monster-generator.cpp"
#include "log.cpp"
#include <bits/stdc++.h>

using namespace std;

string intToString(int number) {
    stringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

void non_negative_damage(int& damage) {
    if (damage < 0) {
        damage = 0;
    }
}

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
    string message;

    string chosen;
    int win = 1;
    cout << "Escolha 'cara' or 'coroa': ";
    cin >> chosen;

    // Calculate result
    // if 1, heads wins

    int result = rand() % 2;
    if (result == 1 && chosen.compare("cara")) {
        message = "Você ganhou o 'cara ou coroa'. A primeira ação é sua!\n";
    } else if (result == 0 && chosen.compare("coroa")) {
        message = "Você ganhou o 'cara ou coroa'. A primeira ação é sua!\n";
    } else {
        message = "Você perdeu o 'cara ou coroa'. A primeira ação é do inimigo!\n";
        win = 0; // Hero lost
    }
    cout << message; // LOG THIS MESSAGE
    add_log(message);
    return win;
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
    bool done = true;
    int base_damage = hero_battle->hero->strength;
    string message = "";
    int enemy_max_health = enemy_battle->enemy->health;
    
    cout << "Escolha sua ação:" << endl;

    while (done) {
        action = get_battle_action();

        switch (action) {
            case 1: {
                // Enemy's HP is damaged by hero's strength
                message = "Você atacou o inimigo!\n";
                if (enemy_battle->consecutive_defending > 0) {
                    message += "O inimigo estava na defensiva e bloqueou parte do dano.\n";
                    base_damage -= enemy_battle->enemy->defense;
                    non_negative_damage(base_damage);
                }
                message += "Você causou dano e o inimigo perdeu " + intToString(100*base_damage/enemy_max_health) + "% de sua vida.\n";
                enemy_battle->enemy->health -= base_damage;
                hero_battle->consecutive_defending = 0;
            }
            done = false;
            break;

            case 2: {
                // Hero's consecutive rounds defending increases by 1
                message = "Você está em posição defensiva!\n";
                hero_battle->consecutive_defending += 1;
            }
            done = false;
            break;

            case 3: {
                if (hero_battle->consecutive_defending > 2) {
                    // Enemy's HP is damaged by hero's strength * 3
                    message = "Você usou o super ataque!\n";
                    base_damage = base_damage * 3;
                    if (enemy_battle->consecutive_defending > 0) {
                        base_damage -= enemy_battle->enemy->defense;
                        non_negative_damage(base_damage);
                        message += "O inimigo estava na defensiva e bloqueou parte do dano.\n";
                    }
                    message += "Você causou dano e o inimigo perdeu " + intToString(100*base_damage/enemy_max_health) + "% de sua vida.\n";
                    enemy_battle->enemy->health -= base_damage;
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
                    message = "Você usou uma poção e recuperou 15 de vida!\n";
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
    cout << message; // LOG THIS MESSAGE
    add_log(message);
}

void enemys_turn(hero_in_battle *hero_battle, enemy_in_battle *enemy_battle) {
    // Enemy's attacks can follow 2 different strategies:
    // The first occurs when the monster's defense is higher than
    // his strength, the second occurs otherwise
    int damage = enemy_battle->enemy->strength;
    string message = "";

    if (enemy_battle->enemy->defense > enemy_battle->enemy->strength) {
        // First strategy: Monster prioritizes super attack
        if (enemy_battle->consecutive_defending > 2) {
            damage = damage * 3;
            message = "O inimigo usou o super ataque!\n";
            if (hero_battle->consecutive_defending > 0) {
                damage -= hero_battle->hero->defense;
                non_negative_damage(damage);
                message += "Você estava na defensiva e bloqueou parte do dano.\n";
            }
            message +=  "Você sofreu " + intToString(damage) + " de dano!\n";
            hero_battle->hero->health -= damage;
            enemy_battle->consecutive_defending = 0;
        } else {
            message = "O inimigo ficou em posição defensiva.\n";
            enemy_battle->consecutive_defending++;
        }
    } else {
        // Second strategy: monster always attacks
        message = "O inimigo te atacou!";
        if (hero_battle->consecutive_defending > 0) {
            damage -= hero_battle->hero->defense;
            non_negative_damage(damage);
            message += "Você estava na defensiva e bloqueou parte do dano.\n";
        }
        message += " Você sofreu " + intToString(damage) + " de dano!\n";
        hero_battle->hero->health -= damage;
    }
    cout << message; // LOG THIS MESSAGE
    add_log(message);
}

void initial_message(main_character& hero, monster& enemy) {
    cout << "A BATALHA ESTÁ PRESTES A COMEÇAR!!" << endl;
    cout << "Lembre-se, seus status são: " << endl;
    cout << "Força: " << hero.strength << endl;
    cout << "Defesa: " << hero.defense << endl;
    cout << "Vida: " << hero.health << "/" << hero.max_health << endl;
    cout << "Você tem " << hero.potion << " Poções. Use-as sabiamente!!" << endl;
    cout << "Você encontrou um " << enemy.name << endl << endl;
}

int battle_workflow(main_character& hero, monster& enemy) {
    // Displays initial message
    initial_message(hero,enemy);

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
    string message = "Situação do HP: " + to_string(hero_battle.hero->health) + "/" + to_string(hero_battle.hero->max_health) + "\n";
    cout << message; // LOG THIS MESSAGE
    add_log(message);
    if (hero.health > 0) {
        return 1;
    }
    return 0;
}

#endif
