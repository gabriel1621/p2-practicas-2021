#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <fstream> //para trabajar con ficheros
#include <sstream>


using namespace std;

const int KMAXSTRING = 50;
const char comillas = '"';
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
    cout << comillas << bookStore.books[a].title << comillas
         <<","
         << comillas << bookStore.books[a].authors << comillas
         <<","
         << bookStore.books[a].year
         <<","
         << comillas << bookStore.books[a].slug << comillas
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
          && (nombre[i]!='-')&& (nombre[i]!='\0')){
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
       nombre[r]='-';   
    }                       //convertir caracters especiales  a "-"
  }
  int o=0;
  for(int t=0;t<recorrido;t++){
    o=t;
    if(nombre[t]=='-'){
      o++;
      if(nombre[o]=='-'){
        nombre.erase(t,1);
        t--;
      }

    }
    
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
  unsigned int identificador=0,fail;
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
void createBookImport(BookStore &bookStore, string libro_importado);
void importFromCsv(BookStore &bookStore){
  
  ifstream fichero;
  string file_name;
  

  cout << NAMEFILE;
  getline(cin,file_name);
  fichero.open(file_name); //abro el fichero

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
  posicionComa=libro_importado.find(comillas);
  nombre = libro_importado.substr(0,posicionComa);
  nuevo_libro_import.title=nombre;

  errorTitle=addControlError(nuevo_libro_import.title);
  if (errorTitle==true){
    error(ERR_BOOK_TITLE);
  }

  if (errorTitle==false){
  /*autor*/
    nueva2 = libro_importado.erase(0,posicionComa+3);
    posicionComa=nueva2.find(comillas);
    autor = nueva2.substr(0,posicionComa);            
    nuevo_libro_import.authors=autor;

    errorAutor=addControlError(nuevo_libro_import.authors);
    if (errorAutor==true){
      error(ERR_BOOK_AUTHORS);
    }
    if(errorAutor==false){
  /*año*/
      nueva3 = nueva2.erase(0,posicionComa+2);
      posicionComa=nueva3.find(comillas);
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
      posicionComa=nueva4.find(comillas);
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
  string file_name;

  cout << NAMEFILE;
  getline(cin,file_name);
  ficheroEsc.open(file_name,ios::out); //abro y si existe lo machaca
  if (ficheroEsc.is_open()){
    
    int canti_libros=(int)bookStore.books.size();
    
    
    for (int a=0;a<canti_libros;a++){
        ficheroEsc <<  comillas << bookStore.books[a].title << comillas << ","
         << comillas << bookStore.books[a].authors << comillas << ","
         << bookStore.books[a].year << ","
         << comillas << bookStore.books[a].slug << comillas << ","
         << bookStore.books[a].price;
    }

    ficheroEsc.close(); //cierro el fichero
  }
  else{
    error(ERR_FILE);
  }
}

void loadData(BookStore &bookStore){
  ifstream ficheroBinLec;
  string preguntaSeguridad;
  bool comprobar;
  char fileName[900];

  
  do{
    cout << "All data will be erased, do you want to continue (Y/N)?: ";
    getline(cin,preguntaSeguridad);
    comprobar = true;

    if ((preguntaSeguridad == "Y")||(preguntaSeguridad == "y")){
      comprobar = false;
      cout << NAMEFILE;
      cin >> fileName;
      cin.get();

      ficheroBinLec.open(fileName,ios::in | ios::binary);
      if (ficheroBinLec.is_open()){
        BinBookStore binBookstoreLoad;
        BinBook binbookLoad;
        bookStore.name=binBookstoreLoad.name;
        bookStore.nextId=binBookstoreLoad.nextId;

        ficheroBinLec.seekg(3*sizeof(bookStore), ios::beg);
        while(ficheroBinLec.read((char *)&bookStore, sizeof(bookStore))){
          binbookLoad.title;
        }

        ficheroBinLec.close();

      }else{
        error(ERR_FILE);
      }

    }
    if((preguntaSeguridad == "N")||(preguntaSeguridad == "n")){
      comprobar = false;
      
    }
    

  }while( comprobar == true);
  
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
    Book bookSave;

    //binbookstoreSave.numbooks=bookStore.books.size();
    ficherBinGuardar.write((const char *)&bookStore, sizeof(BinBookStore));
    for (int i=0;i<bookStore.books.size();i++){

      ficherBinGuardar.write((const char *)&bookStore, sizeof(BookStore));
     // ficherBinGuardar.write((int )&bookStore, sizeof(BookStore));
      //ficherBinGuardar.write((float )&bookStore, sizeof(BookStore));

    }

    ficherBinGuardar.close();
    

    

  }else{
    error(ERR_FILE);
  }


}

void importExportMenu(BookStore &bookStore) {
  char option;
  do {
    showImporExportMenu();
    cin >> option;
    cin.get();

    switch (option) {
      case '1':
        importFromCsv(bookStore);
        break;
      case '2':
        exportToCsv(bookStore);
        break;
      case '3':
        loadData(bookStore);
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
void argumentprocessor(BookStore &bookStore, int argc, char *argv[], int errorArgument){

  int import=0, load=0;

}




int main(int argc, char *argv[]) {
  BookStore bookStore;
  
  bookStore.name = "My Book Store";
  bookStore.nextId = 1;

  char option;
  int errorArgument =0;
  if (argc>1){
    //llamar funcion argumentos
    argumentprocessor(bookStore, argc, argv, errorArgument);

  }
  if ((argc==1) || (errorArgument==0)){
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
          importExportMenu(bookStore);
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
