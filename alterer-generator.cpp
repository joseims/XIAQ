#include <bits/stdc++.h>
using namespace std;

//Alterers são adjetivos
//Irão alterar tanto armaduras quanto armas e monstros
//Porém o conjunto de alterardores de armas e armaduras são diferentes dos alteradores de monstros
struct alterer {
    int strength;
    int defense;
    int health;
};



alterer getRandomWeaponAlterer(){//Pega um alterador aleatório da lista

}

alterer getRandomMonsterAlterer(){//Pega um alterador aleatório da lista

}



//Tipos de alteradores para armas
//Alteradores positivos
alterer enraged;//+afq
alterer shiny;//+vida
alterer tought;//+def
alterer legendary;//+atq,+def,+vida

//Alteradores negativos
alterer irreparable;//-atq,-def,-vida
alterer weak;//-def
alterer dirty;//-vida
alterer soft;//-atq



//Tipos de alterador para mostros
//Negativos
alterer weak;
alterer pacifist;
alterer calm;
alterer dumb;
alterer awful;
alterer greedy;
alterer blind;
alterer scared;
alterer imaginary;
alterer legless;

//Positivos
alterer invisible;
alterer gigantic;
alterer three-headed;
alterer terrifying;
alterer scary;
alterer voracius;
alterer legendary;
alterer hairy;
alterer stony;
alterer murderer;




