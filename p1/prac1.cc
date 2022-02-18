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
  int error;
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
    
  
  }while (error != 0 );
  do{ 

  cout << "Enter attack/defense" << endl;
  ataque = cin.get();
  defensa = cin.get();
  
    if (ataque+defensa == 100) { //comprobar que los dos valores suman 100
      ataquetotal = (ataque/100)*200;
      defensatotal = (defensa/100)*200;

    } 
    else { 
      cout << "Error Worng Distribution"; 
      ataque =0;
    }
  }while (ataque == 0);
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
      enemy.name= "bbbb";
      enemy.features.attack= 60;
      enemy.features.defense= 80;
      enemy.features.hp = (enemy.features.defense*2);}
      
    else if (num_dado <=15) {
      enemy.name= "cccc";
      enemy.features.attack= 80;
      enemy.features.defense= 120;
      enemy.features.hp = (enemy.features.defense*2);}
      
    else if  (num_dado <=18) {
      enemy.name= "dddd";
      enemy.features.attack= 120;
      enemy.features.defense= 100;
      enemy.features.hp = (enemy.features.defense*2);}
      
    else if (num_dado <=20) {
      enemy.Breed= "e";
      enemy.features.attack= 160;
      enemy.features.defense= 140;
      enemy.features.hp = (enemy.features.defense*2);}
      
  
  cout << "Breed: " << enemy.name << endl
        << "Attack: " << enemy.features.attack << endl
        << "Defense: " << enemy.features.defense << endl
        << "Health points: " << enemy.features.hp << endl  ;
  return enemy;
}
/*Inicializacion de funciones
report();
showMenu();

void fight(Hero &hero,Enemy &enemy){   

  do{
    int dadoheore = rollDice();
      dadoheore = (dadoheore*5);
    int dadoenemy = rollDice();
      dadoenemy = (dadoenemy*5);
    int ataque_inicial = Hero.features.attack;
      ataque_inicial = (dadoheore+ataque_inicial);
    int defensa_inicial = Enemy.features.defense;
      defensa_inicial = (dadoenemy+defensa_inicial);
    int hit_points;
      hit_points = (ataque_inicial-defensa_inicial);
      Enemy.features.hp= (Hero.features.hp-hit_points);
    cout << "[Hero -> Enemy]" << endl
         << "Attack: " << ataque_inicial << "+" << dadoheore << endl
         << "Defense: " << defensa_inicial << "+" << dadoenemy << endl
         << "Hit Point: " << hit_points << endl
         << "Enemy health points: " << Enemy.features.hp << endl;
    if (Enemy.features.hp>0){
      int dadoenemy = rollDice();
      dadoenemy = (dadoenemy*5); 
      int dadoheore = rollDice();
      dadoheore = (dadoheore*5);

      int ataque_inicial_eneMY = Enemy.features.attack;
        ataque_inicial_eneMY= (dadoenemy+ataque_inicial_eneMY);
      int defensa_inicial_h = Hero.features.defense;
        defensa_inicial_h= (dadoheroe+defensa_inicial_h);
      int hit_points_eneMY;
        hit_points_eneMY = (Hero.defense-Enemy.attack);
        Hero.features.hp= (Enemy.features.hp-hit_points);
      cout << "[Enemy -> Hero]" << endl
          << "Attack: ",ataque_inicial,"+",dadoenemy << endl
          << "Defense: ",defensa_inicial,"+",dadoheore << endl
          << "Hit Point: ", hit_points << endl
          << "Enemy health points: ",Hero.features.hp << endl
      if Hero.features.hp>0 {
        showMenu();
      }
      else{
        cout << "You are dead";
        report ();
      }
    }

      
  }
  while (Enemy.features.hp<=0){
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

*/

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
  }
}
