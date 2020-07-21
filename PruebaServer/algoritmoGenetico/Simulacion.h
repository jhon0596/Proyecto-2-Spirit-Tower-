//
// Created by jrodr on 20/7/2020.
//

#ifndef PRUEBASERVER_SIMULACION_H
#define PRUEBASERVER_SIMULACION_H

#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include "Espectro.h"
#include "LinkendList.h"
#include "algoritmoGenetico.h"
class Simulacion {
public:
    Simulacion();
    void crearEspectros();
    void verEspectros();
    void EspectroGeneraciones();

private:
    algoritmoGenetico vida =algoritmoGenetico();
    LinkedList<Espectro>* listaEspectros = new LinkedList<Espectro>();
};


#endif //PRUEBASERVER_SIMULACION_H
