//
// Created by jrodr on 14/7/2020.
//

#ifndef PRUEBASERVER_ESPECTRO_H
#define PRUEBASERVER_ESPECTRO_H
#include <iostream>
#include <random>
#include <string>
#include "stdc++.h"

class Espectro {
public:
    Espectro(std::string nm);
    Espectro(std::string nm, std::string gen);

    std::string display();

    int atributos;
    int resistencia;

    std::string unTag;
    int  atributo[5];
    std::string retCli();
    void fillSPECIAL();
    std::string txt[5]={"velocidadRuta","velocidadPersecucion"," RadioVision","Tipo","Nivel"};
    float calcFitn();
};


#endif //PRUEBASERVER_ESPECTRO_H
