#include <bits/stdc++.h>
using namespace std;
#include "item-generator.cpp"
#include "main-character.cpp"

item itens[3];
bool bought[3];
const int potion_price = 5;
int actual_potion_price;
const string potion_text = "Poção (Recupera X de vida)";
const string store_welcome_text = "BEM VINDO MEU PARCEIRO\n";
const string already_bought_text = "Você já comprou esse item, escolha novamente\n";
const string exit_text = "Xau xau meu parceiro\n";
const string not_enought_coins_text = "Sinto muito, você não me parece ter dinheiro suficiente para comprar isso\n";
const string invalid_option_text= "Opção Inválida, escolha novamente\n";

void see_store(main_character character) {
    calculate_actual_potion_price(character);
    printf("%s",store_welcome_text );
    int game_progress_multiplyer = character.game_progress_multiplyer;
    reset_is_bought();
    itens[0] = generate_weapon(game_progress_multiplyer);
    itens[1] = generate_armor(game_progress_multiplyer);
    itens[2] = generate_rand_item(game_progress_multiplyer);
    run_store(character,game_progress_multiplyer);
    
};

void calculate_actual_potion_price(main_character main_character) {
    actual_potion_price = potion_price * character.game_progress_multiplyer;
}

void run_store(main_character character,int game_progress_multiplyer) {
    printf("\n\n");
    print_menu(character,game_progress_multiplyer);
    buying_menu(character);
}

void reset_is_bought(){
    for (int i = 0; i< 3; i ++) {
        bought[i] = false;
    }
};

void exit_store() {
    printf("%s",exit_text);
};

void buy_item(main_character character, item item,int index) {
    if (can_buy_it(character,item.price)) {
        character.coins -= item.price;
        equip_item(character,item,index);
        bought[index] = true;
    } else {
        printf("%s",not_enought_coins_text);
    }
    run_store(character,character.game_progress_multiplyer);
};

void equip_item(main_character character, item item, int index) {
    item old_item;
    if (item.type == ARMOR_TYPE) {
        old_item =  character.armor;
        character.armor = item;
    } else if (item.type == WEAPON_TYPE){
        old_item =  character.weapon;
        character.weapon = item;
    }
    int def_diff = item.defense - old_item.defense;
    int str_diff = item.strength - old_item.strength;
    int hp_diff = item.health - old_item.health;

    character.strength += str_dif;
    character.defense += def_diff;
    character.max_health += hp_diff;

    if (character.max_health < character.health) {
        character.health = character.max_health;
    }
}


void buy_potion(main_character character) {
    if (can_buy_it(character,potion_price)) {
        character.coins -= actual_potion_price;
        character.potion += 1;
    } else {
        printf("%s",not_enought_coins_text);
    }
    run_store();
};

void buying_menu(main_character character) {
     int option;
     while (true) {
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
                printf("%s",invalid_option_text);
            }
        } else {
            printf("%s",already_bought_text);
        }
    }
}

bool is_bought(int index) {
    if (index <= 3 && index > 0) {
        return is_bought[i-1];
    }
    return false;
}

bool can_buy_it(main_character character,int price) {
    return character.coins >= price;
}

item get_same_type_equipped_item(string item_type,main_character character) {
    if (item_type == ARMOR_TYPE) {
        return character.armor;
    } else if (item_type == WEAPON_TYPE){
        return character.weapon;
    }

    return character.weapon;//just for future changes the else if is for code clarification
};

void print_item(item item,main_character character,int index){
    if (bought[index]) {
        printf("[%d] (Item comprado)",index);
    } else {
        item old_item = get_same_type_equipped_item(item.type,character);
        int def_diff = item.defense - old_item.defense;
        int str_diff = item.strength - old_item.strength;
        int hp_diff = item.health - old_item.health;
        printf("[%d] %s (Força= %d, Defesa= %d,Vida= $d) - %d\n",index,item.name,str_diff,def_diff,hp_diff,item.price);
    }
};


void print_potion(int game_progress_multiplyer) {
    printf("[4] %s - %d\n",potion_text,actual_potion_price);
}

void print_menu(main_character character,int game_progress_multiplyer) {
    printf("Selecione uma opção : ");
    for (int i = 0; i < 3;i++) {
        print_item(itens[i],character,i+1);
    }
    print_potion(game_progress_multiplyer);
    printf("[5] Sair da loja");
};

