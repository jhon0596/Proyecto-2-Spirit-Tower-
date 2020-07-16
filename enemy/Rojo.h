//
// Created by grero on 7/14/2020.
//

#ifndef ENEMY_ROJO_H
#define ENEMY_ROJO_H
#include "Espectro.h"


class Rojo: public Espectro {
private:
    int campo_iluminacion;

public:
    void get_campo_iluminacion();
};


#endif //ENEMY_ROJO_H
