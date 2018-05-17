#include <bits/stdc++.h>
using namespace std;

//Alterers são adjetivos
//Irão alterar tanto armaduras quanto armas e monstros
//Porém o conjunto de alterardores de armas e armaduras são diferentes dos alteradores de monstros
struct alterer {
    string text;
    int strength;
    int defense;
    int health;
};

//defautl
//Existe tanto para monstros quanto para armas
alterer default_;

//Tipos de alteradores para armas
//Alteradores positivos
alterer enraged;//+atq
alterer shiny;//+vida
alterer tought;//+def
alterer legendary;//+atq,+def,+vida

//Alteradores negativos
alterer irreparable;//-atq,-def,-vida
alterer weak;//-def
alterer dirty;//-vida
alterer soft;//-atq

alterer item_alterer[8] = {enraged, shiny, tought, legendary, irreparable, weak, dirty, soft, default_};

//Tipos de alterador para mostros
//Negativos
alterer weak;
alterer pacifist;
alterer dumb;
alterer blind;
alterer imaginary;
alterer legless;

//Positivos
alterer invisible;
alterer gigantic;
alterer three_headed;
alterer terrifying;
alterer hairy;
alterer stony;
alterer murderer;

alterer monster_alterer[13] = {weak, pacifist, dumb, blind, imaginary, legless,
    invisible, gigantic, three_headed, terrifying, hairy, stony, murderer, default_};

alterer get_random_item_alterer(){//Pega um alterador aleatório da lista
    int random = rand() % item_alterer.size();
    return item_alterer[random];
}

alterer get_random_monster_alterer(){//Pega um alterador aleatório da lista
    int random = rand() % monster_alterer.size();
    return monster_alterer[random];
}