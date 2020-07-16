//
// Created by jrodr on 14/7/2020.
//

#ifndef PRUEBASERVER_LISTAESPECTROS_H
#define PRUEBASERVER_LISTAESPECTROS_H
#include "NodoEspectro.h"

class ListaEspectros {
public:
    ListaEspectros();
    void add(Espectro* i);
    void deleteF();
    void deleteL();
    int getSize() const;
    void setSize(int size);
    NodoEspectro* head,*tail;
    virtual ~ListaEspectros;
private:
    int size;
};


#endif //PRUEBASERVER_LISTAESPECTROS_H
