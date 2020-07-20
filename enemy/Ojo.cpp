//
// Created by grero on 7/19/2020.
//

#include "Ojo.h"


bool Ojo::get_movilidad() {
    return this->movilidad;
}

void Ojo::set_movilidad(bool movi) {
    this->movilidad = movi;
}

Ojo::Ojo(int campo_vision, LinkedList *ruta, Node *posicion, int v_ruta, int v_patrulla) {
    this->set_campo_vision(campo_vision);
    this->set_ruta(ruta);
    this->set_posicion(posicion);
    this->set_v_ruta(v_ruta);
    this->set_v_patrulla(v_patrulla);
    this->set_contador(0);
    this->set_pos(this->get_ruta()->getHead()) ;
    this->movilidad = false;

}

void Ojo::moverandom() {
    int x = rand();
    if (x % 2 == 0){
        this->movilidad = true;
    }
    else {
        this->movilidad = false;
    }


}
