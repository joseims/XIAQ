#include <bits/stdc++.h>
using namespace std;
#include "main-character.cpp"



item itens[3];
bool bought[3];
const int POTION_PRICE = 5;
int actual_potion_price;
const string ARMOR_TYPE = "armor";
const string WEAPON_TYPE = "weapon";
const string POTION_TEXT = "Poção (Recupera X de vida)";
const string STORE_WELCOME_TEXT = "BEM VINDO MEU PARCEIRO\n";
const string ALREADY_BOUGHT_TEXT = "Você já comprou esse item, escolha novamente\n";
const string EXIT_TEXT = "Xau xau meu parceiro\n";
const string NOT_ENOUGH_COINS_TEXT = "Sinto muito, você não me parece ter dinheiro suficiente para comprar isso\n";
const string INVALID_OPTION_TEXT = "Opção Inválida, escolha novamente\n";


void run_store(main_character main_character);

void print_potion(int game_progress_multiplier) {
    printf("[4] %s - %d\n",POTION_TEXT.c_str(),actual_potion_price);
};


item get_same_type_equipped_item(string item_type, main_character character) {
    if (item_type == ARMOR_TYPE) {
        return character.armor;
    } else if (item_type == WEAPON_TYPE){
        return character.weapon;
    }

    return character.weapon;//just for future changes the else if is for code clarification
};


void print_item(item item_, main_character character, int index){
    if (bought[index]) {
        printf("[%d] (Item comprado)",index);
    } else {
        item old_item = get_same_type_equipped_item(item_.type, character);
        int def_diff = item_.defense - old_item.defense;
        int str_diff = item_.strength - old_item.strength;
        int hp_diff = item_.health - old_item.health;
        printf("[%d] %s (Força= %d, Defesa= %d,Vida= %d) - %d\n",index, item_.name.c_str(), str_diff, def_diff, hp_diff, item_.price);
    }
};

void calculate_actual_potion_price(main_character main_character) {
    actual_potion_price = POTION_PRICE * character.game_progress_multiplier;
};


void print_menu(main_character character) {
    printf("Selecione uma opção : ");
    for (int i = 0; i < 3;i++) {
        print_item(itens[i],character,i+1);
    }
    print_potion(character.game_progress_multiplier);
    printf("[5] Sair da loja");
};

void reset_is_bought(){
    for (int i = 0; i< 3; i ++) {
        bought[i] = false;
    }
};

void exit_store() {
    printf("%s",EXIT_TEXT.c_str());
};

bool can_buy_it(main_character character, int price) {
    return character.coins >= price;
};

void equip_item(main_character character, item item_, int index) {
    item old_item;
    if (item_.type == ARMOR_TYPE) {
        old_item = character.armor;
        character.armor = item_;
    } else if (item_.type == WEAPON_TYPE){
        old_item =  character.weapon;
        character.weapon = item_;
    }
    int def_diff = item_.defense - old_item.defense;
    int str_diff = item_.strength - old_item.strength;
    int hp_diff = item_.health - old_item.health;

    character.strength += str_diff;
    character.defense += def_diff;
    character.max_health += hp_diff;

    if (character.max_health < character.health) {
        character.health = character.max_health;
    }
}

void buy_item(main_character character, item item_, int index) {
    if (can_buy_it(character,item_.price)) {
        character.coins -= item_.price;
        equip_item(character,item_,index);
        bought[index] = true;
    } else {
        printf("%s",NOT_ENOUGH_COINS_TEXT.c_str());
    }
    run_store(character);
};

void buy_potion(main_character character) {
    if (can_buy_it(character,POTION_PRICE)) {
        character.coins -= actual_potion_price;
        character.potion += 1;
    } else {
        printf("%s",NOT_ENOUGH_COINS_TEXT.c_str());
    }
    run_store(character);
};

bool is_bought(int index) {
    if (index <= 3 && index > 0) {
        return bought[index-1];
    }
    return false;
};

void buying_menu(main_character character) { //TO SWITCH CASE
     int option;
     while (1) {
        scanf("%d",&option);
        if (is_bought(option)) {
            if (option == 1) {
                buy_item(character,itens[0],0);
                return;
            }  else if (option == 2) {
                buy_item(character,itens[1],1);
                return;
            }  else if (option == 3) {
                buy_item(character,itens[2],2);    
                return;      
            }  else if (option == 4) {
                buy_potion(character);
                return;
            }  else if (option == 5) {
                exit_store();
                return;
            }  else {
                printf("%s",INVALID_OPTION_TEXT.c_str());
            }
        } else {
            printf("%s",ALREADY_BOUGHT_TEXT.c_str());
        }
    }
};

void run_store(main_character character) {
    printf("\n\n");
    print_menu(character);
    buying_menu(character);
};



void see_store(main_character character) {
    calculate_actual_potion_price(character);
    printf("%s",STORE_WELCOME_TEXT.c_str());
    int game_progress_multiplier = character.game_progress_multiplier;
    reset_is_bought();
    itens[0] = generate_weapon(game_progress_multiplier);
    itens[1] = generate_armor(game_progress_multiplier);
    itens[2] = generate_rand_item(game_progress_multiplier);
    run_store(character);
    
};

main() {

};

