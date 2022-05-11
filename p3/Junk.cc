#include <"Junk.h">
#include <"Util.h" >
#include <iostream>

Junk::Junk(){
    type = WASTELAND;
    quantity = 0;

}
Junk::Junk(JunkType type, int quantity){
    type = type;
    quantity = quantity;

    if(quantity<0){
        Util::error(EXCEPTION_QUANTITY);
    }

}
Junk::JunkType getType() const{
    return type;
}
Junk::int getQuantity() const{
    return quantity;
}
Junk::char getTypeChar() const{

}
Junk::int getValue() const{
    return type*quantity;
}

ostream& operator<<(ostream &os, const Junk &junk){
    os<< "[" << junk.type << ':' << junk.quantity << ']' << endl;
}