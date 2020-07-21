//
// Created by grero on 7/14/2020.
//


#ifndef ENEMY_ENEMIGO_H
#define ENEMY_ENEMIGO_H
#include "Node.h"
#include "LinkedList.h"

class Enemigo {
private:
    int campo_vision;
    Node* posicion;
    LinkedList* ruta;

public:
    int get_campo_vision();
    void set_campo_vision(int campo);
    void set_posicion(Node *pos);
    Node* get_posicion();
    LinkedList * get_ruta();
    void set_ruta(LinkedList *route);
    void atacar();


};


#endif //ENEMY_ENEMIGO_H
