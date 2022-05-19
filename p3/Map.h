#ifndef _Map_h
#define _Map_h
#include "Junk.h"
#include "Coordinate.h"
#include <iostream>

using namespace std;

class Map{
    friend ostream& operator<<(ostream &os,const Map &map );
    
    protected:
        int rows;
        int columns;
    public:
        Map(int rows, int columns);
        bool isInside(const Coordinate &coord )const;
        void putJunk(const Junk &junk, const Coordinate &coord )const;
        Junk getJunk(const Coordinate &coord )const;
        Junk collectJunk(const Coordinate &coord )const;     
        
};

#endif