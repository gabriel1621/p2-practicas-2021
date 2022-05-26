#include "Betonski.h"
#include <string.h>
#include "Util.h"
#include <vector>

Betonski::Betonski(string name){
    
    if (name.length()<1){
        throw EXCEPTION_NAME;
    }
    else{
        this->name=name;
        captured=false;
        anger=0;
        Coordinate position;
    }

}
Coordinate Betonski::getPosition() const{
    return position;
}
void Betonski::capture(){
    captured=true;
    
}
void Betonski::setPosition(const Coordinate &coord){

    position=coord;
}
int Betonski::calculateValue() const{
    int suma=0;
    
    for (unsigned int i=0;i<bag.size();i++){
        suma=suma+bag[i].getValue();
    }
    return suma;
}
int Betonski::calculateValue(JunkType type) const{
    int suma=0;
    for (unsigned int i=0;i<bag.size();i++){
       if (bag[i].getType()==type){ 
        suma=suma+bag[i].getValue();}
    }
    return suma;

}
int Betonski::spoliation(){
    
    if (isCaptured()==false){
        throw BETONSKI_NOT_CAPTURED;
    }
    else{
        int spoli=calculateValue()+anger;

        if(spoli>5000){
            anger=0;
            captured=false;
            throw EXCEPTION_REBELION;

        }
        else{
            anger=anger+calculateValue();
            for (int i=bag.size();i>0;--i){
                bag.erase(bag.begin()+i);
            }
            
        }
        return calculateValue();
    }
    

}
int Betonski::spoliation(JunkType type){
    
    if (isCaptured()==false){
        throw BETONSKI_NOT_CAPTURED;
    }
    else{
        int valor = calculateValue(type);
        int spoli=calculateValue(type)+anger;
        if(spoli>5000){
            anger=0;
            captured=false;
            throw EXCEPTION_REBELION;

        }
        else{
            anger=anger+calculateValue(type);
            for (unsigned int i=0;i<bag.size();i++){
                if (bag[i].getType()==type){
                    bag.erase(bag.begin()+i);
                    i--;

                }

            }
            
           
        }
        return valor;
    }
    

}
int Betonski::extract(Map &map){
    if(map.isInside(position)){
     Junk nuevorecu;
     JunkType ntypo;
     nuevorecu=map.collectJunk(position);
     ntypo=nuevorecu.getType();
     
        if (ntypo!=WASTELAND){
            bag.push_back(nuevorecu);

            return (nuevorecu.getValue());
        }
        else{
            return 0;
        }

    }
    else{
        throw EXCEPTION_OUTSIDE;
    }
    
}
bool Betonski::move(const Map &map){
    if (map.isInside(position)==true){
        
        int num=Util::getRandomNumber(8);
        int rowa=position.getRow();
        int columna=position.getColumn();
        
        Coordinate nposition;
        switch(num){
            case 0:
                nposition.setRow(rowa-1);
                nposition.setColumn(columna);
                break;
            case 1:
                nposition.setRow(rowa-1);
                nposition.setColumn(columna+1);
                break;
            case 2:
                nposition.setRow(rowa);
                nposition.setColumn(columna+1);
                break;    
            case 3:
                nposition.setRow(rowa+1);
                nposition.setColumn(columna+1);
                break;
            case 4:
                nposition.setRow(rowa+1);
                nposition.setColumn(columna);
                break;
            case 5:
                nposition.setRow(rowa+1);
                nposition.setColumn(columna-1);
                break;
            case 6:
                nposition.setRow(rowa);
                nposition.setColumn(columna-1);
                break;
            case 7:
                nposition.setRow(rowa-1);
                nposition.setColumn(columna-1);
                break;

        }
        if(map.isInside(nposition)){
            setPosition(nposition);
            return true;
        }
        else{
            return false;
        }
        

    }
    else{
        throw EXCEPTION_OUTSIDE;
    }

}
string Betonski::traduCapture() const{
    if (isCaptured()){
        return " Captured ";
    }
    else{
       return " Free ";
    }

}
ostream& operator<<(ostream &os,const Betonski &betonski){
    
    
   
        os<<"Betonski "<<'"'<<betonski.getName()<<'"'<<betonski.traduCapture()<<betonski.getAnger()<<betonski.getPosition()<<endl;
    if (betonski.bag.size()==0){
        os<<"";
    }
    else{
       for (unsigned int i=0;i<betonski.bag.size();i++){
           JunkType tipo=betonski.bag[i].getType();
            os<<'['<<betonski.bag[i].conversion(tipo)<<':'<<betonski.bag[i].getQuantity()<<"] ";
        }
    }
    return os;
}
