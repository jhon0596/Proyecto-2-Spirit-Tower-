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
    Rojo(int campo_vision,LinkedList *ruta, Node *posicion, int v_ruta, int v_patrulla,int campo_iluminacion);
    int getCampoIluminacion() const;

    void setCampoIluminacion(int campoIluminacion);
};


#endif //ENEMY_ROJO_H
