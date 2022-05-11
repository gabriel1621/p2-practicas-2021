#include <iostream>
#include <"Coordinate.h">
#include <Util.h>

Coordinate::Coordinate{
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
    return colum;
}

void Coordinate:: setRow(int row){
   row= Util::getRandomNumber(int max);

} 
void Coordinate:: setColumn(int row){
   column= Util::getRandomNumber(int max);

} 

bool Coordinate:: compare(const Coordinate &coord){
    return compare;
}

Coordinate::ostream& operator<<(ostream &or,const Coordinate &coord){
    os << '[' << coord.row << ',' << coord.column << ']' << endl;
    return os;
}