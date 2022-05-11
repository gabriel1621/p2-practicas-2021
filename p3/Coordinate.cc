#include <iostream>
#include <"Coordinate.h">
#include <Util.h>

Coordinate::Coordinate{
    row=-1;
    column=-1;
}

Coordinate::Coordinate(int row, int column){
    row=row;
    column=column;
}

Coordinate::int getRow() const{
    return row;
}

Coordinate::int getColumn() const{
    return colum;
}

Coordinate::void setRow(int row){
   row= Util::getRandomNumber(int max);

} 
Coordinate::void setColumn(int row){
   column= Util::getRandomNumber(int max);

} 

Coordinate::bool compare(const Coordinate &coord){
    return compare;
}

Coordinate::ostream& operator<<(ostream &or,const Coordinate &coord){
    os << '[' << coord.row << ',' << coord.column << ']' << endl;
}