#include <bits/stdc++.h>
using namespace std;
#include "item-generator.cpp"
#include "main-character"

item itens[3];
bool is_bought[3];
int potion_price = 5;
string potion_text = "Poção (Recupera X de vida)"

void see_store(main_character character) {
    int game_progress_multiplyer = character.gameProgressMultiplyer;
    reset_is_bought();
    itens[0] = generate_weapon(game_progress_multiplyer);
    itens[1] = generate_armor(game_progress_multiplyer);
    itens[2] = generate_rand_item(game_progress_multiplyer);
    print_menu(character);
    buying_menu(character);
    
};

void reset_is_bought(){
    for (int i = 0; i< 3; i ++) {
        is_bought[i] = false;
    }
};

void exit_store() {
    print("Xau xau meu parceiro");
};

void buy_item(main_character character, item item) {
    if (can_buy_it(character,item.price)) {
        //desconta o valor , equipa o item e marca como comprado
    } else {
        printf("Ops,a");
    }
    buying_menu();
};

void buy_potion(main_character character) {
    if (can_buy_it(character,potion_price)) {
        //Desconta o valor,incrementa
    } else {
        printf("Ops,a");
    }
    buying_menu();
};

void buying_menu(main_character character) {
     int option;
     while (true) {
        scanf("%d",&option);
        if (is_bought(option)) {
            if (option == 1) {
                buy_item(character,itens[0]);
                return;
            }  else if (option == 2) {
                buy_item(character,itens[1]);
                return;
            }  else if (option == 3) {
                buy_item(character,itens[2]);    
                return;      
            }  else if (option == 4) {
                buy_potion(character);
                return;
            }  else if (option == 5) {
                exit_store();
                return;
            }  else {
                printf("opção Inválida, escolha novamente");
            }
        } else {
            printf("Você já comprou esse item, escolha novamente");
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
    item old_item = get_same_type_equipped_item(item.type,character);
    int def_diff = item.defense - old_item.defense;
    int atq_diff = item.attack - old_item.attack;
    int hp_diff = item.health - old_item.health;
    printf("[%d] %s (Ataque= %d, Defesa= %d,Vida= $d) - %d",index,item.name,atq_diff,def_diff,hp_diff,item.price);
};


void print_potion(int game_progress_multiplyer) {
    int actual_potion_price = get_item_price(potion_price,game_progress_multiplyer);
    printf("[4] %s - $d",potion_text,actual_potion_price);
}

void print_menu(int game_progress_multiplyer,main_character character) {
    printf("Selecione uma opção : ")
    for (int i = 0; i < 3;i++) {
        print_item(itens[i],character,i+1);
    }
    print_potion(game_progress_multiplyer);
    print("[5] Sair da loja");
};

