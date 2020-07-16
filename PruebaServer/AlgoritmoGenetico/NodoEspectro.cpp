//
// Created by jrodr on 14/7/2020.
//

#include "NodoEspectro.h"

NodoEspectro *NodoEspectro::getNext() const {
    return next;

}

void NodoEspectro::setNext(NodoEspectro *pun) {
    this->next = pun;

}

void NodoEspectro::setEspectro(Espectro *espectro) {
    this->espectro=espectro;
}

Espectro* NodoEspectro::getEspectro() const {
    return this->espectro;
}

NodoEspectro::NodoEspectro() {

}