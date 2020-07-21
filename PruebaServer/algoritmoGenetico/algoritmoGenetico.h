//
// Created by jrodr on 20/7/2020.
//

#ifndef PRUEBASERVER_ALGORITMOGENETICO_H
#define PRUEBASERVER_ALGORITMOGENETICO_H

#include "LinkendList.h"
#include "Node.h"
#include "Espectro.h"
#include "Utilities.h"
class algoritmoGenetico {
public:
    void swap(Node<Espectro> *a, Node<Espectro> *b);
    void bubbleSort(LinkedList<Espectro> *start);
    void cruzarPoblacion(LinkedList<Espectro>* listaEspectro);
    LinkedList<Espectro>* Le;
    int Generation =0;
};


#endif //PRUEBASERVER_ALGORITMOGENETICO_H
