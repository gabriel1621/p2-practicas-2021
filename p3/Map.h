#ifndef _Map_h
#define _Map_h

#include <iostream>

using namespace std;

class Map{
    friend ostream& operator<<(ostream &os,const Map &map );
    
    protected:
        int rows;
        int columns;
    public:
        Map(int rows, int columns);
        bool isInside(Coordinate &coord const);
        void putJunk(Junk &junk const, Coordinate &coord const);
        Junk getJunk(Coordinate &coord const);
        Junk collectJunk(Coordinate &coord const);     
        
}

#endif