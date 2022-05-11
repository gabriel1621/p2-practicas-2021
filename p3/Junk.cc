#include <"Junk.h">
#include <iostream>

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
    return type[0];

}
int Junk::getValue() const{
    JunkType WASTELAND = 0;
    JunkType GOLD = 500;
    JunkType METAL = 100;
    JunkType FOOD = 50;
    JunkType STONE =20;

    return type*quantity;
}

ostream& operator<<(ostream &os, const Junk &junk){
    os<< "[" << junk.type << ':' << junk.quantity << ']' << endl;

    return os;
}