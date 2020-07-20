//
// Created by grero on 7/14/2020.
//

#include "Rojo.h"

int Rojo::getCampoIluminacion() const {
    return campo_iluminacion;
}

void Rojo::setCampoIluminacion(int campoIluminacion) {
    campo_iluminacion = campoIluminacion;
}

Rojo::Rojo(int campo_vision, LinkedList *ruta, Node *posicion, int v_ruta, int v_patrulla, int campo_iluminacion) {
    this->set_campo_vision(campo_vision);
    this->set_ruta(ruta);
    this->set_posicion(posicion);
    this->set_v_ruta(v_ruta);
    this->set_v_patrulla(v_patrulla);
    this->setCampoIluminacion(campo_iluminacion);
    this->set_pos(this->get_ruta()->getHead());
    this->set_contador(0);
}
