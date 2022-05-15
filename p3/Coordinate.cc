#include <iostream>
#include "Coordinate.h"
#include "Util.h"

Coordinate::Coordinate(){
    row=-1;
    column=-1;
}

Coordinate::Coordinate(int row, int column){
    this->row=row;
    this->column=column;
}

int Coordinate:: getRow() const{
    return row;
}

int Coordinate:: getColumn() const{
    return column;
}

void Coordinate:: setRow(int row){
    
    
   this->row=Util::getRandomNumber(row);

} 
void Coordinate:: setColumn(int row){
    
   this->column= Util::getRandomNumber(column);

} 

bool Coordinate::compare(Coordinate &coord) const{
    bool coordenaditas;
    if (this->row != -1){
        if(this->column != -1){
            coordenaditas=true;
        }
        
    }
    else{
        coordenaditas=true;
    }
    return coordenaditas;
}

ostream& operator<<(ostream &os,const Coordinate &coord){
    os << '[' << coord.getRow() << ',' << coord.getColumn() << ']' << endl;
    return os;
}