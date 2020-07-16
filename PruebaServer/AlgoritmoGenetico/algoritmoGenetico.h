//
// Created by jrodr on 14/7/2020.
//

#ifndef PRUEBASERVER_ALGORITMOGENETICO_H
#define PRUEBASERVER_ALGORITMOGENETICO_H
#include "Espectro.h"
#include "ListaEspectros.h"
#include "Utilities.h"

class algoritmoGenetico {
public:
    AlgoritmoGenetico();
    void swap(NodoEspectro *a, NodoEspectro *b);
    void bubbleSort(ListaEspectros *start);
    void cruzarPoblacion(ListaEspectros* listaEspectros);
    ListaEspectros* LE;
    int Generation;
};


#endif //PRUEBASERVER_ALGORITMOGENETICO_H
