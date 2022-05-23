#include "Betonski.h"
#include <string.h>
#include "Util.h"

Betonski::Betonski(string name){
    this->name=name;
    captured=false;
    anger=0;
    if (name.length()<1){
        throw EXCEPTION_NAME;
    }

}
Coordinate Betonski::getPosition() const{
    return position;
}
void Betonski::capture(){
    captured=true;
    
}
void Betonski::setPosition(const Coordinate &coord){


}
int Betonski::calculateValue() const{
    //return Junk.getValue();
}
int Betonski::calculateValue(JunkType type) const{

}
int Betonski::spoliation(){
    int spoli=calculateValue()+getAnger();
    if (isCaptured()==false){
        throw BETONSKI_NOT_CAPTURED;
    }
    else{
        if(spoli>5000){
            anger=0;
            throw EXCEPTION_REBELION;

        }
        else{
            //lo funan
        }
    }

}
int Betonski::spoliation(JunkType type){
    int spoli=calculateValue(type)+getAnger();
    if (isCaptured()==false){
        throw BETONSKI_NOT_CAPTURED;
    }
    else{
        if(spoli>5000){
            anger=0;
            throw EXCEPTION_REBELION;

        }
        else{
            //lo funan
        }
    }

}
int Betonski::extract(Map &map){

}
bool Betonski::move(const Map &map) const{
    if (map.isInside(position)==true){
        int num=Util::getRandomNumber(8);
        return true;
        
    }
    else{
        throw EXCEPTION_OUTSIDE;
    }

}
string Betonski::traduCapture() const{
    if (isCaptured()==false){
        return "Free";
    }
    else{
       return "Captured";
    }

}
ostream& operator<<(ostream &os,const Betonski &betonski){
    os<<"Betonski "<<'"'<<betonski.getName()<<'"'<<betonski.traduCapture()<<betonski.getAnger()<<betonski.getPosition()<<endl;
    if (betonski.calculateValue()<1){
        os<<"";
    }
    else{
        os<<"[GOLD:"<<betonski.calculateValue(GOLD)<<"] "
        <<"[STONE:"<<betonski.calculateValue(STONE)<<"] "
        <<"[FOOD:"<<betonski.calculateValue(FOOD)<<"] ";
    }
}
