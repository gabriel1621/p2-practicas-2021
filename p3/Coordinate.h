#ifndef _Coordinate_h
#define _Coordinate_h

#include <iostream>

using namespace std;

class Coordinate{
    friend ostream& operator<<(ostream &os, const Coordinate &coord );
    protected:
        int row;
        int column;
    public:
        Coordinate();
        Coordinate( int row, int column);
        int getRow() const;
        int getColumn() const;
        void setRow(int row){this->row=row;}
        void setColumn(int column){this->column=column;}
        bool compare(Coordinate &coord const) const;
        
}

#endif