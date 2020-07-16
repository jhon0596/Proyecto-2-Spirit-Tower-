//
// Created by jrodr on 14/7/2020.
//

#ifndef PRUEBASERVER_NODOESPECTRO_H
#define PRUEBASERVER_NODOESPECTRO_H
#include "Espectro.h"

class NodoEspectro {
public:
    NodoEspectro();
    NodoEspectro *getNext() const;
    void setEspectro(Espectro* espectro);
    void setNext(NodoEspectro* pun);
    Espectro* getEspectro() const;

private:

    Espectro* espectro;
    NodoEspectro *next;

};


#endif //PRUEBASERVER_NODOESPECTRO_H
