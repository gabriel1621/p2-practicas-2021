#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>

using namespace std;

const int KMAXSTRING = 50;

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
  char comillas = '\"';
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
bool control_error(string nombre){
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

string create_slug(string nombre){
  string nombre_limpio;
  int recorrido=0;
  char chars[] ="--";

  recorrido=nombre.length();
  
  for(int w=0;w<recorrido;w++){
    nombre[w]=tolower(nombre[w]);//convertir a minusculas
    
  }
  

  for(int r=0;r<recorrido;r++){
    if(isalnum(nombre[r])==0){
       nombre[r]='-';   
    }                       //convertir caracters especiales  a "-"
  }
  cout << nombre<<endl;
  for(int t=0;t<recorrido;t++){
    str.erase (std::remove(str.begin(), str.end(), chars[t]), str.end());


  }
  
  return nombre;
}

void addBook(BookStore &bookStore) {
  Book nuevo_libro;
  bool control1,control2,control3,control4;
  
  /*nombre*/
  do{
    cout << "Enter book title:";
    getline(cin,nuevo_libro.title);
    control1=control_error(nuevo_libro.title);
    if (control1==true){
      error(ERR_BOOK_TITLE);
    }
       
    
  }while(control1!=false);

  /*autor*/
  do{
    cout << "Enter author(s):";
    getline(cin,nuevo_libro.authors);
    control2=control_error(nuevo_libro.authors);
    if (control2==true){
      error(ERR_BOOK_AUTHORS);
    }
    
  }while(control2!=false);

  /*año*/
  do{
    string year;
    int longitud=0;
    cout <<"Enter publication year:";
    getline(cin,year);
    longitud=year.length();
    if (longitud>0){
      
      nuevo_libro.year = stoi(year);//convertir string a entero

    }
    if((nuevo_libro.year>=1440) && (nuevo_libro.year<=2022)){

      
      control3=false;
      

    }else{
      error(ERR_BOOK_DATE);
      control3=true;
      
    }
    
    

    

  }while(control3!=false);
  /*precio*/
  do{
    string precio;
    int longitud=0;
    cout <<"Enter price:";
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

  nuevo_libro.slug=create_slug(nuevo_libro.title);
  cout << "slug "<<nuevo_libro.slug << endl;
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

void importExportMenu(BookStore &bookStore) {
  cout << "[Import/export options]" << endl
       <<"1- Import from CSV"<< endl
       <<"2- Export to CSV"<< endl
       <<"3- Load data"<< endl
       <<"4- Save data"<< endl
       <<"b- Back to main menu"<< endl
       <<"Option: ";

}

void importFromCsv(BookStore &bookStore){
}

void exportToCsv(const BookStore &bookStore){
}

void loadData(BookStore &bookStore){
}

void saveData(const BookStore &bookStore){
}

int main(int argc, char *argv[]) {
  BookStore bookStore;
  
  bookStore.name = "My Book Store";
  bookStore.nextId = 1;

  char option;
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
  } while (option != 'q');

  return 0;
}
