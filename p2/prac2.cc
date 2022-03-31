#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <fstream> //para trabajar con ficheros
#include <sstream>


using namespace std;

const int KMAXSTRING = 50;
const char COMILLAS = '"';
const char GUION = '-';
const string NAMEFILE = "Enter filename: ";

enum Error {
  ERR_OPTION,
  ERR_BOOK_TITLE,
  ERR_BOOK_AUTHORS,
  ERR_BOOK_DATE,
  ERR_BOOK_PRICE,
  ERR_ID,
  ERR_FILE,
  ERR_ARGS
};

struct Book {
  unsigned int id;
  string title;
  string authors;
  int year;
  string slug;
  float price;
};

struct BinBook {
  unsigned int id;
  char title[KMAXSTRING];
  char authors[KMAXSTRING];
  int year;
  char slug[KMAXSTRING];
  float price;
};

struct BookStore {
  string name;
  vector<Book> books;
  unsigned int nextId;
};

struct BinBookStore {
  char name[KMAXSTRING];
  unsigned int nextId;
};
/**Inicializo todas las funciones*/
/*Muestra los mensajes de error*/
void error(Error e);
/*Menu del main*/
void showMainMenu();
/*Imprime una version resumida del catalogo*/
void showCatalog(const BookStore &bookStore);
/*Imprime una version extensa del catalogo*/
void showExtendedCatalog(const BookStore &bookStore);
/*Compueba que los nombres introducidos son correctos*/
bool addControlError(string nombre);
/*funcion que crea el slug del libro*/
string slugGenerador(string nombre);
/*funcion para añadir un libro*/
void addBook(BookStore &bookStore);
/*funcion para borrar libros*/
void deleteBook(BookStore &bookStore);
/*imprime el menu de la funcion export/import*/
void showImporExportMenu();
/*funcion axiliar para añadir libros des un fichero de texto*/
void createBookImport(BookStore &bookStore, string libro_importado);
/*funcion para pasar string a char*/
void stringToChar(string name, char nameConvert[]);
/*funcion para importar ficheros de texto*/
void importFromCsv(BookStore &bookStore, string argumentos, int &badfile);
/*funcion para exportar a fichero de texto*/
void exportToCsv(const BookStore &bookStore);
/*funcion axiliar para importar ficheros binarios*/
void loadDataProcess(BookStore &bookStore, string argumentos,string fileName, int &badfile);
/*funcion para importar ficheros binarios*/
void loadData(BookStore &bookStore, string argumentos, int &badfile);
/*funcion axiliar para exportar ficheros binarios*/
void saveData(const BookStore &bookStore );
/*menu de la funcion inport/export*/
void importExportMenu(BookStore &bookStore, int &badfile) ;
/*funcion para el control de errores de argumentos
y selesccion de la orden de ejecucion*/
void ErrorandSelectArgument(vector<string> argumentos, int argc, int &errorArgument, int &argBinario, int &argTexto);
/*funcion para procesar y ejecutar las funciones atraves de argumentos*/
void argumentprocessor(BookStore &bookStore, int argc, char *argv[], int &errorArgument, int &badfile);
/*********************************/
void error(Error e) {
  switch (e) {
    case ERR_OPTION:
      cout << "ERROR: wrong menu option" << endl;
      break;
    case ERR_BOOK_TITLE:
      cout << "ERROR: wrong book title" << endl;
      break;
    case ERR_BOOK_AUTHORS:
      cout << "ERROR: wrong author(s)" << endl;
      break;
    case ERR_BOOK_DATE:
      cout << "ERROR: wrong date" << endl;
      break;
    case ERR_BOOK_PRICE:
      cout << "ERROR: wrong price" << endl;
      break;
    case ERR_ID:
      cout << "ERROR: wrong book id" << endl;
      break;
    case ERR_FILE:
      cout << "ERROR: cannot open file" << endl;
      break;
    case ERR_ARGS:
      cout << "ERROR: wrong arguments" << endl;
      break;
  }
}

void showMainMenu() {
  cout << "[Options]" << endl
       << "1- Show catalog" << endl
       << "2- Show extended catalog" << endl
       << "3- Add book" << endl
       << "4- Delete book" << endl
       << "5- Import/export" << endl
       << "q- Quit" << endl
       << "Option: ";
}

void showCatalog(const BookStore &bookStore) {
  //almaceno el tamaño del vector
  int canti_libros=bookStore.books.size(); 
  //con el bucle for imprimo los libros almacenados
  for (int a=0;a<canti_libros;a++){
    cout<< bookStore.books[a].id
        << ". " << bookStore.books[a].title
        << " (" << bookStore.books[a].year << "), "
        << bookStore.books[a].price <<endl;
  }
}

void showExtendedCatalog(const BookStore &bookStore) {
  int canti_libros=(int)bookStore.books.size();
  
  for (int a=0;a<canti_libros;a++){
    cout << COMILLAS << bookStore.books[a].title << COMILLAS
         <<","
         << COMILLAS << bookStore.books[a].authors << COMILLAS
         <<","
         << bookStore.books[a].year
         <<","
         << COMILLAS << bookStore.books[a].slug << COMILLAS
         <<","
         <<bookStore.books[a].price<<endl;
  }
}
bool addControlError(string nombre){
  /*la funcion recibira un string (autor o titulo)
  y me duelve un bool para saber si hay errores*/
  bool control=false;
  int longitud=0;
  /*obtengo la longitud del string para comprobar
  todas las posciones con el bucle*/
  longitud=nombre.length();
  for (int i=0;i<longitud;i++){
      if((isalnum(nombre[i])==0) && (nombre[i]!=' ') 
          && (nombre[i]!=',') && (nombre[i]!=':') 
          && (nombre[i]!=GUION)&& (nombre[i]!='\0')){
           control=true;
      }
    }
    if (longitud==0){
      
      control=true;
    }
  return control;
}
bool controlErrorNumberInt(string num){
  bool control=false;
  int longitud=0;
  /*obtengo la longitud del string para comprobar
  todas las posciones con el bucle*/
  longitud=num.length();
  
  if (longitud>0){

    for (int i=0;i<longitud;i++){
      if(isdigit(num[i])==0){
           control=true;
      }
    }
      
    
  }
  else{
    control=true;
  }
  return control;
}
bool controlErrorNumberFloat(string num){
  bool control=false;
  int longitud=0;
  /*obtengo la longitud del string para comprobar
  todas las posciones con el bucle*/
  longitud=num.length();
  
  if (longitud>0){

    for (int i=0;i<longitud;i++){
      //compre que sea numero y que no contenga . en la primera poscion
      if((isdigit(num[i])==0)&&(num[0]=='.')){ 
        control=true;
      }
    }
      
    
  }
  else{
    control=true;
  }
  return control;
}

string slugGenerador(string nombre){
  /*esta fucion recibe el string nombre y mediante
  una sucesion de bulces y condiciones ire tranformado el
  string hasta obtner el slug*/
  string nombre_limpio;
  int recorrido=0;
  
  recorrido=nombre.length();
  
  for(int w=0;w<recorrido;w++){
    nombre[w]=tolower(nombre[w]);//convertir a minusculas
    
  }
  
  for(int r=0;r<recorrido;r++){

    if(isalnum(nombre[r])==0){
      nombre[r]=GUION;  //convertir caracters especiales  a "-" 
    }                       
  }

  /*Elimino los "-" repetidos comprobando dos
  posiciones de la cadena*/
  int o=0;
  for(int t=0;t<recorrido;t++){
    o=t;
    if(nombre[t]==GUION){
      o++;
      if(nombre[o]==GUION){
        nombre.erase(t,1);
        t--;
      }

    }
    
  }

  //eliminio guines iniciales
  if (nombre[0]==GUION){
    nombre.erase(0,1);

  }

  //elimino guiones finales
  recorrido=nombre.length()-1;
  if (nombre[recorrido]==GUION){
    nombre.erase(recorrido,1);
  }
  
  return nombre;
}

void addBook(BookStore &bookStore) {
  Book nuevo_libro;
  /*Declaro variables para el control de errores*/
  bool errorTitle,errorAutor,erroryear,errorPrecio;
  
  /*nombre*/
  do{

    cout << "Enter book title: ";
    getline(cin,nuevo_libro.title);

    /*llamo a la funcion control de errores*/
    errorTitle=addControlError(nuevo_libro.title);

    if (errorTitle==true){
      error(ERR_BOOK_TITLE);
    }
       
    
  }while(errorTitle!=false);

  /*autor*/
  do{
    cout << "Enter author(s): ";
    getline(cin,nuevo_libro.authors);

    /*llamo a la funcion control de errores*/
    errorAutor=addControlError(nuevo_libro.authors);

    if (errorAutor==true){
      error(ERR_BOOK_AUTHORS);
    }
    
  }while(errorAutor!=false);

  /*año*/
  do{
    string year;
    

    cout <<"Enter publication year: ";
    getline(cin,year);

    //obtengo la longitud y compruebo que no este vacio
    erroryear=controlErrorNumberInt(year);
    if (erroryear==false){
      
      nuevo_libro.year = stoi(year);//convertir string a entero

      //compruebo que esta en el rango de años
      if((nuevo_libro.year>=1440) && (nuevo_libro.year<=2022)){

        erroryear=false;
      
      }
      else{

        error(ERR_BOOK_DATE);
        erroryear=true;
      }

    }
    

    else{

      error(ERR_BOOK_DATE);
      erroryear=true;
    }

  }while(erroryear!=false);

  /*precio*/
  do{
    string precio;

    cout <<"Enter price: ";
    getline(cin,precio);

    errorPrecio=controlErrorNumberFloat(precio);
    
    
    if (errorPrecio!=true){
        
      nuevo_libro.price= stof(precio);//convertir string a float
      if(nuevo_libro.price>=0){
      
        errorPrecio=false;
      }
      else{
        error(ERR_BOOK_PRICE);
        errorPrecio=true;
      }
      
    }

    else{
      error(ERR_BOOK_PRICE);
      errorPrecio=true;
    }

    
  }while(errorPrecio!=false);
  
  nuevo_libro.slug=slugGenerador(nuevo_libro.title);//creo el slug
  
  nuevo_libro.id=bookStore.nextId; //asigno la id
  bookStore.nextId++;//icremento la id 
  bookStore.books.push_back(nuevo_libro); //añado el libro al vector

}

void deleteBook(BookStore &bookStore) {
  string id_borrar;
  unsigned int identificador=0;
  int fail=0;

  //obtengo el id
  cout << "Enter book id: ";
  getline(cin,id_borrar);

  //compruebo que no esta vacio
  if (id_borrar.size()<=0){
    error(ERR_ID);
  }

  //convieto el string a entero
  identificador=stoi(id_borrar);

  /*recorro el vector para buscar coincidencias y saber
  si el id exist*/
  for(int h=0; h<(int)bookStore.books.size();h++){
    if (bookStore.books[h].id==identificador){
      fail++;
      identificador = h;
    }
  }
  
  if (fail==0){
    error(ERR_ID);
  }  
  else{
    //elimnio el libro
    bookStore.books.erase(bookStore.books.begin() +identificador);

  }


}
void showImporExportMenu(){
    cout << "[Import/export options]" << endl
       <<"1- Import from CSV"<< endl
       <<"2- Export to CSV"<< endl
       <<"3- Load data"<< endl
       <<"4- Save data"<< endl
       <<"b- Back to main menu"<< endl
       <<"Option: ";
}

void importFromCsv(BookStore &bookStore, string argumentos, int &badfile){
  
  ifstream fichero;
  string fileName;

  //compruebo si viene por agumento para pedir el nombre del fichero
  if (argumentos.length()>0){
    fileName=argumentos; //asigno el argumento al nombre del archivo

  }
  else{
    cout << NAMEFILE;
    getline(cin,fileName);
  }

  
  fichero.open(fileName); //abro el fichero

  if(fichero.is_open()){ //compruebo si se puede abrir
    string libro_importado;
    
      
    do{//leo todas la lines del ficero

      while(getline(fichero,libro_importado)){ 

        //llamo a la funcion axuliar por cada linea del fichero
        createBookImport(bookStore,libro_importado);

      }
      
    }while(!fichero.eof()); //compruebo que ha llegado al final
      

    fichero.close(); //cierro el fichero
  }
  else{
    error(ERR_FILE);
    /*encaso de veneir por argumento modifico la variable de errores
    para que no muestre el menu*/
    if (argumentos.length()>0){
      badfile=1;
    }
  }
}
void createBookImport(BookStore &bookStore, string libro_importado){
  /*Para importar libros leo el fichro por lineas almacenadolo ennun string
  ese string ire trocendolo para obtener la informacion de cada varible del libro*/
  Book nuevo_libro_import;

  //varibles auxiliras para la moficacion del string
  string nueva2,nueva3,nueva4; 
  string nombre, autor,year,slug,precio;

  bool errorTitle,errorAutor,erroryear,errorPrecio;
  int posicionComa;

  /*Para trocear el string usare las fuciones:
     erase para eliminar cadena sobrante,
     substr para obtener la subcadena 
     find para buscar el caracter que usare de guia tanto 
     para eliminar trozos de la cadena y generar la subcadenas*/

  /*Extrael titulo*/
  libro_importado.erase(0,1); //elimino comillas
  posicionComa=libro_importado.find(COMILLAS); //busco la siguiente comilla
  nombre = libro_importado.substr(0,posicionComa); //genero subcadena
  nuevo_libro_import.title=nombre; //asigno subcadena al titulo

  errorTitle=addControlError(nuevo_libro_import.title);
  if (errorTitle==true){
    error(ERR_BOOK_TITLE);
  }

  if (errorTitle==false){

  /*autor*/
    nueva2 = libro_importado.erase(0,posicionComa+3);
    posicionComa=nueva2.find(COMILLAS);
    autor = nueva2.substr(0,posicionComa);            
    nuevo_libro_import.authors=autor;

    errorAutor=addControlError(nuevo_libro_import.authors);

    if (errorAutor==true){
      error(ERR_BOOK_AUTHORS);
    }
    if(errorAutor==false){

  /*año*/
      nueva3 = nueva2.erase(0,posicionComa+2);
      posicionComa=nueva3.find(COMILLAS);
      year = nueva3.substr(0,posicionComa-1);         
                    
      erroryear=controlErrorNumberInt(year);
      if (erroryear!=true){
      
        nuevo_libro_import.year = stoi(year);//convertir string a entero

        //compruebo que esta en el rango de años
        if((nuevo_libro_import.year>=1440) && (nuevo_libro_import.year<=2022)){

         erroryear=false;
      
        }
        else{

          error(ERR_BOOK_DATE);
          erroryear=true;
        }

      }
      else{
        error(ERR_BOOK_DATE);
        erroryear=true;
       }
  /*slug*/

      nueva4 = nueva3.erase(0,posicionComa+1);
      posicionComa=nueva4.find(COMILLAS);
      slug = nueva4.substr(0,posicionComa);
      nuevo_libro_import.slug=slug;

  /*price*/
      if(erroryear==false){
      
        precio = nueva4.erase(0,posicionComa+2); 
        errorPrecio=controlErrorNumberFloat(precio);
        
        if (errorPrecio!=true){
          
          nuevo_libro_import.price= stof(precio);//convertir string a float
          if(nuevo_libro_import.price>=0){
        
            errorPrecio=false;
            nuevo_libro_import.id=bookStore.nextId;
            bookStore.nextId++;
            bookStore.books.push_back(nuevo_libro_import);
          }
          else{
            error(ERR_BOOK_PRICE);
            errorPrecio=true;
          }
        
        }

        else{
          error(ERR_BOOK_PRICE);
          errorPrecio=true;
        }

       

        
                    
      }
    }
                
  }
}
void exportToCsv(const BookStore &bookStore){
  ofstream ficheroEsc;
  string fileName;

  cout << NAMEFILE;
  getline(cin,fileName);

  ficheroEsc.open(fileName,ios::out); //abro y si existe lo machaca

  if (ficheroEsc.is_open()){ //compruebo que se puede abrir
    
    int canti_libros=(int)bookStore.books.size();
    
    /*guardo en cada linea de fichero un libro con la estructura pedida*/
    for (int a=0;a<canti_libros;a++){

        ficheroEsc <<  COMILLAS << bookStore.books[a].title << COMILLAS << ","
         << COMILLAS << bookStore.books[a].authors << COMILLAS << ","
         << bookStore.books[a].year << ","
         << COMILLAS << bookStore.books[a].slug << COMILLAS << ","
         << bookStore.books[a].price;
    }

    ficheroEsc.close(); //cierro el fichero
  }
  else{
    error(ERR_FILE);
  }
}
void loadDataProcess(BookStore &bookStore, string argumentos,string fileName, int &badfile){
  ifstream ficheroBinLec;

  ficheroBinLec.open(fileName,ios::in | ios::binary);//abro el fichero binario

  if (ficheroBinLec.is_open()){//compruebo si se puede abrir

    BinBookStore binBookstoreLoad;
    BinBook binbookLoad;
    Book bookload;
        
    bookStore.books.clear();//limpio el vector

    //asigno el nombre de la bookstore y el id
    ficheroBinLec.read((char *)&binBookstoreLoad, sizeof(BinBookStore));
    bookStore.name=binBookstoreLoad.name;
    bookStore.nextId=(binBookstoreLoad.nextId);
        
    //voy grabando los libros
    while(ficheroBinLec.read((char *)&binbookLoad, sizeof(BinBook))){
          
      bookload.id=binbookLoad.id; //id
      bookload.title=binbookLoad.title; //titulo
      bookload.authors=binbookLoad.authors; //autor
      bookload.year=binbookLoad.year; //año
      bookload.slug=binbookLoad.slug; //slug
      bookload.price=binbookLoad.price; //precio

      bookStore.books.push_back(bookload);
    } 
        
    ficheroBinLec.close();
  }
  else{
    error(ERR_FILE);

    if (argumentos.length()>0){
      badfile=1;
    }
  }
}

void loadData(BookStore &bookStore, string argumentos, int &badfile){
  string preguntaSeguridad;
  bool comprobar;
  string fileName;
  
  /*Compruebo si el fichero viene por argumentos*/
  if (argumentos.length()>0){

    //asigno el argumento al nombre del archivo
    fileName=argumentos;

    //llamo a la funcion de cargar libros
    loadDataProcess(bookStore,argumentos, fileName,badfile);
  }
  else{

    do{
    //pregunta de seguridad
    cout << "All data will be erased, do you want to continue (Y/N)?: ";
    getline(cin,preguntaSeguridad);
    comprobar = true;

    if ((preguntaSeguridad == "Y")||(preguntaSeguridad == "y")){

      comprobar = false;

      //pido el nombre del fichero
      cout << NAMEFILE;
      getline(cin,fileName);

      //lamo a la funcion
      loadDataProcess(bookStore,argumentos, fileName,badfile);

    }
    if((preguntaSeguridad == "N")||(preguntaSeguridad == "n")){

      comprobar = false;
      
    }
    

  }while( comprobar == true);
    
  }
  
  
}
void stringToChar(string name, char nameConvert[]){
 //convieto el string en char recortandolo has la constante-1 
  strncpy(nameConvert, name.c_str(), KMAXSTRING-1);
 //asigno en la ultima posicion el caracter '\0' 
  nameConvert[KMAXSTRING-1]='\0';

}

void saveData(const BookStore &bookStore ){
  /*en este caso declaro el nombre del fichero como char para 
  probar las difectes opciones a la hora trabajar con ficheros*/

  char fileName[90];//le asigno un tamaño ya que tiene que ser un char con tamaño constante
  ofstream ficherBinGuardar;

  cout << NAMEFILE;
  cin >> fileName;
  cin.get();

  ficherBinGuardar.open(fileName,ios::out | ios::binary); //abro el fichero

  if (ficherBinGuardar.is_open()){
    
    BinBookStore binbookstoreSave;

    binbookstoreSave.nextId=bookStore.nextId;
    //ayudandome de la funcion paso el nombre de lña bookstore a char
    stringToChar(bookStore.name,binbookstoreSave.name);
    
    //alamaceno el nombre de la book store y el id
    ficherBinGuardar.write((const char *)&binbookstoreSave, sizeof(BinBookStore));
    
    //alaceno libro por libro con el bucle
    for (int unsigned i=0;i<bookStore.books.size();i++){
      BinBook binbookSave;

      binbookSave.id=bookStore.books[i].id; //id
      stringToChar(bookStore.books[i].title,binbookSave.title); //char titulo
      stringToChar(bookStore.books[i].authors,binbookSave.authors); //char autor
      binbookSave.year=bookStore.books[i].year; //año
      stringToChar(bookStore.books[i].slug,binbookSave.slug); //char slug
      binbookSave.price=bookStore.books[i].price; //precio

      ficherBinGuardar.write((const char *)&binbookSave, sizeof(BinBook));
     

    }

    ficherBinGuardar.close();

  }else{
    error(ERR_FILE);
  }


}

void importExportMenu(BookStore &bookStore, int &badfile) {
  char option;
  string argumentos=""; //declaro el argumento vacio para trabajar sin argumentos
  
  do {
    showImporExportMenu();
    cin >> option;
    cin.get();

    switch (option) {
      case '1':
        importFromCsv(bookStore,argumentos,badfile);
        break;
      case '2':
        exportToCsv(bookStore);
        break;
      case '3':
        loadData(bookStore,argumentos,badfile);
        break;
      case '4':
        saveData(bookStore);
        break;
      case 'b':
        break;
      default:
        error(ERR_OPTION);
    }
  } while (option != 'b');

}

void ErrorandSelectArgument(vector<string> argumentos, int argc, int &errorArgument, int &argBinario, int &argTexto){
 /*Control de errores*/
  
  if ((argc==3) || (argc==5)){ //compruebo conatidad de argumentos
    //compruebo si el primer argumero
    if ((argumentos[1]=="-l") || (argumentos[1]=="-i")){ 
      if (argc==5){
        //compruebo si el segundo argumero
        if ((argumentos[3]=="-l")||(argumentos[3]=="-i")){ 
          if (argumentos[1]==argumentos[3]){ //compruebo argumentos repetidos
            errorArgument = 1;
          }

        }
        else{
          errorArgument = 1;
        }

      }
      
    }
    else{
      errorArgument = 1;
    }

  }
  else{
    errorArgument = 1;
  }
  /*Selecionar argumento*/
  /*Voy comprobando el orden de los argumentos y nombre del fichero
  con el que van acopañados*/
    if (errorArgument == 0){
      if(argc==3){
        if (argumentos[1]=="-l"){
          argBinario = 1;
          
        }
        if (argumentos[1]=="-i"){
          argTexto = 1;
        }
      }
      if (argc==5){
        if ((argumentos[1]=="-l") && (argumentos[3]=="-i")){
          argBinario = 2;
          argTexto=1;
        }
        if ((argumentos[1]=="-i") && (argumentos[3]=="-l")){
          argBinario = 3;
          argTexto=1;
        }
      }

  }

  
  
}
void argumentprocessor(BookStore &bookStore, int argc, char *argv[], int &errorArgument, int &badfile){
  vector<string> argumentos; //creo un vector donde almacenar los argumentos
  int argBinario=0;
  int argTexto=0;
  
  for (int i=0;i<argc;i++){

    argumentos.push_back(argv[i]);
    
  }
  //llamo a la funcion donde se comprueban los errores y se marcar el orden de ejecucion
  ErrorandSelectArgument(argumentos, argc, errorArgument, argBinario, argTexto);
  
  if (errorArgument==1){

    error(ERR_ARGS);

  }
  
 
 /*orden de ejecucion*/
  if (errorArgument == 0){
    
    if ((argBinario>0)&&(argBinario<=3)){
      switch (argBinario){
        case 1: loadData(bookStore,argumentos[2],badfile);
                break;
        case 2: loadData(bookStore,argumentos[2],badfile);
                importFromCsv(bookStore,argumentos[4],badfile);
                break;
        case 3: loadData(bookStore,argumentos[4],badfile);
                importFromCsv(bookStore,argumentos[2],badfile);
                break;
      }
    }
    else if(argTexto ==1){
      
      importFromCsv(bookStore,argumentos[2],badfile);
    }

  }

}



/*Codigo main */
int main(int argc, char *argv[]) {
  BookStore bookStore;
  
  bookStore.name = "My Book Store";
  bookStore.nextId = 1;
  
  int errorArgument = 0, badfile=0;//variables para mostra o no el menu
  char option;
  
  if (argc>1){
    //llamar funcion argumentos
    argumentprocessor(bookStore, argc, argv,errorArgument, badfile);

  }
  /*con esta condicion evito que el menu se muestre cuando hay fallo en los
  argumentos o al abrir ficheros*/
  if ((argc==1) || ((errorArgument==0) && (badfile==0))){
    do {
      showMainMenu();
      cin >> option;
      cin.get();

      switch (option) {
        case '1':
          showCatalog(bookStore);
          break;
        case '2':
          showExtendedCatalog(bookStore);
          break;
        case '3':
          addBook(bookStore);
          break;
        case '4':
          deleteBook(bookStore);
          break;
        case '5':
          importExportMenu(bookStore, badfile);
          break;
        case 'q':
          break;
        default:
          error(ERR_OPTION);
      }
    }while (option != 'q');
  }
  

  return 0;
}
