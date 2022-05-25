#include "Map.h"
#include "Junk.h"
#include "Util.h"
#include <vector>

Map::Map(int rows, int columns){

    if ((rows<5)||(columns<5)){
        throw EXCEPTION_SIZE;
    }
    else{
        this->rows=rows;
        this->columns=columns;
        vector <Junk> recursos;
        for (int i=0;i<columns;i++){
        

         for (int j=0;j<rows;j++){
                Junk recurso;
            
            
                recursos.push_back(recurso);

            
            }
            junks.push_back(recursos);
        
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
void Map::putJunk(const Junk &junk,const Coordinate &coord){
    if (isInside(coord)==true){
        junks[coord.getRow()][coord.getColumn()] = junk;

        
    }
    else{
        throw EXCEPTION_OUTSIDE;
    }
}
Junk Map::getJunk(const Coordinate &coord) const{
    if (isInside(coord)==true){ 
               
        return (junks[coord.getRow()][coord.getColumn()] );
    }
    else{
        throw EXCEPTION_OUTSIDE;
    }


}
Junk Map::collectJunk(const Coordinate &coord){
    Junk rmplaza,rtunjunk;
    if (isInside(coord)==true){ 
        
        
        rtunjunk=junks[coord.getRow()][coord.getColumn()];
        junks[coord.getRow()][coord.getColumn()]=rmplaza;
        return rtunjunk;
    }
    else{
        throw EXCEPTION_OUTSIDE;
    }
}
char Map::charType(int row, int column)const{
    
    Junk recuposicion;
    recuposicion = junks[row][column];
    JunkType typo;
    
    typo=recuposicion.getType();
    char letratipo;

   switch (typo){
        case WASTELAND:
            letratipo=' ';
            break;
        case GOLD:
            letratipo='G';
            break;
        case METAL:
            letratipo='M';
            break;
        case FOOD:
            letratipo='F';
            break;
        case STONE:
            letratipo='S';
            break;
    }
    return letratipo;
}

ostream& operator<<(ostream &os,const Map &map){
    os <<"   ";

    
    
        for (int i=0;i<map.rows;i++){
            
           if (i<10){
              os<<"0"<<i<<" ";
              
            }
            else{
                os <<i<<" ";
                
            }   
            
        }
        os <<endl;

        for (int j=0;j<map.rows;j++){
            for (int x=0;x<map.columns;x++){
           
                if (x==0){
                    int num =x+j;
                    if (num<10){
                     os<<"0"<<num<<" ";
              
                    }
                    else{
                        os <<num<<" ";

                    }   
                }
                else{

                  os <<map.charType(j,x)<<"  ";
                }
           

            } 
            os <<endl;
        } 
    return os;
}