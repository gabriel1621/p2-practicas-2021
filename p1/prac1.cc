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





Hero createHero(){
  Hero hero;
  char nombre_Heore[KNAME];
  int error;
  int ataque, defensa;
  int ataquetotal, defensatotal;
  do{
    cout << "Enter Hero name: \n ";
    cin >> nombre_Heore;
    if (nombre_Heore == ""){ //prueba de nombre vacio
      cout << "ERROR: Worng Name \n";
      error = 1;
    }
    else if ((isalnum(nombre_Heore[0]) == 0)){ //prueba valores alfanumericos
      cout << "ERROR: Worng Name \n";
      error = 1;
    }
  
  }while (error == 0 );
  do{ 

  cout << "Enter attack/defense \n";
  ataque = cin.get();
  defensa = cin.get();
  
    if (ataque+defensa == 100) { //comprobar que los dos valores suman 100
      ataquetotal = (ataque/100)*200;
      defensatotal = (defensa/100)*200;

    } 
    else{ 
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
/*
Enemy createEnemy(Enemy &enemy){
  Enemy enemy
  int num_dado;
  num_dado = rollDice();
    if num_dado <=6 {
      cout  << "Breed: " << enemy.Breed= 1 << endl
            << "Attack: " << enemy.features.attack= 40 << endl
            << "Defense: " << enemy.features.defense= 40 << endl
            << "Health points: " << enemy.features.hp = (hero.features.defense*2) << endl  }
      
    else if num_dado <=11 {
      cout  << "Breed: " << Enemy.Breed= 2 << endl
            << "Attack: " << Enemy.features.attack= 60 << endl
            << "Defense: " << Enemy.features.defense= 80 <<endl
            << "Health points: ",Enemy.features.hp = (hero.features.defense*2);}
      
    else if num_dado <=15 {
      cout  << "Breed: ",Enemy.Breed= 3;
            << "Attack: ",Enemy.features.attack= 80 ;
            << "Defense: ",Enemy.features.defense= 120;
            << "Health points: ",Enemy.features.hp = (hero.features.defense*2);}
      
    else if  num_dado <=18 {
      cout  << "Breed: ",Enemy.Breed= 3;
            << "Attack: ",Enemy.features.attack= 120 ;
            << "Defense: ",Enemy.features.defense= 100;
            << "Health points: ",Enemy.features.hp = (hero.features.defense*2);}
      
    else if num_dado <=20 {
     cout  << "Breed: ",Enemy.Breed= 3;
            << "Attack: ",Enemy.features.attack= 160 ;
            << "Defense: ",Enemy.features.defense= 140;
            << "Health points: ",Enemy.features.hp = (hero.features.defense*2);}
      
  }
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



int main(int argc,char *argv[]){

  if(argc!=2){ // Si los parámetros no son correctos, el programa termina inmediatamente
    cout << "Usage: " << argv[0] << " <seed>" << endl;
  }
  else{
    srand(atoi(argv[1])); // Introducimos la semilla para generar números aleatorios
    
    // Aquí vendrá todo tu código del "main"...
    Hero hero;
    Enemy enemy;
    createHero();
    createEnemy();
    showMenu();
  }
}
*/