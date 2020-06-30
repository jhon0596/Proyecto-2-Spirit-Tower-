#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//numero de filas de la cuadricula, se puede modificar segun queramos el tamaño del tablero
#define FILA 10
//numero de columnas de la cuadricula, se puede modificar segun queramos el tamaño del tablero
#define COLUMNA 10
#include <windows.h>
using namespace std;

//posicion donde queremos llegar en la cuadricula
int fila_objetivo= 7;
int columna_objetivo=7;
//posicion donde iniciamos en la cuadricula
int fila_inicial=1;
int columna_inicial=1;

struct lista {
    int fila;
    int columna;
    int f;
} lista[FILA*COLUMNA];

struct node {
    int caminable;
    int lista_abierta;
    int lista_cerrada;
    int f;
    int g;
    int h;
    int padre_fila;
    int padre_columna;
}node[FILA][COLUMNA];

//Metodo encargado de realizar el proceso heuristico entre 2 puntos de la cuadricula utilizando la formula de Manhattan para hallar la distancia entre puntos
int heuristico(int fila1, int columna1, int fila2, int columna2){

    int fila=(abs(fila2-fila1)*10);
    int columna=(abs(columna2-columna1)*10);
    return max(fila, columna);
}

//metodo que retorna 0 si la casilla no es caminable o 1 si lo es.
int info(int vet[FILA][COLUMNA], int i, int j ){

   if(vet[i][j]==1)
       return 1;
   else if(vet[i][j]==0)
       return 0;
}

//metodo que inicializa los valores de cada nodo de la cuadricula
void iniciarNodos(int vet[FILA][COLUMNA]){
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
//metodo que realiza la busqueda del camino mediante A*
                    //vet = vector 2D
void pathfinder(int vet[FILA][COLUMNA], int inicioF, int inicioC, int objetivoF, int objetivoC){
   int i,j;
   int dfila, dcolumna;
   int filaactual=inicioF;
   int columnaactual=inicioC;
   node[filaactual][columnaactual].h = heuristico(filaactual, columnaactual, objetivoF,objetivoC);
   node[filaactual][columnaactual].f = node[filaactual][columnaactual].g + node[filaactual][columnaactual].h;
   node[filaactual][columnaactual].lista_abierta=1;

   while(filaactual != objetivoF && columnaactual !=objetivoC ){
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
   }

}
//metodo que ilustra en consola el resultado de la busqueda del camino a atraves de la cuadricula definida
void dibujar(int vet[FILA][COLUMNA]){
    int i,j;
    for(i=0; i<FILA; i++){
        for (j=0; j<COLUMNA; j++){
            if (i==0){
                printf("%c|",177);
                continue;
            }
            else if (j==0){
                printf("%c|",177);
                continue;
            }
            else if (i==FILA-1){
                printf("%c|",177);
                continue;
            }
            else if (j==COLUMNA-1){
                printf("%c|",177);
                continue;
            }
            //S = Start, representara nuestra posicion inicial en la cuadricula
            else if(i==fila_inicial && j==columna_inicial){
                printf("S|");
                continue;
            }
            //G = Goal, representara la posicion a la que queremos llegar en la cuadricula
            else if(i==fila_objetivo && j==columna_objetivo){
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
                printf("%c|",177);
        }

        printf("\n--------------------\n");
    }

}




int main() {
//creamos la matriz que se usara como tablero, donde 0 coloca un obstaculo en esa posicion y 1 es una posicion caminable
    int cuadricula[FILA][COLUMNA];
    int i,j;
    for(i=0;i<FILA;i++){
        for(j=0;j<COLUMNA;j++){
            //indicamos las coordenadas de la matriz donde queremos colocar el obstaculo
            if(i==0)
                cuadricula[i][j]=0;
            else if(j==0)
                cuadricula[i][j]=0;

            else if(i==4 && j ==4)
                cuadricula[i][j]=0;

            else if (i==FILA-1)
                cuadricula[i][j]=0;
            else if (j==COLUMNA-1)
                cuadricula[i][j]=0;
            else
                cuadricula[i][j]=1;
        }
    }

//Trabajamos sobre el tablero o cuadricula creada
    iniciarNodos(cuadricula);

    //Lo activamos cuando queramos ver la ruta entre los puntos
    //pathfinder(cuadricula,fila_inicial,columna_inicial,fila_objetivo,columna_objetivo);

    //Nos ilustra el tablero, aun sin la ruta trazada entre los puntos
    dibujar(cuadricula);


    return 0;
}
