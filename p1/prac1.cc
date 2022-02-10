#include <iostream>
#include <cstdlib> // Para rand(), srand() y atoi()

using namespace std;
/*Constantes*/
const int KNAME=32;
const int KENEMIES=5;
const int KPOINTS=200;
const int KDICE=20; // Número de caras del dado

struct Core{
  int attack;
  int defense;
  int hp;
};
/*define clases de enemigos*/
enum Breed{
  AXOLOTL,
  TROLL,
  ORC,
  HELLHOUND,
  DRAGON
};

struct Enemy{
  Breed name;
  Core features;
};

struct Hero{
  char name[KNAME];
  Core features;
  bool special;
  int runaways;
  int exp;
  int kills[KENEMIES];
};

int rollDice(){   //funcion de dado
  return rand()%KDICE+1; //devuelve valores entre 1 y 20
}
/*declarar funciones*/
int nombreheroe(){}
int attack_defense(){}

Hero createHero(){
  nombreheroe(Hero.name);{  //funcion nombre heroe
    cout << "Enter Hero name: \n ";
    cin >> Hero.name;
    if (Hero.name = " ");{ //prueba de nombre vacio
      cout << "Error Worng Name \n";
      nombreheroe();
    }
    else if (isalpha(Hero.name [0]));{ //prueba valores alfanumericos
      cout << "Error Worng Name \n";
      nombreheroe();
    }

  }
  attack_defense();{ //funcion ataque y defensa
    int ataque_defensa;
    cout << "Enter attack/defense \n";
    cin >> ataque_defensa;
      //trocear el parametro en dos valores enteros (%ataque/%defensa)
      //comprobar valores > 0
/*    if (ataque+defesensa=100); { //comprobar que los dos valores suman 100
      hero.Core.attack = (ataque/100)*200;
      hero.Core.defense = (defensa/100)*200;

    }  
    else{ cout << "Error Worng Distribution"; attack_defense();}
    */
  }
  Hero.core.hp = (hero.Core.defense*2);
  Hero.special = true;
  Hero.exp = 0;
  Hero.kills = 0;
}
/*
Enemy createEnemy(){
  switch (rollDice){
    case rollDice <=6 :
      AXOLOTL
    case rollDice <=11 :
      TROLL
    case rollDice <=15 :
      ORC
    case rollDice <=18 :
      HELLHOUND
    case rollDice <=20 :
      DRAGON
  }
}

void fight(Hero &hero,Enemy &enemy){
}

void report(const Hero &hero){
}

void showMenu(){
  cout << "[Options]" << endl
       << "1- Fight" << endl
       << "2- Run away" << endl
       << "3- Special" << endl 
       << "4- Report" << endl
       << "q- Quit" << endl
       << "Option: ";
  cin >> opcion; 
  switch (opcion){
    case 1:
    case 2:
    case 3:
    case 4:
    case "q":
    default: 
      cout << "Error Wrong Option \n";
      showMenu()
  }
}

int main(int argc,char *argv[]){
  if(argc!=2){ // Si los parámetros no son correctos, el programa termina inmediatamente
    cout << "Usage: " << argv[0] << " <seed>" << endl;
  }
  else{
    srand(atoi(argv[1])); // Introducimos la semilla para generar números aleatorios
    
    // Aquí vendrá todo tu código del "main"...
  }
}
*/