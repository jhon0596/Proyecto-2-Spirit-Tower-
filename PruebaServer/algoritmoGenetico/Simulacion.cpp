//
// Created by jrodr on 20/7/2020.
//

#include "Simulacion.h"
int tag=0;
Simulacion::Simulacion() {

}

void Simulacion::crearEspectros() {

    for(int i=0;i<10;i++){

        Espectro e1=  Espectro("espectro"+std::to_string(tag));

        tag++;
        listaEspectros->insertAtEnd(e1);
    }
    vida.bubbleSort(listaEspectros);

}
void Simulacion::verEspectros() {
    for (int i = 0; i<listaEspectros->getSize();i++){
         Node<Espectro> *current = listaEspectros->getElement(i);
        std::cout<< current->getData().display();
        std::cout << "\n";

    }

}
void Simulacion::EspectroGeneraciones()  {
    vida.cruzarPoblacion(listaEspectros);

}