#include <bits/stdc++.h>
#include "main-character.cpp"
#include "monster-generator.cpp"
#include "battle.cpp"
#include "store.cpp"
#include "ranking.cpp"
#include "log.cpp"

using namespace std;

const string INTRODUCTION = "Bem Vindo ao XIAQ\n";
const string CONGRATULATIONS_MESSAGE = "Parabéns!! Você ganhou mais uma batalha!\n\n";
const string START_OPTIONS_MESSAGE = "[1] Iniciar batalha\n[2] Ver Instruções\n[3] Visualizar Recordes\n[4] Sair\n\n";
const string IN_GAME_OPTIONS_MESSAGE = "[1] Continua Batalhando\n[2] Ir para a loja\n";
const string LOSS_MESSAGE = "Infelizmente chegamos ao fim dessa partida após essa derrota.\n";
const string INSTRUCTIONS = "O jogo se dá através de sucessivas lutas contra monstros!\nA cada 5 vitórias você poderá ir para loja ficar mais forte!\nDê o seu melhor para matar o maior numero de monstros possível!\n\n";
const string DIFFICULTY_OPTIONS = "Escolha um nível de dificuldade:\n[1] Fácil\n[2] Médio\n[3] Difícil\n";
const int SCORE_INCREMENT = 5;
int DIFFICULTY_LEVEL = 1;

void play(main_character &character) {
  //Select the difficult level before start the game.
  int battles_counter = 0;
  int still_in_battle = 0;
  int current_score = 0;
  do {
    if(still_in_battle) {
      printf("%s", CONGRATULATIONS_MESSAGE.c_str());
      add_log(CONGRATULATIONS_MESSAGE);
      character.coins += 2;
      current_score += SCORE_INCREMENT + character.game_progress_multiplier/10;
    }

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
  add_log(LOSS_MESSAGE);
  add_log("\n\n\n\n\n\n\n");
  printf("\n");
  save_log();
  insert(DIFFICULTY_LEVEL, character.name, current_score);
  
}

void game_setup(main_character &character) {
  generate_all_alterers();
  generate_all_monsters();
  generate_all_items();
  set_initial_items();
  character.game_progress_multiplier = DIFFICULTY_LEVEL;
}

void select_difficulty_level() {
  printf("%s", DIFFICULTY_OPTIONS.c_str());
  int option;
  bool valid_option = true;
  do {
    scanf("%d", &option);
    switch(option) {
      case 1:
        DIFFICULTY_LEVEL = 1;
        break;
      case 2:
        DIFFICULTY_LEVEL = 2;
        break;
      case 3:
        DIFFICULTY_LEVEL = 3;
        break;
      default:
        printf("Opção inválida");
        valid_option = false;
        break;
    }
  } while(!valid_option);
  
}

void start_menu(main_character &character) {
  printf("%s", INTRODUCTION.c_str());
  add_log(INTRODUCTION);
  int option;
  string message;
  while(1) {
    printf("%s", START_OPTIONS_MESSAGE.c_str());
    scanf(" %d", &option);

    switch(option) {
      case 1:
        select_difficulty_level();
        game_setup(character);
        printf("Jogador, digite seu primeiro nome:\n");
        cin >> character.name;
        message = "Uma nova partida foi iniciada!\n\nNovo jogador: " + character.name + "\n\n";
        add_log(message);
        printf("%s",message.c_str());
        play(character);
        break;
      case 2:
        printf("%s", INSTRUCTIONS.c_str());
        break;
      case 3:
        see_all_three_highest_score();
        break;
      case 4:
        return;
      default:
        printf("Opção inválida\n");
        break;
    }
  }
}

int main() {
  load_log();
  start_menu(character);
}
