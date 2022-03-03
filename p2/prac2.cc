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
  int canti_libros=sizeof(books);
  for (int a=0;a<=canti_libros;a++){
    cout<< book.id<<". "<<book.title<<" "<<book.year<<", "<<book.price<<endl;
  }
}

void showExtendedCatalog(const BookStore &bookStore) {
  int canti_libros=sizeof(books);
  for (int a=0;a<=canti_libros;a++){
    cout << "book.title \"" 
         <<","
         <<"book.author \""
         <<","
         <<book.year
         <<","
         <<"book.slug \""
         <<","
         <<book.price<<endl;
  }
}
bool control_error(BookStore &bookStore){
  return control_error;
}
void create_slug(BookStore &bookStore){
  string nuevo_slug=book.title;
  recorrido=strlen(nuevo_slug);

  for(int w=0;w<recorrido;w++){
    nuevo_slug[w]=tolower(nuevo_slug[w]);//convertir a minusculas
  }

  for(int r=0;r<recorrido;r++){
    if(isalnum(nuevo_slug[r])=!0){
       nuevo_slug[r]='-';   }          //convertir caracters especiales  a "-"
  }

  for(int t=0;t<recorrido;t++){
    if ((nuevo_slug[t] =='-') && (nuevo_slug[t+1] == '-')){

    }
    //eliminar "-" seguidos
  }

}
void addBook(BookStore &bookStore, Book &book) {
  bool error,error2,error3,error4;
  int longitud=0;
  /*nombre*/
  do{
    cout << "Enter book title:";
    cin.getline(book.title,KMAXSTRING-1)
    error=false

    longitud = strlen(book.title);
    for (int i=0;i<longitud;i++){
      if((isalnum(book.title[i])==0) && (book.title[i]!=' ') 
          && (book.title[i]!=',') && (book.title[i]!=':') 
          && (book.title[i]!='-')&& (book.title[i]!='\0')){
        error(ERR_BOOK_TITLE);
        error=true;
      }
    }
    if (longitud==0){
      error(ERR_BOOK_TITLE);
      error=true;
    }
    
  }while(error==false);
  /*autor*/
  do{
    cout << "Enter author(s):";
    cin.getline(book.authors,KMAXSTRING-1)
    error2=false

    longitud = strlen(book.authors);
    for (int i=0;i<longitud;i++){
      if((isalnum(book.authors[i])==0) && (book.authors[i]!=' ') 
          && (book.authors[i]!=',') && (book.authors[i]!=':') 
          && (book.authors[i]!='-')&& (book.authors[i]!='\0')){
        error(ERR_BOOK_TITLE);
        error2=true;
      }
    }
    if (longitud==0){
      error(ERR_BOOK_AUTHORS);
      error2=true;
    }
    
  }while(error2==false);
  /*año*/
  do{
    int year=0;
    int longitud=0;
    cout <<"Enter publication year:";
    cin.getline(year);

    if((book.year<1440) && (book.year>2022)){
      error(ERR_BOOK_DATE);
      error3=true;
    }
    book.year = stoi(year);//convertir enetero a string
    longitud=strlen(book.year);
    if (longitud==0){
      error(ERR_BOOK_DATE);
      error3=true;
    }

  }while(error3==false);
  /*precio*/
  do{
    float price=0;
    int longitud=0;
    cout <<"Enter price:";
    cin.getline(price);

    if(price<=0){
      error(ERR_BOOK_PRICE);
      error4=true;
    }
    bookStore.price = stof(year);//convertir enetero a string
    longitud=strlen(book.price);
    if (longitud==0){
      error(ERR_BOOK_PRICE);
      error4=true;
    }

  }while(error4==false);
  create_slug(bookStore);
}

void deleteBook(BookStore &bookStore) {
  cout << "Enter book id: " << endl;
  cin.getline(BinBook.id);


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
  Book book;
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
        addBook(bookStore,book);
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
