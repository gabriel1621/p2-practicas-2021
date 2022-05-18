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
        this->quantity = quantity;
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
        case WASTELAND:
            letratipo='W';
            break;
        case GOLD:
            letratipo='G';
            break;
        case METAL:
            letratipo='M';
            break;
        case FOOD:
            letratipo='F';
            break;
        case STONE:
            letratipo='S';
            break;
    }
    return letratipo;

}
int Junk::getValue() const{
    int value=0;
    
   switch (this->type){
        case WASTELAND:
            value=0;
            break;
        case GOLD:
            value=500;
            break;
        case METAL:
            value=100;
            break;
        case FOOD:
            value=50;
            break;
        case STONE:
            value=20;
            break;
    }

    return value*quantity;
}
string Junk::conversion(JunkType type) const{
    string typee;
    switch(type){
        case WASTELAND:
            typee="WASTELAND";
            break;
        case GOLD:
            typee="GOLD";
            break;
        case METAL:
            typee="METAL";
            break;
        case FOOD:
            typee="FOOD";
            break;
        case STONE:
            typee="STONE";
            break;
    }
    return typee;
}
ostream& operator<<(ostream &os, const Junk &junk){
    JunkType tipo=junk.getType();
    os<< "[" << junk.conversion(tipo) << ':' << junk.getQuantity() << ']' << endl;

    return os;
}