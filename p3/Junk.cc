#include "Junk.h"



Junk::Junk(){
    type = WASTELAND;
    quantity = 0;

}
Junk::Junk(JunkType type, int quantity){
    this->type = type;
    

    if(quantity<0){
        throw EXCEPTION_QUANTITY;
    }
    else{
        quantity = quantity;
    }

}
JunkType Junk::getType() const{
    return type;
}
int Junk::getQuantity() const{
    return quantity;
}
char Junk:: getTypeChar() const{
    char letratipo;
     switch (type){
        case 0:
            letratipo='W';
            break;
        case 1:
            letratipo='G';
            break;
        case 2:
            letratipo='M';
            break;
        case 3:
            letratipo='F';
            break;
        case 4:
            letratipo='S';
            break;
    }
    return letratipo;

}
int Junk::getValue() const{
    int value=0;

    switch (type){
        case 0:
            value=0;
            break;
        case 1:
            value=500;
            break;
        case 2:
            value=100;
            break;
        case 3:
            value=50;
            break;
        case 4:
            value=20;
            break;
    }

    return value*quantity;
}

ostream& operator<<(ostream &os, const Junk &junk){
    os<< "[" << junk.getType() << ':' << junk.getQuantity() << ']' << endl;

    return os;
}