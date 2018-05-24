#include <bits/stdc++.h>
#include "main-character.cpp"
#include "monster-generator.cpp"
#include "battle.cpp"
#include "store.cpp"

using namespace std;

const string INTRODUCTION = "BEM VINDO AO XIAQ\n";
const string CONGRATULATIONS_MESSAGE = "Parabéns!! Você ganhou mais uma batalha..\n";
const string OPTIONS_MESSAGE = "Digite 1 caso deseje ir a loja ou 1 se quiser continuar batalhando.\n";
const string LOSS_MESSAGE = "Infelizmente chegamos ao fim após essa derrota.\n";

void start_game(main_character character, monster enemy) {
  //Select the difficult level before start the game.
  while(battle_workflow(character, enemy)) {
    printf("%s", CONGRATULATIONS_MESSAGE.c_str());
    printf("%s", OPTIONS_MESSAGE.c_str());

    int option;
    scanf("%d", &option);
    if(option == 2) {
      see_store(character);
    }
  }
}

int main() {
  printf("%s", INTRODUCTION.c_str());

  monster enemy = get_random_monster();
  generate_generic_monster(&enemy);
  start_game(character, enemy);

  //Refresh the rank here, after the game's ending.
  printf("%s", LOSS_MESSAGE.c_str());
}