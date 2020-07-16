//
// Created by grero on 7/14/2020.
//

#ifndef ENEMY_ESPECTRO_H
#define ENEMY_ESPECTRO_H
#include "Enemigo.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//numero de filas de la cuadricula, se puede modificar segun queramos el tamaño del tablero
#define FILA 15
//numero de columnas de la cuadricula, se puede modificar segun queramos el tamaño del tablero
#define COLUMNA 21
#include <windows.h>


class Espectro: public Enemigo {
private:
    Node* pos = new Node();
    LinkedList* posruta;
    LinkedList* rutacorta;
    int contador;
    int v_patrulla;
    int v_ruta;
    int movpos;
    int movneg;
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
public:
    Espectro(int campo_vision,LinkedList *ruta, Node *posicion, int v_ruta, int v_patrulla);
    int get_v_patrulla();
    void set_v_patrulla(int vPatrulla);
    int get_v_ruta();
    void set_v_ruta(int vRuta);
    Node* move();
    void pathfinding(Node* inicio, Node* final);
    int heuristico(int fila1, int columna1, int fila2, int columna2);
    int info(int vet[FILA][COLUMNA], int i, int j );
    void iniciarNodos(int vet[FILA][COLUMNA]);
    void pathfindaux(int vet[FILA][COLUMNA], int inicioF, int inicioC, int objetivoF, int objetivoC);
    void dibujar(int vet[FILA][COLUMNA], Node* inicio, Node* final);
    LinkedList* get_rutacorta();
    void set_rutacorta(LinkedList* route);
    Node* get_pos();

};


#endif //ENEMY_ESPECTRO_H
