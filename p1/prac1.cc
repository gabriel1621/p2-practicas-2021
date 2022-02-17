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
int nombreheroe(Hero &name){};
int attack_defense(){};


Hero createHero(Hero &name ){
  nombreheroe(Hero.name);{  //funcion nombre heroe
    cout << "Enter Hero name: \n ";
    char nombre_Heore;
    cin >> nombre_Heore;
    if (nombre_Heore = "");{ //prueba de nombre vacio
      cout << "Error Worng Name \n";
      nombreheroe();
    };
    else-if ((isalnum(nombre_Heore[0]) == 0));{ //prueba valores alfanumericos
      cout << "Error Worng Name \n";
      nombreheroe();
    };
    else{
      Hero.name=nombre_Heore;
    }
    

  }
  attack_defense();{ //funcion ataque y defensa
    int ataque_defensa;
    cout << "Enter attack/defense \n";
    cin >> ataque_defensa;
      //cin.get()   trocear el parametro en dos valores enteros (%ataque/%defensa)
      //comprobar valores > 0
    if (ataque+defesensa=100); { //comprobar que los dos valores suman 100
      hero.Core.attack = (ataque/100)*200;
      hero.Core.defense = (defensa/100)*200;

    } ;
    else{ 
      cout << "Error Worng Distribution"; 
      attack_defense();
    };
    
  }
  Hero.core.hp = (hero.Core.defense*2);
  Hero.special = true;
  Hero.exp = 0;
  Hero.kills = 0;
  Hero.runaways = 3;
}

Enemy createEnemy(Enemy &enemy){
  switch (rollDice){
    if rollDice <=6 {
      cout  << "Breed: ",Enemy.Breed= 1;
            << "Attack: ",Enemy.Core.attack= 40 ;
            << "Defense: ",Enemy.Core.defense= 40;
            << "Health points: ",Enemy.core.hp = (hero.Core.defense*2); }
      
    else-if rollDice <=11 {
      cout  << "Breed: ",Enemy.Breed= 2;
            << "Attack: ",Enemy.Core.attack= 60 ;
            << "Defense: ",Enemy.Core.defense= 80;
            << "Health points: ",Enemy.core.hp = (hero.Core.defense*2);}
      
    else-if rollDice <=15 {
      cout  << "Breed: ",Enemy.Breed= 3;
            << "Attack: ",Enemy.Core.attack= 80 ;
            << "Defense: ",Enemy.Core.defense= 120;
            << "Health points: ",Enemy.core.hp = (hero.Core.defense*2);}
      
    else-if rollDice <=18 {
      cout  << "Breed: ",Enemy.Breed= 3;
            << "Attack: ",Enemy.Core.attack= 120 ;
            << "Defense: ",Enemy.Core.defense= 100;
            << "Health points: ",Enemy.core.hp = (hero.Core.defense*2);}
      
    else-if rollDice <=20 {
     cout  << "Breed: ",Enemy.Breed= 3;
            << "Attack: ",Enemy.Core.attack= 160 ;
            << "Defense: ",Enemy.Core.defense= 140;
            << "Health points: ",Enemy.core.hp = (hero.Core.defense*2);}
      
  }
}
/*Inicializacion de funciones*/
report();
showMenu();
/********************/
void fight(Hero &hero,Enemy &enemy){   

  do{
    int dadoheore = rollDice();
      dadoheore = (dadoheore*5);
    int dadoenemy = rollDice();
      dadoenemy = (dadoenemy*5);
    int vida_inicial = Hero.core.attack;
      Hero.core.attack= (dadoheore+vida_inicial);
    int defensa_inicial = Enemy.core.defense;
      Enemy.core.defense= (dadoenemy+defensa_inicial);
    int hit_points;
      hit_points = (Enemy.defense-Hero.attack);
      Enemy.core.hp= (Hero.core.hp-hit_points);
    cout << "[Hero -> Enemy]" << endl
         << "Attack: ",vida_inicial,"+",dadoheore << endl
         << "Defense: ",defensa_inicial,"+",dadoenemy << endl
         << "Hit Point: ", hit_points << endl
         << "Enemy health points: ",Enemy.core.hp << endl
    if (Enemy.core.hp<=0){
      break;
    }
    else{
      int dadoenemy = rollDice();
      dadoenemy = (dadoenemy*5); 
      int dadoheore = rollDice();
      dadoheore = (dadoheore*5);

    int vida_inicial = Enemy.core.attack;
      Enemy.core.attack= (dadoheore+vida_inicial);
    int defensa_inicial = Hero.core.defense;
      Hero.core.defense= (dadoenemy+defensa_inicial);
    int hit_points;
      hit_points = (Hero.defense-Enemy.attack);
      Hero.core.hp= (Enemy.core.hp-hit_points);
    cout << "[Enemy -> Hero]" << endl
         << "Attack: ",vida_inicial,"+",dadoenemy << endl
         << "Defense: ",defensa_inicial,"+",dadoheore << endl
         << "Hit Point: ", hit_points << endl
         << "Enemy health points: ",Hero.core.hp << endl
    if Hero.core.hp>0 {
      showMenu();
    }
    else{
      cout << "You are dead";
      report ();
    }
    }
  }
  while (Enemy.core.hp<=0){
    cout << "Enemy Killed" << endl
    if enum.Breed = 1 {
      Hero.exp = Hero.exp+100;
    }
    else-if enum.Breed = 2 {
      Hero.exp = Hero.exp+150;
    }
    else-if enum.Breed = 3 {
      Hero.exp = Hero.exp+200;
    }
    else-if enum.Breed = 4 {
      Hero.exp = Hero.exp+300;
    }
    else-if enum.Breed = 5 {
      Hero.exp = Hero.exp+400;
    }

  }

}
void runawayfuncion(Hero &hero){
  int contador_de_huida;
  contador_de_huida ++;
 while Hero.runaways>=0 || contador_de_huida<=2{
   Hero.runaways= Hero.runaways-1;
   createEnemy();
 }
 cout << "ERROR: cannot run away";
 showMenu();
  
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
    case 1: fight();
    case 2: runawayfuncion();
    case 3:
    case 4: report();
    case "q": Exit;
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
    createHero();
    createEnemy();
    showMenu();
  }
}
