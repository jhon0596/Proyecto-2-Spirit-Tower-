//
// Created by grero on 7/19/2020.
//

#include "Raton.h"

Raton::Raton(int campo_vision, Node *posicion) {
    int i,j;
    this->set_campo_vision(campo_vision);
    this->set_posicion(posicion);
    for(i=0;i<FILA;i++){
        for(j=0;j<COLUMNA;j++){
            //indicamos las coordenadas de la matriz donde queremos colocar el obstaculo
            if(i==0)
                cuadricula[i][j]=0;
            else if(j==0)
                cuadricula[i][j]=0;
//
            else if(i==2 && (j ==19||j==18||j==17||j==16||j==14||j==13||j==12||j==11||j==10||j==9||j==8||j==7||j==6||j==5||j==4||j==3||j==2))
                cuadricula[i][j]=0;
            else if(i==3 && (j ==4||j==6||j==14||j==16))
                cuadricula[i][j]=0;
            else if(i==4 && (j ==2||j==4||j==6||j==8||j==10||j==12||j==13||j==14||j==15||j==16||j==18))
                cuadricula[i][j]=0;
            else if(i==5 && (j ==2||j==8||j==10||j==18))
                cuadricula[i][j]=0;
            else if(i==6 && (j ==2||j==3||j==4||j==5||j==6||j==7||j==8||j==10||j==12||j==14||j==15||j==16||j==18))
                cuadricula[i][j]=0;
            else if(i==7 && (j ==2||j==4||j==10||j==12||j==14||j==16||j==18))
                cuadricula[i][j]=0;
            else if(i==8 && (j==1||j ==2||j==4||j==5||j==6||j==7||j==8||j==10||j==12||j==14||j==16||j==18))
                cuadricula[i][j]=0;
            else if(i==9 && (j ==2||j==4||j==10||j==12||j==14||j==16||j==18))
                cuadricula[i][j]=0;
            else if(i==10 && (j ==2||j==4||j==5||j==6||j==8||j==9||j==10||j==12||j==14||j==15||j==16||j==18||j==19))
                cuadricula[i][j]=0;
            else if(i==11 && (j ==2||j==12||j==18))
                cuadricula[i][j]=0;
            else if(i==12 && (j ==2||j==4||j==5||j==6||j==7||j==8||j==9||j==10||j==12||j==13||j==14||j==15||j==16||j==18))
                cuadricula[i][j]=0;
            else if(i==13 && (j==6))
                cuadricula[i][j]=0;

//
            else if (i==FILA-1)
                cuadricula[i][j]=0;
            else if (j==COLUMNA-1)
                cuadricula[i][j]=0;
            else
                cuadricula[i][j]=1;
        }
    }

}

void Raton::move() {
    int n = 0 + ( std::rand() % ( 3 - 0 + 1 ));
    std::cout<< n <<std::endl;
    Node* nod = new Node();
    if (n == 0 ){
        if (cuadricula[this->get_posicion()->get_x()][this->get_posicion()->get_y() -1] == 1){
            nod->set_x(this->get_posicion()->get_x());
            nod->set_y(this->get_posicion()->get_y()-1);
            this->set_posicion(nod);
        }
    }
    else if (n == 1){
        if (cuadricula[this->get_posicion()->get_x()-1][this->get_posicion()->get_y() ] == 1){
            nod->set_x(this->get_posicion()->get_x()-1);
            nod->set_y(this->get_posicion()->get_y());
            this->set_posicion(nod);
        }
    }
    else if (n == 2){
        if (cuadricula[this->get_posicion()->get_x()][this->get_posicion()->get_y() +1] == 1){
            nod->set_x(this->get_posicion()->get_x());
            nod->set_y(this->get_posicion()->get_y()+1);
            this->set_posicion(nod);
        }
    }
    else{
        if (cuadricula[this->get_posicion()->get_x()+1][this->get_posicion()->get_y() ] == 1){
            nod->set_x(this->get_posicion()->get_x()+1);
            nod->set_y(this->get_posicion()->get_y());
            this->set_posicion(nod);
        }
    }

}
