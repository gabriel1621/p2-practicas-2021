#ifndef _Betonski_h
#define _Betonski_h
#include "Coordinate.h"
#include "Map.h"
#include <iostream>
#include "Util.h"

using namespace std;

class Betonski{
    friend ostream& operator<<(ostream &os,const Betonski &betonski);
    protected:
        vector<Junk>bag;
        string name;
        int anger;
        bool captured;
        Coordinate position;
    public:
        Betonski(string name);
        string getName() const{return name;}
        int getAnger() const{return anger;}
        bool isCaptured() const{return captured;}
        Coordinate getPosition() const;
        void capture();
        void setPosition(const Coordinate &coord);
        int calculateValue()const;
        int calculateValue(JunkType type) const;
        int spoliation();
        int spoliation(JunkType type);
        int extract(Map &map);
        bool move(const Map &map) const;
        string traduCapture() const;
        


        
};

#endif