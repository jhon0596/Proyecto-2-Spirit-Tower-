//
// Created by grero on 7/14/2020.
//

#include "Azul.h"

void Azul::teletransportar(Node *pos) {
    this->set_pos(pos);

}

Azul::Azul(int campo_vision, LinkedList *ruta, Node *posicion, int v_ruta, int v_patrulla) : Espectro(campo_vision,
                                                                                                      ruta, posicion,
                                                                                                      v_ruta,
                                                                                                      v_patrulla) {
    this->set_campo_vision(campo_vision);
    this->set_ruta(ruta);
    this->set_posicion(posicion);
    this->set_v_ruta(v_ruta);
    this->set_v_patrulla(v_patrulla);
    this->set_pos(this->get_ruta()->getHead());
    this->set_contador(0);
}
