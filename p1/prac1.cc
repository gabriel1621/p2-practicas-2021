#include <iostream>
#include <cstdlib> // Para rand(), srand() y atoi()
#include <cstring>

using namespace std; //para cin y cout
/*Constantes*/
const int KNAME=32; //longitud del nombre del heroe
const int KENEMIES=5; //numero de heroes
const int KPOINTS=200; //puntos totales
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

  /*creo variables auxiliares que usaré en la crecion del heroe*/
  bool error,error2; //control de errores
  float ataque, defensa; //ataque/defensa introducidos por teclado
  int ataquetotal, defensatotal; //ataque y defensa otorgada al heroe
  int longitud;//logitud del nombre del heroe

  /*uso un do while para el control de errores del nombre
  usando el bool error para cerrar el bucle*/ 
  do{
    cout << "Enter hero name: ";
    cin.getline(hero.name, KNAME-1);
    error = true ;
    longitud = strlen(hero.name); //obtengo la logitud

    /*compruebo que no haya ningun caracter no permitido en todo el nombre*/
    for(int i=0; i<longitud; i++){
      if((isalnum(hero.name[i])==0) && (hero.name[i]!='\0') && (hero.name[i]!=' ') ){
        cout << "ERROR: wrong name" << endl;
        error = false;
      }
    }

    /*compruebo que el primer caracter del nombre sea una letra*/    
    if ((isalpha(hero.name[0]) == 0)){ 
      cout << "ERROR: wrong name" << endl;
      error = false;
    }

    /*compruebo que nombre no esta vacio*/
    else if (longitud==0){
      cout << "ERROR: wrong name" << endl;
      error = false;
    }
    
  
  }while (error != true );

  /*obtengo los valores ataque y defensa*/
  do{ 
    error2 =0;
    cout << "Enter attack/defense: ";
    cin >> ataque;
    cin.get();  
    cin >> defensa;

    /*compruebo que sumen 100 y si los valores son 
    correctos hago la reparticion de puentos*/
    if ((ataque+defensa) != 100) { //comprobar que los dos valores suman 100
      
      cout << "ERROR: wrong distribution" << endl; 
      error2 =1;
    } 
    else { 
      ataquetotal = (ataque/100)*KPOINTS;
      defensatotal = (defensa/100)*KPOINTS;
      
    }
  }while (error2 != 0);

  /*otorgo los valores obtenidos a la estructura del herore*/
  hero.features.attack = ataquetotal;
  hero.features.defense = defensatotal;
  hero.features.hp = (hero.features.defense*2);
  hero.special = true;
  hero.exp = 0;
  /*inicializo el vector de los enemigos a cero*/
  for (int x =0;x<KENEMIES;++x){
    hero.kills[x]=0 ;
  }
  hero.runaways = 3;

  return hero;
}
/*crecion enemigo*/
Enemy createEnemy(){
  Enemy enemy;
  int num_dado;
  num_dado = rollDice();//lazamos el dado

  /*con el valor obtenido en el dado escogemos el enemigo*/
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

  /*guardo en un string el nombre del enemigo
  para luego poder mostrar en vez de el numero eneum*/    
  string nombre_enemigo;
  switch (enemy.name){
  case AXOLOTL: nombre_enemigo="Axolotl"; break ;
  case TROLL: nombre_enemigo="Troll"; break;
  case ORC: nombre_enemigo="Orc" ;break;
  case HELLHOUND: nombre_enemigo="Hellhound";break;
  case DRAGON: nombre_enemigo="Dragon";break; }

  /*muestro en el terminal la estructura final de enemigo*/
  cout << "[Enemy]" << endl
        << "Breed: " << nombre_enemigo << endl
        << "Attack: " << enemy.features.attack << endl
       << "Defense: " << enemy.features.defense << endl
       << "Health points: " << enemy.features.hp << endl  ;

  return enemy;
}

/*************Defino todas las funciones que vamos a usar*********************/

  /*Esta funcion ya dada nos ofrecerá las opciones a usar en la practica*/
    void showMenu(Hero &hero, Enemy &enemy); 

  /*Report: Esta opción mostrará un resumen del estado actual de la partida, 
  donde se ven los datos del héroe y un resumen de los enemigos derrotados*/
    void report(const Hero &hero);

  /*Fight: esta opcion iniciará el ataque entre heroe y enemigo*/
    void fight(Hero &hero,Enemy &enemy);

  /*Runaway: esta funcion nos permitira huir del enemigo un maximo de 3 veces
  y nunca dos veces seguidas*/
    void runawayfuncion(Hero &hero, Enemy &enemy);

  /*Special: nos ofrecera un ataque especial con mucho mas daño del hero, solo
  se podra usar una vez en la partida*/
    void special(Hero &hero, Enemy &enemy);

  /*Esta funcion sumará los puntos de experiencia al heroe tras derrotar un enemigo
  y llevara el contador de enemigos derrotados que podremos ver en la funcion report*/
    void experiencia (Hero &hero, Enemy &enemy);

  /*Esta sera una funcion auxiliar a la funcion fight, en esta fucion el anemigo atacará
  al heroe si todavia continua con vida*/
    void enemy_hero(Hero &hero, Enemy &enemy);

/*****************************************************************************/

void runawayfuncion(Hero &hero, Enemy &enemy){
  /*compruebo que la opcion sigue disponible, en el caso cierto uso "hero.runaways"
  como contador de uso de esta funcion, muestro la huida por el terminal y creo un 
  nuevo enemigo*/
  /*si la opcion ya no esta disponible muestro el error por el terminal y volvera
  al menú de opciones*/
  if (hero.runaways > 0){
   hero.runaways--;
   cout << "You run away" << endl;
   enemy=createEnemy();
   
  }else{
    cout << "ERROR: cannot run away"<<endl;
    
  }
 
  
}

void report(const Hero &hero){
  /*declaro el string printspecial el cual nos mostrara si el ataque especial
  sigue disponible en la partida*/
  string printspecial;
  if (hero.special == true){
    printspecial = "yes";
  }
  else{
    printspecial = "no";
  }
  /*imprimo por el terminal los datos de la funcion report*/
    cout << "[Report]" << endl
      << "Name: " << hero.name << endl
      << "Attack: " << hero.features.attack << endl
      << "Defense: " << hero.features.defense << endl
      << "Health points: " << hero.features.hp << endl
      << "Special: " << printspecial << endl
      <<  "Runaways: " << hero.runaways << endl
      << "Exp: " << hero.exp << endl
      << "Enemies killed: "<<endl
      << "- Axolotl: "<<hero.kills[0]<<endl
      << "- Troll: "<<hero.kills[1]<<endl
      << "- Orc: "<<hero.kills[2]<<endl
      << "- Hellhound: "<<hero.kills[3]<<endl
      << "- Dragon: "<<hero.kills[4]<<endl
      << "- Total: "<<(hero.kills[0]+hero.kills[1]+hero.kills[2]+hero.kills[3]+hero.kills[4])<<endl;
  
}

void showMenu(Hero &hero, Enemy &enemy){
  cout << "[Options]" << endl
          << "1- Fight" << endl
          << "2- Run away" << endl
          << "3- Special" << endl 
          << "4- Report" << endl
          << "q- Quit" << endl
          << "Option: ";
  
}

void experiencia (Hero &hero, Enemy &enemy){
  /*declaro la variable axuliar xp y con la esrtructura condicional apoyandose 
  en los enumerados sumamos la experiencia y el contador de muertes segun el enemigo 
  derrotado. Finalmente se crea otro enemigo para continuar con la   partida*/
  int xp;
    xp = hero.exp;
    cout << "Enemy killed" << endl;//Muestro el mensaje de enemigo derrotado
  
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
      enemy = createEnemy();
      
}

void enemy_hero(Hero &hero, Enemy &enemy){
  /*se lanzan los dados del enemigo y del heroe*/
      int dadoenemy2 = rollDice();
      dadoenemy2 = (dadoenemy2*5); 
      int dadoheore2 = rollDice();
      dadoheore2 = (dadoheore2*5);

  /*calculo los puntos de ataque y defensa*/
      int ataque_inicial_eneMY = enemy.features.attack;
        ataque_inicial_eneMY= (dadoenemy2+ataque_inicial_eneMY);
      int defensa_inicial_h = hero.features.defense;
        defensa_inicial_h= (dadoheore2+defensa_inicial_h);

  /*calculo el daño que recibira el heroe, en caso de ser negativo
  valdra cero*/
      int hit_points_eneMY;
        hit_points_eneMY = (ataque_inicial_eneMY-defensa_inicial_h);
        if (hit_points_eneMY<=0){hit_points_eneMY=0; } 
        
        
  /*actualizo la vida del heroe tras el ataque*/         
      hero.features.hp= (hero.features.hp-hit_points_eneMY);
      if(hero.features.hp<=0){hero.features.hp=0;}
  
  /*muestro en el terminal los datos del ataque*/
      cout << "[Enemy -> Hero]" << endl
          << "Attack: "<<enemy.features.attack<<"+"<<dadoenemy2 << endl
          << "Defense: "<<hero.features.defense<<"+"<<dadoheore2 << endl
          << "Hit points: "<< hit_points_eneMY << endl
          << "Hero health points: "<<hero.features.hp << endl;

  /*compruebo que heroe sigue con vida*/
    if (hero.features.hp>0) {
      }
    else{
      cout << "You are dead" << endl;
      report(hero);
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

  /*calculo puntos de daño, si es negativo sera 0*/
    int hit_points;
      hit_points = (ataque_inicial-defensa_inicial);
      if (hit_points<=0){
        hit_points=0;}

  /*actualizo la vida del enemigo*/    
    enemy.features.hp= (enemy.features.hp-hit_points);
    if (enemy.features.hp<=0){enemy.features.hp=0; }
    

  /*salida del ataque por el terminal*/
    cout << "[Hero -> Enemy]" << endl
         << "Attack: " << hero.features.attack << " + " << dadoheore << endl
         << "Defense: " << enemy.features.defense << " + " << dadoenemy << endl
         << "Hit points: " << hit_points << endl
         << "Enemy health points: " << enemy.features.hp << endl;

  /*Compruebo la vida del enemigo, en caso de seguir vivo el enemigo atacara*/
    if (enemy.features.hp>0){
      /*inicio ataque del enemigo con la funcion enemy_hero*/
        enemy_hero(hero,enemy);
    }else{    
      /*en caso de derrotar el enemigo se sumara la experiencia la heroe*/
      experiencia (hero,enemy);
      
    }
  

}


void special(Hero &hero, Enemy &enemy){
  /*con el concional compruebo si sigue disponible es ataque especial*/
  if (hero.special == true){
      hero.special = false;

  /*lanzamiento de dados*/
    int dadospecial=rollDice(); 
        dadospecial = (dadospecial*5*3);
    int dadoenemy = rollDice();
      dadoenemy = (dadoenemy*5);

  /*calculo ataque el ataque y la defensa total*/
    int ataque_inicial = hero.features.attack;
      ataque_inicial = (dadospecial+ataque_inicial);
    int defensa_inicial;
      defensa_inicial = (dadoenemy+enemy.features.defense);

  /*calculo puntos de daño*/
    int hit_points;
      hit_points = (ataque_inicial-defensa_inicial);
      if (hit_points<=0){
        hit_points=0;
      }  

  /*vida del enemigo*/
    enemy.features.hp= (enemy.features.hp-hit_points);
    if (enemy.features.hp<=0){enemy.features.hp=0; }
    
  /*salida del ataque por el terminal*/
    cout << "[Hero -> Enemy]" << endl
         << "Attack: " << hero.features.attack << " + " << dadospecial << endl
         << "Defense: " << enemy.features.defense << " + " << dadoenemy << endl
         << "Hit points: " << hit_points << endl
         << "Enemy health points: " << enemy.features.hp << endl;

  /*inicio ataque del enemigo*/
    if (enemy.features.hp>0){
        enemy_hero(hero,enemy);
    }else{    
      experiencia (hero,enemy);
    }

  }else{
    cout << "ERROR: special not available" << endl;
    
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
    char opcion;
    bool huida = true;
      do{
        showMenu(hero,enemy);
        cin >> opcion;
        cin.get();
        
          switch (opcion) {
            case '1': huida=true; fight(hero,enemy);break;
            case '2': if(huida==false){
                        cout << "ERROR: cannot run away";
                        break;
                      }else{
                        huida=false;
                        runawayfuncion(hero,enemy);
                        break;
                      }
            case '3': huida=true; special(hero,enemy);break;
            case '4': report(hero);break;
            case 'q': break;
            default :cout << "Error Wrong Option" <<endl;
            
          }
             
        
        
     }while (opcion!='q' && hero.features.hp>0);
    
    return 0;
        
    

  }
}
