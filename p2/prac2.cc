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
void error(Error e);
void showMainMenu();
void showCatalog(const BookStore &bookStore);
void showExtendedCatalog(const BookStore &bookStore);
bool addControlError(string nombre);
string slugGenerador(string nombre);
void addBook(BookStore &bookStore);
void deleteBook(BookStore &bookStore);
void showImporExportMenu();
void createBookImport(BookStore &bookStore, string libro_importado);
void stringToChar(string name, char nameConvert[]);
void importFromCsv(BookStore &bookStore, string argumentos, int &badfile);
void exportToCsv(const BookStore &bookStore);
void loadDataProcess(BookStore &bookStore, string argumentos,string fileName, int &badfile);
void loadData(BookStore &bookStore, string argumentos, int &badfile);
void saveData(const BookStore &bookStore );
void importExportMenu(BookStore &bookStore, int &badfile) ;
void ErrorandSelectArgument(vector<string> argumentos, int argc, int &errorArgument, int &binary, int &text);
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
/*mostrará un listado con información resumida de los libros del catálogo*/
void showCatalog(const BookStore &bookStore) {
  int canti_libros=bookStore.books.size();
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
  bool control=false;
  int longitud=0;
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

string slugGenerador(string nombre){
  string nombre_limpio;
  int recorrido=0;
  

  recorrido=nombre.length();
  
  for(int w=0;w<recorrido;w++){
    nombre[w]=tolower(nombre[w]);//convertir a minusculas
    
  }
  

  for(int r=0;r<recorrido;r++){
    if(isalnum(nombre[r])==0){
       nombre[r]=GUION;   
    }                       //convertir caracters especiales  a "-"
  }
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
  if (nombre[0]==GUION){
    nombre.erase(0,1);

  }
  recorrido=nombre.length()-1;
  if (nombre[recorrido]==GUION){
    nombre.erase(recorrido,1);
  }
  
  return nombre;
}

void addBook(BookStore &bookStore) {
  Book nuevo_libro;
  bool errorTitle,errorAutor,control3,control4;
  
  /*nombre*/
  do{
    cout << "Enter book title: ";
    getline(cin,nuevo_libro.title);
    errorTitle=addControlError(nuevo_libro.title);
    if (errorTitle==true){
      error(ERR_BOOK_TITLE);
    }
       
    
  }while(errorTitle!=false);

  /*autor*/
  do{
    cout << "Enter author(s): ";
    getline(cin,nuevo_libro.authors);
    errorAutor=addControlError(nuevo_libro.authors);
    if (errorAutor==true){
      error(ERR_BOOK_AUTHORS);
    }
    
  }while(errorAutor!=false);

  /*año*/
  do{
    string year;
    int longitud=0;
    cout <<"Enter publication year: ";
    getline(cin,year);
    longitud=year.length();
    if (longitud>0){
      
      nuevo_libro.year = stoi(year);//convertir string a entero

    }
    if((nuevo_libro.year>=1440) && (nuevo_libro.year<=2022)){

      
      control3=false;
      

    }
    else{
      error(ERR_BOOK_DATE);
      control3=true;
      
    }
    
    

    

  }while(control3!=false);
  /*precio*/
  do{
    string precio;
    int longitud=0;
    cout <<"Enter price: ";
    getline(cin,precio);
    longitud=precio.length();
    

    if (longitud>0){
      nuevo_libro.price= stof(precio);
     
      
    }
    if(nuevo_libro.price>=0){
      
      control4=false;
    }
    else{
      error(ERR_BOOK_PRICE);
      control4=true;
    }

    
    
    
  }while(control4!=false);

  nuevo_libro.slug=slugGenerador(nuevo_libro.title);
  nuevo_libro.id=bookStore.nextId;
  bookStore.nextId++;
  bookStore.books.push_back(nuevo_libro);

}

void deleteBook(BookStore &bookStore) {
  string id_borrar;
  unsigned int identificador=0;
  int fail=0;
  cout << "Enter book id: ";
  getline(cin,id_borrar);
  
  if (id_borrar.size()<=0){
    error(ERR_ID);
  }

  identificador=stoi(id_borrar);

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
  if (argumentos.length()>0){
    fileName=argumentos;

  }
  else{
    cout << NAMEFILE;
    getline(cin,fileName);
  }

  
  fichero.open(fileName); //abro el fichero

  if(fichero.is_open()){ //compruebo si se puede abrir
    string libro_importado;
    
      
    do{
      while(getline(fichero,libro_importado)){
          createBookImport(bookStore,libro_importado);

      }
      
    }while(!fichero.eof()); //compruebo que ha llegado al final
      

    fichero.close(); //cierro el fichero
  }else{
    error(ERR_FILE);
    if (argumentos.length()>0){
          badfile=1;
        }
  }
}
void createBookImport(BookStore &bookStore, string libro_importado){
  Book nuevo_libro_import;

  string nueva2,nueva3,nueva4;
  string nombre, autor,year,slug,precio;
  bool errorTitle,errorAutor,control3;
  int posicionComa;

  /*Extrael titulo*/
  libro_importado.erase(0,1);
  posicionComa=libro_importado.find(COMILLAS);
  nombre = libro_importado.substr(0,posicionComa);
  nuevo_libro_import.title=nombre;

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
                    
      if ((year.length()>0) && (year != " ")){           
        nuevo_libro_import.year = stoi(year);//convertir string a entero

      }
      if((nuevo_libro_import.year>=1440) && (nuevo_libro_import.year<=2022)){
      control3=false;
      }else{
      error(ERR_BOOK_DATE);
      control3=true;
                  
      }
  /*slug*/
      nueva4 = nueva3.erase(0,posicionComa+1);
      posicionComa=nueva4.find(COMILLAS);
      slug = nueva4.substr(0,posicionComa);
      nuevo_libro_import.slug=slug;

      if(control3==false){
  /*price*/
       precio = nueva4.erase(0,posicionComa+2);             
       if (precio.length()>0){
          nuevo_libro_import.price= stof(precio);      
        }
        if(nuevo_libro_import.price>=0){ 
          control3=false;
        }
        else{
          error(ERR_BOOK_PRICE);
          control3=true;
        }

        nuevo_libro_import.id=bookStore.nextId;
        bookStore.nextId++;
        bookStore.books.push_back(nuevo_libro_import);
                    
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
  if (ficheroEsc.is_open()){
    
    int canti_libros=(int)bookStore.books.size();
    
    
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
  ficheroBinLec.open(fileName,ios::in | ios::binary);
  if (ficheroBinLec.is_open()){
        BinBookStore binBookstoreLoad;
        BinBook binbookLoad;
        Book bookload;
        
        bookStore.books.clear();

          ficheroBinLec.read((char *)&binBookstoreLoad, sizeof(BinBookStore));
          bookStore.name=binBookstoreLoad.name;
          bookStore.nextId=(binBookstoreLoad.nextId);
        

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
  

  if (argumentos.length()>0){
    fileName=argumentos;
    loadDataProcess(bookStore,argumentos, fileName,badfile);
  }
  else{
    do{
    cout << "All data will be erased, do you want to continue (Y/N)?: ";
    getline(cin,preguntaSeguridad);
    comprobar = true;

    if ((preguntaSeguridad == "Y")||(preguntaSeguridad == "y")){
      comprobar = false;
      
      cout << NAMEFILE;
      getline(cin,fileName);

      loadDataProcess(bookStore,argumentos, fileName,badfile);

      

    }
    if((preguntaSeguridad == "N")||(preguntaSeguridad == "n")){
      comprobar = false;
      
    }
    

  }while( comprobar == true);
    
  }
  
  
}
void stringToChar(string name, char nameConvert[]){

  strncpy(nameConvert, name.c_str(), KMAXSTRING-1);
  nameConvert[KMAXSTRING-1]='\0';
}

void saveData(const BookStore &bookStore ){
  char fileName[9000];
  ofstream ficherBinGuardar;
  cout << NAMEFILE;
  cin >> fileName;
  cin.get();

  ficherBinGuardar.open(fileName,ios::out | ios::binary);

  if (ficherBinGuardar.is_open()){
    
    BinBookStore binbookstoreSave;
    binbookstoreSave.nextId=bookStore.nextId;
    stringToChar(bookStore.name,binbookstoreSave.name);
    
    ficherBinGuardar.write((const char *)&binbookstoreSave, sizeof(BinBookStore));
    
    for (int unsigned i=0;i<bookStore.books.size();i++){
      BinBook binbookSave;
      binbookSave.id=bookStore.books[i].id;
      stringToChar(bookStore.books[i].title,binbookSave.title);
      stringToChar(bookStore.books[i].authors,binbookSave.authors);
      binbookSave.year=bookStore.books[i].year;
      stringToChar(bookStore.books[i].slug,binbookSave.slug);
      binbookSave.price=bookStore.books[i].price;

      ficherBinGuardar.write((const char *)&binbookSave, sizeof(BinBook));
     

    }

    ficherBinGuardar.close();
    

    

  }else{
    error(ERR_FILE);
  }


}

void importExportMenu(BookStore &bookStore, int &badfile) {
  char option;
  string argumentos="";
  
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

void ErrorandSelectArgument(vector<string> argumentos, int argc, int &errorArgument, int &binary, int &text){
 /*Control de errores*/
  
  if ((argc==3) || (argc==5)){
    if ((argumentos[1]=="-l") || (argumentos[1]=="-i")){
      if (argc==5){
        if ((argumentos[3]=="-l")||(argumentos[3]=="-i")){
          if (argumentos[1]==argumentos[3]){
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
    if (errorArgument == 0){
      if(argc==3){
        if (argumentos[1]=="-l"){
          binary = 1;
          
        }
        if (argumentos[1]=="-i"){
          text = 1;
        }
      }
      if (argc==5){
        if ((argumentos[1]=="-l") && (argumentos[3]=="-i")){
          binary = 2;
          text=1;
        }
        if ((argumentos[1]=="-i") && (argumentos[3]=="-l")){
          binary = 3;
          text=1;
        }
      }

  }

  
  
}
void argumentprocessor(BookStore &bookStore, int argc, char *argv[], int &errorArgument, int &badfile){
  vector<string> argumentos;
  int binary=0;
  int text=0;
  
  for (int i=0;i<argc;i++){

    argumentos.push_back(argv[i]);
    
  }
    
  ErrorandSelectArgument(argumentos, argc, errorArgument, binary, text);
  
  if (errorArgument==1){

    error(ERR_ARGS);

  }
  
 
 /*orden de ejecucion*/
  if (errorArgument == 0){
    
    if ((binary>0)&&(binary<=3)){
      switch (binary){
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
    else if(text ==1){
      
      importFromCsv(bookStore,argumentos[2],badfile);
    }

  }

}



/*Codigo main */
int main(int argc, char *argv[]) {
  BookStore bookStore;
  
  bookStore.name = "My Book Store";
  bookStore.nextId = 1;
  int errorArgument = 0, badfile=0;
  char option;
  
  if (argc>1){
    //llamar funcion argumentos
    argumentprocessor(bookStore, argc, argv,errorArgument, badfile);

  }
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
