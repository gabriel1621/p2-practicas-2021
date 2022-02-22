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
/* estructura del heroe*/
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
/*creacion de heroe*/
Hero createHero(){
  Hero hero;
  /*variables auxiliares*/
  char nombre_Heore[KNAME]; //nombre de heroe
  bool error,error2; //control de errores
  float ataque, defensa; //ataque/defensa
  int ataquetotal, defensatotal; //ataque y defensa otorgada al heroe
  int longitud;//logitud del nombre del heroe
  
  do{
    cout << "Enter hero name: ";
    cin.getline(nombre_Heore, KNAME-1);
    error = true ;
    longitud = strlen(nombre_Heore); 
    for(int i=0; i<longitud; i++){
      if((isalnum(nombre_Heore[i]!=1))&&(nombre_Heore[i]!='\0')){
      cout << "ERROR: wrong name" << endl;
      error = false;
      }
    }    
    if ((isalpha(nombre_Heore[0]) == 0)){ //prueba primera letra inicial
      cout << "ERROR: wrong name" << endl;
      error = false;
    }
    else if (longitud==0){
      cout << "ERROR: wrong name" << endl;
      error = false;
    }
    
  
  }while (error != true );
  do{ 
    error2 =0;
    cout << "Enter attack/defense: ";
    cin >> ataque;
    cin.get();  
    cin >> defensa;
    if ((ataque+defensa) != 100) { //comprobar que los dos valores suman 100
      
      cout << "ERROR: wrong distribution" << endl; 
      error2 =1;
    } 
    else { 
      ataquetotal = (ataque/100)*200;
      defensatotal = (defensa/100)*200;
      
    }
  }while (error2 != 0);
  hero.name[KNAME] = nombre_Heore[KNAME];
  hero.features.attack = ataquetotal;
  hero.features.defense = defensatotal;
  hero.features.hp = (hero.features.defense*2);
  hero.special = true;
  hero.exp = 0;
  for (int x =0;x<KENEMIES;++x){
    hero.kills[x]=0 ;
  }
  hero.runaways = 3;
  return hero;
}
/*crecion enemigo*/
void name_enemy(Enemy &enemy);
Enemy createEnemy(){
  Enemy enemy;
  int num_dado;
  enemy.features.defense= 0;
    num_dado = rollDice();
    if (num_dado <=6) {
      enemy.name= (AXOLOTL);
      enemy.features.attack= 40;
      enemy.features.defense= 40;
      enemy.features.hp = (enemy.features.defense*2);}
      
    else if (num_dado <=11) {
      enemy.name= (TROLL);
      enemy.features.attack= 60;
      enemy.features.defense= 80;
      enemy.features.hp = (enemy.features.defense*2);}
      
    else if (num_dado <=15) {
      enemy.name= (ORC);
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
      
  string nombre_enemigo;
  switch (enemy.name){
  case AXOLOTL: nombre_enemigo="Axolotl"; break ;
  case TROLL: nombre_enemigo="Troll"; break;
  case ORC: nombre_enemigo="Orc" ;break;
  case HELLHOUND: nombre_enemigo="Hellhound";break;
  case DRAGON: nombre_enemigo="Dragon";break; }

  cout << "[Enemy]" << endl
        << "Breed: " << nombre_enemigo << endl
        << "Attack: " << enemy.features.attack << endl
       << "Defense: " << enemy.features.defense << endl
       << "Health points: " << enemy.features.hp << endl  ;
  

  return enemy;
}

/*Inicializacion de funciones*/
void showMenu(Hero &hero, Enemy &enemy);
void report(const Hero &hero);
void lucha(Hero &hero, Enemy &enemy);
void fight(Hero &hero,Enemy &enemy);
void runawayfuncion(Hero &hero, Enemy &enemy);
void special(Hero &hero, Enemy &enemy);


/**************************************/
void runawayfuncion(Hero &hero, Enemy &enemy){
  int contador_de_huida=0;
  if (hero.runaways > 0 && contador_de_huida < 2){
   contador_de_huida++;
   hero.runaways--;
   cout << "You run away" << endl;
   createEnemy();
   showMenu(hero,enemy);
  }else{
    cout << "ERROR: cannot run away"<<endl;
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
      << "Exp: " << hero.exp << endl
      << "Enemies killed: "<<endl
      << "- Axolot: "<<hero.kills[0]<<endl
      << "- Troll: "<<hero.kills[1]<<endl
      << "- Orc: "<<hero.kills[2]<<endl
      << "- Hellhound: "<<hero.kills[3]<<endl
      << "- Dragon: "<<hero.kills[4]<<endl
      << "Total: "<<(hero.kills[0]+hero.kills[1]+hero.kills[2]+hero.kills[3]+hero.kills[4])<<endl;
  
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
  switch (opcion) {
    case 49: fight(hero,enemy);break;
    case 50: runawayfuncion(hero,enemy);break;
    case 51: special(hero,enemy);break;
    case 52: report(hero);break;
    case 113: break;
    default :cout << "Error Wrong Option" <<endl;
      showMenu(hero,enemy);

  }
  
}




void fight(Hero &hero,Enemy &enemy){   
  /*lanzamiento de dados*/
    int dadoheore = rollDice();
      dadoheore = (dadoheore*5);
    int dadoenemy = rollDice();
      dadoenemy = (dadoenemy*5);
  /*calculo ataque el ataque y la defensa total*/
    int ataque_inicial = hero.features.attack;
      ataque_inicial = (dadoheore+ataque_inicial);
    int defensa_inicial;
      defensa_inicial = (dadoenemy+enemy.features.defense);
  /*calculo puntos de daño*/
    int hit_points;
      hit_points = (ataque_inicial-defensa_inicial);
      if (hit_points<=0){
        hit_points=0;
      }  
  /*vida del enemigo*/
    int vida_enemy;
    vida_enemy= (enemy.features.hp-hit_points);
    enemy.features.hp=vida_enemy;
  /*salida del ataque por el terminal*/
    cout << "[Hero -> Enemy]" << endl
         << "Attack: " << hero.features.attack << " + " << dadoheore << endl
         << "Defense: " << enemy.features.defense << " + " << dadoenemy << endl
         << "Hit Point: " << hit_points << endl
         << "Enemy health points: " << vida_enemy << endl;
  /*inicio ataque del enemigo*/
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
        if (hit_points_eneMY<=0){hit_points_eneMY=0; } 
        
        
      int vida_heroe;
      
      vida_heroe= (hero.features.hp-hit_points_eneMY);
      hero.features.hp=vida_heroe;
      cout << "[Enemy -> Hero]" << endl
          << "Attack: "<<enemy.features.attack<<"+"<<dadoenemy << endl
          << "Defense: "<<hero.features.defense<<"+"<<dadoheore << endl
          << "Hit Point: "<< hit_points_eneMY << endl
          << "Hero health points: "<<vida_heroe << endl;
      if (vida_heroe>0) {
        showMenu(hero,enemy);
      }
      else{
        cout << "You are dead" << endl;
        report(hero);
        
      }
    }else{    
    
      int xp;
      xp = hero.exp;
      cout << "Enemy Killed" << endl;
      if (enemy.name == AXOLOTL ){
        hero.exp = xp+100;
        hero.kills[0]++;
      }
      else if (enemy.name == TROLL) {
        hero.exp = xp+150;
        hero.kills[1]++;
      }
      else if (enemy.name == HELLHOUND ){
        hero.exp = xp+200;
        hero.kills[2]++;
      }
      else if (enemy.name == ORC ){
        hero.exp = xp+300;
        hero.kills[3]++;
      }
      else if (enemy.name == DRAGON) {
        hero.exp = xp+400;
        hero.kills[4]++;
      }
      createEnemy();    //por esto a lo mejor no se recargan los int de arriba
      showMenu(hero,enemy);
    }
  

}


void special(Hero &hero, Enemy &enemy){
  if (hero.special == true){
    hero.special = false;
    int dadospecial;
    dadospecial=rollDice();
    

  }else{
    cout << "ERROR: special not available" << endl;
    showMenu(hero,enemy);
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
    hero = createHero();
    enemy = createEnemy();
    showMenu(hero,enemy);

  }
}
