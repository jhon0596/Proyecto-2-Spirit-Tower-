//
// Created by jrodr on 20/7/2020.
//

#ifndef PRUEBASERVER_ESPECTRO_H
#define PRUEBASERVER_ESPECTRO_H
#include <iostream>
#include <random>
#include <string>
#include "stdc++.h"

class Espectro {
public:
    Espectro();

    Espectro(std::string nm);

    Espectro(std::string nm,std::string gen);

    Espectro(std::string nm, int vr, int vp, int rv, int ataque, int defensa);

    std::string display();



    int atributos=0;
    int vida=0;
    int gen;
    std::string unTag;
    int  atributo[5]={0,0,0,0,0};
    void fillSPECIAL();
    std::string txt[5]={"vr","vp","rv","ataque","defensa"};
    float calcFitn();
};




#endif //PRUEBASERVER_ESPECTRO_H
