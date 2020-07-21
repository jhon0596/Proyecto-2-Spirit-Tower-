//
// Created by grero on 7/19/2020.
//

#ifndef ENEMY_OJO_H
#define ENEMY_OJO_H
# include "Espectro.h"


class Ojo : public Espectro {
private:
    bool movilidad;
public:
    Ojo(int campo_vision,LinkedList *ruta, Node *posicion, int v_ruta, int v_patrulla);
    bool get_movilidad();
    void set_movilidad(bool movi);
    void moverandom();
};


#endif //ENEMY_OJO_H
