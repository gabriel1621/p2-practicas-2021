#include <iostream>
#include <cstdlib> // Para rand(), srand() y atoi()
#include <cstring>

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
Hero createHero(){
  Hero hero;
  char nombre_Heore[KNAME];
  int error,error2;
  int ataque, defensa;
  int ataquetotal, defensatotal;

  do{
    cout << "Enter Hero name:" << endl;
    cin >> nombre_Heore;
    error = 0 ;
    if ((isalnum(nombre_Heore[0]) == 0)){ //prueba valores alfanumericos
      cout << "ERROR: Worng Name" << endl;
      error = 2;

    }
    else if ((isalpha(nombre_Heore[0]) == 0)){ //prueba valores alfanumericos
      cout << "ERROR: Worng Name" << endl;
      error = 3;
    }
    else if (long(nombre_Heore[KNAME]==1)){
      cout << "ERROR: Worng Name" << endl;
      error = 3;
    }
    
  
  }while (error != 0 );/*
  do{ 
    error2 =0;
    cout << "Enter attack/defense" << endl;
    ataque = cin.get();  
    defensa = cin.get();
    if ((ataque+defensa) == 100) { //comprobar que los dos valores suman 100
      ataquetotal = (ataque/100)*200;
      defensatotal = (defensa/100)*200;

    } 
    else { 
      cout << "Error Worng Distribution" << endl; 
      error2 =1;
    }
  }while (ataque != 0);*/
  hero.name[KNAME] = nombre_Heore[KNAME];
  hero.features.attack = ataquetotal;
  hero.features.defense = defensatotal;
  hero.features.hp = (hero.features.defense*2);
  hero.special = true;
  hero.exp = 0;
  hero.kills[KENEMIES] ;
  hero.runaways = 3;
  return hero;
}

Enemy createEnemy(){
  Enemy enemy;
  int num_dado;
  num_dado = rollDice();
    if (num_dado <=6) {
      enemy.name= AXOLOTL;
      enemy.features.attack= 40;
      enemy.features.defense= 40;
      enemy.features.hp = (enemy.features.defense*2);}
      
    else if (num_dado <=11) {
      enemy.name= TROLL;
      enemy.features.attack= 60;
      enemy.features.defense= 80;
      enemy.features.hp = (enemy.features.defense*2);}
      
    else if (num_dado <=15) {
      enemy.name= ORC;
      enemy.features.attack= 80;
      enemy.features.defense= 120;
      enemy.features.hp = (enemy.features.defense*2);}
      
    else if  (num_dado <=18) {
      enemy.name= HELLHOUND;
      enemy.features.attack= 120;
      enemy.features.defense= 100;
      enemy.features.hp = (enemy.features.defense*2);}
      
    else if (num_dado <=20) {
      enemy.name= DRAGON;
      enemy.features.attack= 160;
      enemy.features.defense= 140;
      enemy.features.hp = (enemy.features.defense*2);}
      
  
  cout << "Breed: " << enemy.name << endl
        << "Attack: " << enemy.features.attack << endl
        << "Defense: " << enemy.features.defense << endl
        << "Health points: " << enemy.features.hp << endl  ;
  return enemy;
}
/*Inicializacion de funciones*/
void showMenu(Hero &hero, Enemy &enemy);
void report(Hero &hero);
void lucha(Hero &hero, Enemy &enemy);
void fight(Hero &hero,Enemy &enemy);
void runawayfuncion(Hero &hero);
void special(Hero &hero);

/**************************************/
void runawayfuncion(Hero &hero, Enemy &enemy){
  int contador_de_huida;
 while (hero.runaways >= 0 && contador_de_huida <= 2){
   contador_de_huida++;
   hero.runaways= hero.runaways-1;
   createEnemy();
  }
 cout << "ERROR: can not run away";
 showMenu(hero,enemy);
  
}
void showMenu(Hero &hero, Enemy &enemy){
  char opcion;
  cout << "[Options]" << endl
       << "1- Fight" << endl
       << "2- Run away" << endl
       << "3- Special" << endl 
       << "4- Report" << endl
       << "q- Quit" << endl
       << "Option: ";
  cin >> opcion; 
  switch (opcion){
    case 49: {
      fight(hero,enemy);
      break;
    }
    case 50: {
      runawayfuncion(hero);
      break;}
    case 51: {
      special(hero);
      break;}
    case 52: {/*
      report(hero);*/
      break;}
    case 113: exit;
    default: 
      cout << "Error Wrong Option \n";
      showMenu(hero,enemy);
  }
}

void report(const Hero &hero){
  char printspecial;
    cout << "Name: " << hero.name << endl
      << "Attack: " << hero.features.attack << endl
      << "Defense: " << hero.features.defense << endl
      << "Health points: " << hero.features.hp << endl
      << "Special: " << printspecial << endl
      <<  "Runaways: " << hero.runaways << endl
      << "Exp: " << hero.exp << endl;
}
void lucha(Hero &hero, Enemy &enemy){
    int dadoheore = rollDice();
      dadoheore = (dadoheore*5);
    int dadoenemy = rollDice();
      dadoenemy = (dadoenemy*5);
    int ataque_inicial = hero.features.attack;
      ataque_inicial = (dadoheore+ataque_inicial);
    int defensa_inicial = enemy.features.defense;
      defensa_inicial = (dadoenemy+defensa_inicial);
    int hit_points;
      hit_points = (ataque_inicial-defensa_inicial);
      enemy.features.hp= (hero.features.hp-hit_points);
    int vida_enemy;
      vida_enemy = enemy.features.hp;
    cout << "[Hero -> Enemy]" << endl
         << "Attack: " << ataque_inicial << " + " << dadoheore << endl
         << "Defense: " << defensa_inicial << " + " << dadoenemy << endl
         << "Hit Point: " << hit_points << endl
         << "Enemy health points: " << vida_enemy << endl;
    if (vida_enemy>0){
      dadoenemy = rollDice();
      dadoenemy = (dadoenemy*5); 
      dadoheore = rollDice();
      dadoheore = (dadoheore*5);

      int ataque_inicial_eneMY = enemy.features.attack;
        ataque_inicial_eneMY= (dadoenemy+ataque_inicial_eneMY);
      int defensa_inicial_h = hero.features.defense;
        defensa_inicial_h= (dadoheore+defensa_inicial_h);
      int hit_points_eneMY;
        hit_points_eneMY = (ataque_inicial_eneMY-defensa_inicial_h);
        hero.features.hp= (enemy.features.hp-hit_points);
      int vida_heroe;
        vida_heroe=hero.features.hp;
      cout << "[Enemy -> Hero]" << endl
          << "Attack: "<<ataque_inicial<<"+"<<dadoenemy << endl
          << "Defense: "<<defensa_inicial<<"+"<<dadoheore << endl
          << "Hit Point: "<< hit_points << endl
          << "Enemy health points: "<<vida_heroe << endl;
      if (vida_heroe>0) {
        showMenu(hero,enemy);
      }
      else{
        cout << "You are dead" << endl;
        /*report(hero);*/
      }
    }

}

void fight(Hero &hero,Enemy &enemy){   
  
  do{
    lucha(hero,enemy);
      
  }while (enemy.features.hp<=0);
  int xp;
  xp = hero.exp;
    cout << "Enemy Killed" << endl;
    if (enemy.name = AXOLOTL ){
      hero.exp = xp+100;
    }
    else if (enemy.name = TROLL) {
      hero.exp = xp+150;
    }
    else if (enemy.name = ORC ){
      hero.exp = xp+200;
    }
    else if (enemy.name = HELLHOUND ){
      hero.exp = xp+300;
    }
    else if (enemy.name = DRAGON) {
      hero.exp = xp+400;
    }

  

}


void special(Hero &hero){/*
  if (hero.special == true){
    hero.special = false;
    lucha(dadoheore)=(dadoheore*3)
    lucha();
    

  }else{
    cout << "ERROR: special not available" << endl;
    showMenu();
  }*/
}




int main(int argc,char *argv[]){

  if(argc!=2){ // Si los parámetros no son correctos, el programa termina inmediatamente
    cout << "Usage: " << argv[0] << " <seed>" << endl;
  }
  else{
    srand(atoi(argv[1])); // Introducimos la semilla para generar números aleatorios
    
    // Aquí vendrá todo tu código del "main"...
    Hero hero;
    Enemy enemy;
    hero = createHero();
    enemy = createEnemy();
    showMenu(hero,enemy);

  }
}
