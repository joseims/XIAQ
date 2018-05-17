#include <bits/stdc++.h>
#include "alterer-generator.cpp"

using namespace std;

struct item{
    string name;
    int strength;
    int defense;
    int health;
    string attack;
    string type;
    int price;
};

//Tipos de armas
item sword;//atq ++
item mace;//atq+,vida+
item gauntlet;//atq+,def+,vida+
item sword_shield;//atq+ def+

item weapons[4] = {sword,mace,gauntlet,sword_shield};


//Tipos de armadura
item light_armor;//+vida
item medium_armor;//+vida,+def
item heavy_armor;//+def
item spiky_armor;//+atq,+def
item kimono;//+atq,+vida

item armors[5] = {light_armor,medium_armor,heavy_armor,spikey_armor,kimono};

//Initial
item stick;//Arma inicia
item potato_sack;//Armadura inicial

//Poderiamos colocar humor criando itens similares, mas comicos
//Como por exemplo uma pedra, que teria os estatos igual o da gauntlet porem o texto de ataque seria diferente
//Ou uma roupa de papel aluminio, coisa assim o mesmo pra monstros

item get_random_weapon() {//Pega uma arma aleatória
    int random = rand() % weapons.size();
    return weapons[random];
}

item get_random_armor() {//Pega uma armadura aleatória
    int random = rand() % armors.size();
    return armors[random];
}

int multiplyer_item(int attribute, int gameProgressMultiplyer) {
    return attribute * gameProgressMultiplyer;
}

item join_item_alterer(item i, alterer a, int gameProgressMultiplyer) {
    item new_item;
    new_item.name = i.name + " " + a.text;
    new_item.strength = multiplyer_item((i.strength + a.strength), gameProgressMultiplyer);
    new_item.defense = multiplyer_item((i.defense + a.defense), gameProgressMultiplyer);
    new_item.health = multiplyer_item((i.health + a.health), gameProgressMultiplyer);
    new_item.attack = i.attack + " " + a.text;
    new_item.type = i.type;
    new_item.price = multiplyer_item(i.price, gameProgressMultiplyer);
    return new_item;
}

item generate_weapon(int gameProgressMultiplyer) {//Gera uma arma aleatória
    item random_weapon = get_random_weapon();
    alterer random_alterer = get_random_item_alterer();
    return join_item_alterer(random_weapon, random_alterer, gameProgressMultiplyer);
}

item generate_armor(int gameProgressMultiplyer) { // Gera uma armadura aleatória
    item random_armor = get_random_armor();
    alterer random_alterer = get_random_item_alterer();
    return join_item_alterer(random_armor, random_alterer, gameProgressMultiplyer);
}

item generate_randItem(int gameProgressMultiplyer) { //Gera um item que pode ser uma armadura ou arma,
                                                     //A ideia é que na loja tenha 1 arma, 1 armadura e 1 rand
    int random = rand() % 1;
    if (random) return generate_weapon();
    else return generate_armor();
}