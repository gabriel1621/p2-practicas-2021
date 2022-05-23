#include "Map.h"
#include "Junk.h"
#include "Util.h"
#include <vector>

Map::Map(int rows, int columns){

    if ((rows<=5)||(columns<=5)){
        throw EXCEPTION_SIZE;
    }
    else{
        this->rows=rows;
        this->columns=columns;
    }
    
    
    for (int i=0;i<columns;i++){
        

        for (int j=0;j<rows;j++){
            Junk recurso=Junk();
            Junk recursos;
            
            Junk.recursos.push_back(recurso);
            junks.push_back(Junk);
        }

        
    }


}
bool Map::isInside(const Coordinate &coord) const{
    
    if (((coord.getRow()>=0)&&(coord.getRow()<=rows)) || ((coord.getColumn()>0)&&(coord.getColumn()<=columns))){
        return true;
    }
    else{
        return false;
    }


    
}
void Map::putJunk(const Junk &junk,const Coordinate &coord)const{
    /*if (isInside(&coord)==true){
        
        
    }
    else{
        throw EXCEPTION_OUTSIDE;
    }*/
}
Junk Map::getJunk(const Coordinate &coord) const{
   /* if (isInside()==true){
        
        return Junk;
    }
    else{
        throw EXCEPTION_OUTSIDE;
    }

*/
}
Junk Map::collectJunk(const Coordinate &coord)const {
  /*  if (isInside()==true){
        JunkType recursoRemplazado;
        recursoRemplazado=WASTELAND;

        Junk.push_back(recursoRemplazado)

    }
    else{
        throw EXCEPTION_OUTSIDE;
    }
*/
}
ostream& operator<<(ostream &os,const Map &map){
    os<<"";
    /*for(int i=0;i<map.rows;i++){
        for(int j=0;j<map.columns;j++){
            //os<<
        }
    }*/
}