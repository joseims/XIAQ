#include <bits/stdc++.h>
#include "main-character.cpp"
#include "monster-generator.cpp"
#include "battle.cpp"
#include "store.cpp"
#include "ranking.cpp"

using namespace std;

const string INTRODUCTION = "BEM VINDO AO XIAQ\n";
const string CONGRATULATIONS_MESSAGE = "Parabéns!! Você ganhou mais uma batalha..\n";
const string START_OPTIONS_MESSAGE = "Digite 1 caso queira batalhar, 2 se quiser ver as instruções ou 3 para visualizar o ranking.\n";
const string IN_GAME_OPTIONS_MESSAGE = "Digite 2 caso deseje ir a loja ou 1 se quiser continuar batalhando.\n";
const string LOSS_MESSAGE = "Infelizmente chegamos ao fim dessa partida após essa derrota.\n";
const string INSTRUCTIONS = "\n";
const int SCORE_INCREMENT = 5;

void play(main_character &character) {
  //Select the difficult level before start the game.
  int battles_counter = 0;
  int still_in_battle = 0;
  int current_score = 0;
  do {
    if(still_in_battle)
      printf("%s", CONGRATULATIONS_MESSAGE.c_str());
      character.coins ++;
      current_score += SCORE_INCREMENT;

    if(battles_counter == 5) {
      printf("%s", IN_GAME_OPTIONS_MESSAGE.c_str());

      int option;
      scanf("%d", &option);
      if(option == 2) {
        see_store(character);
      }
      battles_counter = 0;
    }

    monster enemy = generate_monster(false, ++character.game_progress_multiplier);
    still_in_battle = battle_workflow(character, enemy);
    battles_counter++;
  } while(still_in_battle);

  printf("%s", LOSS_MESSAGE.c_str());
  insert(1, "", current_score);
}

void game_setup(main_character &character) {
  generate_all_alterers();
  generate_all_monsters();
  character.game_progress_multiplier = 1;
}

void start_menu(main_character &character) {
  printf("%s", INTRODUCTION.c_str());
  int option;
  while(1) {
    printf("%s", START_OPTIONS_MESSAGE.c_str());
    scanf("%d", &option);

    switch(option) {
      case 1:
        game_setup(character);
        play(character);
        break;
      case 2:
        printf("%s", INSTRUCTIONS.c_str());
        break;
      case 3:
        see_all_score(1);
        break;
      default:
        printf("Opção inválida");
        break;
    }
  }
}

int main() {
  start_menu(character);
}