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



alterer get_random_weapon_alterer(){//Pega um alterador aleatório da lista

}

alterer get_random_monster_alterer(){//Pega um alterador aleatório da lista

}

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

alterer weapon_alterer[9] = {enraged,shiny,tought,legendary,irreparable,weak,dirty,soft,default_};

//Tipos de alterador para mostros
//Negativos
alterer monster_weak;
alterer monster_pacifist;
alterer monster_dumb;
alterer monster_blind;
alterer monster_imaginary;
alterer monster_legless;

//Positivos
alterer monster_invisible;
alterer monster_gigantic;
alterer monster_three_headed;
alterer monster_terrifying;
alterer monster_hairy;
alterer monster_stony;
alterer monster_murderer;


alterer monster_alterer[14] = {monster_weak,monster_pacifist,monster_dumb,monster_blind,monster_imaginary,monster_legless,monster_invisible,monster_gigantic,monster_three_headed,monster_terrifying,monster_hairy,monster_stony,monster_murderer,default_};




