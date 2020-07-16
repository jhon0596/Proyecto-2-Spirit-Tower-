//
// Created by grero on 7/14/2020.
//

#include "Enemigo.h"


int Enemigo::get_campo_vision() {
    return this->campo_vision;
}

void Enemigo::set_campo_vision(int campo) {
    this->campo_vision = campo;
}

void Enemigo::set_posicion(Node *pos) {
    this->posicion = *pos;
}

Node Enemigo::get_posicion() {
    return this->posicion;
}

LinkedList Enemigo::get_ruta() {
    return this->ruta;
}

void Enemigo::set_ruta(LinkedList *route) {
    this->ruta = *route;
}
