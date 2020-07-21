//
// Created by grero on 7/14/2020.
//

#ifndef ENEMY_AZUL_H
#define ENEMY_AZUL_H
#include "Espectro.h"


class Azul: public Espectro {
private:

public:
    Azul(int campo_vision,LinkedList *ruta, Node *posicion, int v_ruta, int v_patrulla);
    void teletransportar(Node* pos);

};


#endif //ENEMY_AZUL_H
