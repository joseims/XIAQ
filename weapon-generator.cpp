#include <bits/stdc++.h>
using namespace std;


struct item{
    string name;
    int strength;
    int defense;
    int health;
    string atack;
    string type;
    int price
};


//Tipos de armas
item sword;//atq ++
item mace;//atq+,vida+
item gauntlet;//atq+,def+,vida+
item sword_shield;//atq+ def+

//Tipos de armadura
item light_armor;//+vida
item medium_armor;//+vida,+def
item heavy_armor;//+def
item spiky_armor;//+atq,+def
item kimono;//+atq,+vida


//Tipos de alteradores
//Irão alterar tanto armaduras quanto armas
//Não sei se definir eles como items é o mais correto, mas creio que facilita a implementação

//Alteradores positivos
item enraged;//+afq
item shiny;//+vida
item tought;//+def
item legendary;//+atq,+def,+vida

//Alteradores negativos
item irreparable;//-atq,-def,-vida
item weak;//-def
item dirty;//-vida
item soft;//-atq

//Initial
item stick;//Arma inicia
item potato_sack;//Armadura inicial

//Poderiamos colocar humor criando itens similares, mas comicos
//Como por exemplo uma pedra, que teria os estatos igual o da gauntlet porem o texto de ataque seria diferente
//Ou uma roupa de papel aluminio, coisa assim o mesmo pra monstros


item generate_weapon(int gameProgressMultiplyer) {//Gera uma arma aleatória

}

item generate_armor(int gameProgressMultiplyer) { // Gera uma armadura aleatória

}

item generate_randItem(int gameProgressMultiplyer) { //Gera um item que pode ser uma armadura ou arma, 
                                                     //A ideia é que na loja tenha 1 arma, 1 armadura e 1 rand

}


item getRandomWeapon() {//Pega uma arma aleatória

}

item getRandomArmor() {//Pega uma armadura aleatória

}