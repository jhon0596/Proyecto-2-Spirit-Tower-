//
// Created by grero on 7/14/2020.
//

#include "Espectro.h"

int Espectro::get_v_ruta() {
    return this->v_ruta;
}

int Espectro::get_v_patrulla() {
    return this->v_patrulla;
}

Espectro::Espectro(int campo_vision, LinkedList *ruta, Node *posicion, int v_ruta, int v_patrulla) {
    this->set_campo_vision(campo_vision);
    this->set_ruta(ruta);
    this->set_posicion(posicion);
    this->set_v_ruta(v_ruta);
    this->set_v_patrulla(v_patrulla);
    this->posruta = new LinkedList();
    this->rutacorta = new LinkedList();
    this->pos->set_x(this->get_ruta().getHead()->get_x()) ;
    this->pos->set_y(this->get_ruta().getHead()->get_y());
    this->contador = 0;
}

void Espectro::set_v_patrulla(int vPatrulla) {
    this->v_patrulla = vPatrulla;

}

void Espectro::set_v_ruta(int vRuta) {
    this->v_ruta = vRuta;

}

Node* Espectro::move() {
    if (this->rutacorta->getHead() != NULL){
        if (contador == 1||(this->rutacorta->getLast()->get_x() == this->pos->get_x() && this->rutacorta->getLast()->get_y() == this->pos->get_y())){
            this->pos = this->rutacorta->backtracking();
            contador = 1;
            return nullptr;
        }
        else {
            this->pos = this->rutacorta->getLast();
            return nullptr;
        }
    }
    else if (movpos < this->get_ruta().getSize() && movneg == 0){
        Node* aux = this->get_ruta().getNode(movpos);
        movpos++;
        this->pos = aux;
        contador = 0;
        return aux;

    }
    else {
        contador = 0;
        movneg = 1;
        movpos --;
        this->pos = this->get_ruta().getNode(movpos);
        return this->get_ruta().getNode(movpos);
    }
    if (movpos == 0 && movneg == 1){
        movneg = 0;

    }


}

void Espectro::pathfinding(Node *inicio, Node *final) {
    int cuadricula[FILA][COLUMNA];
    int i,j;
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
    iniciarNodos(cuadricula);
    pathfindaux(cuadricula,inicio->get_x(),inicio->get_y(),final->get_x(),final->get_y());
    dibujar(cuadricula,inicio, final);

}

int Espectro::heuristico(int fila1, int columna1, int fila2, int columna2) {
    int fila=(abs(fila2-fila1)*10);
    int columna=(abs(columna2-columna1)*10);
    return max(fila, columna);
}

int Espectro:: info(int vet[FILA][COLUMNA], int i, int j ){
    if(vet[i][j]==1)
        return 1;
    else if(vet[i][j]==0)
        return 0;
}

void Espectro:: iniciarNodos(int vet[FILA][COLUMNA]){
    int i,j;
    for(i=0;i<FILA;i++){
        for(j=0;j<COLUMNA;j++){
            node[i][j].caminable=info(vet,i,j);
            node[i][j].lista_abierta=0;
            node[i][j].lista_cerrada=0;
            node[i][j].g=0;
            node[i][j].h=0;
            node[i][j].f=node[i][j].g+node[i][j].h;
            node[i][j].padre_fila=0;
            node[i][j].padre_columna=0;
        }

    }
}

void Espectro:: pathfindaux(int vet[FILA][COLUMNA], int inicioF, int inicioC, int objetivoF, int objetivoC){
    int i,j;
    int dfila, dcolumna;
    int filaactual=inicioF;
    int columnaactual=inicioC;
    node[filaactual][columnaactual].h = heuristico(filaactual, columnaactual, objetivoF,objetivoC);
    node[filaactual][columnaactual].f = node[filaactual][columnaactual].g + node[filaactual][columnaactual].h;
    node[filaactual][columnaactual].lista_abierta=1;

    while(filaactual != objetivoF || columnaactual !=objetivoC ){
        int menorF=10000;
        for(i=0;i<FILA;i++){
            for(j=0;j<COLUMNA;j++){
                if(node[i][j].lista_abierta==1){
                    if(node[i][j].f<menorF){
                        filaactual=i;
                        columnaactual=j;
                        menorF=node[filaactual][columnaactual].f;
                    }
                }
            }
        }

        node[filaactual][columnaactual].lista_abierta=0;
        node[filaactual][columnaactual].lista_cerrada=1;

        for(dfila=-1; dfila<=1; dfila++){
            for (dcolumna=-1; dcolumna<=1; dcolumna++){
                if(node[filaactual+dfila][columnaactual+dcolumna].caminable==1 && node[filaactual+dfila][columnaactual+dcolumna].lista_cerrada==0){//duda
                    if(node[filaactual+dfila][columnaactual+dcolumna].lista_abierta==0){
                        node[filaactual+dfila][columnaactual+dcolumna].lista_abierta=1;
                        node[filaactual+dfila][columnaactual+dcolumna].lista_cerrada=0;
                        node[filaactual+dfila][columnaactual+dcolumna].padre_fila=filaactual;
                        node[filaactual+dfila][columnaactual+dcolumna].padre_columna=columnaactual;
                        if(dfila==0 || dcolumna==0)
                            node[filaactual+dfila][columnaactual+dcolumna].g = node[filaactual][columnaactual].g+10;
                        else
                            node[filaactual+dfila][columnaactual+dcolumna].g=node[filaactual][columnaactual].g+14;
                        node[filaactual+dfila][columnaactual+dcolumna].h = heuristico((filaactual+dfila),(columnaactual+dcolumna),objetivoF,objetivoC);//duda
                        node[filaactual+dfila][columnaactual+dcolumna].f=node[filaactual+dfila][columnaactual+dcolumna].g+node[filaactual+dfila][columnaactual+dcolumna].h;//duda
                    }
                    else {
                        if(dfila==0 || dcolumna==0){
                            if  (node[filaactual+dfila][columnaactual+dcolumna].g==14){
                                node[filaactual+dfila][columnaactual+dcolumna].padre_fila=filaactual;
                                node[filaactual+dfila][columnaactual+dcolumna].padre_columna=columnaactual;
                                node[filaactual+dfila][columnaactual+dcolumna].g=10;
                                node[filaactual+dfila][columnaactual+dcolumna].h=heuristico((filaactual+dfila),(columnaactual+dcolumna),objetivoF,objetivoC);//duda
                                node[filaactual+dfila][columnaactual+dcolumna].f=node[filaactual+dfila][columnaactual+dcolumna].g+node[filaactual+dfila][columnaactual+dcolumna].h;//duda

                            }
                        }
                    }
                }
            }
        }
    }

    int auxiliar=1;
    filaactual=objetivoF;
    columnaactual=objetivoC;
    while(filaactual!=inicioF||columnaactual!=inicioC){
        lista[auxiliar].fila=node[filaactual][columnaactual].padre_fila;
        lista[auxiliar].columna=node[filaactual][columnaactual].padre_columna;
        lista[auxiliar].f=node[filaactual][columnaactual].f;
        filaactual=lista[auxiliar].fila;
        columnaactual=lista[auxiliar].columna;
        vet[filaactual][columnaactual]=4;
        if (filaactual == inicioF && columnaactual == inicioC){
           // this->posruta->addNode(filaactual, columnaactual);
            this->rutacorta->addNode(this->posruta->getLast()->get_x(),this->posruta->getLast()->get_y());
            cout<<"Posible ruta lista"<<endl;
            this->posruta = new LinkedList();
        }

        else{
            this->posruta->addNode(filaactual, columnaactual);
        }

    }

}


//metodo que ilustra en consola el resultado de la busqueda del camino a atraves de la cuadricula definida
void Espectro:: dibujar(int vet[FILA][COLUMNA], Node* inicio, Node* final){
    int i,j;
    for(i=0; i<FILA; i++){
        for (j=0; j<COLUMNA; j++){
            if (i==0){
                printf("P|");
                continue;
            }
            else if (j==0){
                printf("P|");
                continue;
            }
            else if (i==FILA-1){
                printf("P|");
                continue;
            }
            else if (j==COLUMNA-1){
                printf("P|");
                continue;
            }
                //S = Start, representara nuestra posicion inicial en la cuadricula
            else if(i== inicio->get_x() && j==inicio->get_y()){
                printf("S|");
                continue;
            }
                //G = Goal, representara la posicion a la que queremos llegar en la cuadricula
            else if(i==final->get_x() && j==final->get_y()){
                printf("G|");
                continue;
            }
                //X se colocara en cada uno de los nodos o casillas de la cuadricula por los que pasamos para llegar hasta la ruta
            else if(vet[i][j]==4){
                printf("X|");
                continue;
            }

            else if(vet[i][j]==1){
                printf(" |");
                continue;
            }
            else if(vet[i][j]==0)
                printf("P|");
        }

        printf("\n");
    }

}

LinkedList *Espectro::get_rutacorta() {
    return this->rutacorta;
}

void Espectro::set_rutacorta(LinkedList *route) {
    this->rutacorta = route;

}

Node *Espectro::get_pos() {
    return this->pos;
}



