//
// Created by grero on 7/19/2020.
//

#ifndef ENEMY_RATON_H
#define ENEMY_RATON_H
#include "Enemigo.h"
//numero de filas de la cuadricula, se puede modificar segun queramos el tamaño del tablero
#define FILA 15
//numero de columnas de la cuadricula, se puede modificar segun queramos el tamaño del tablero
#define COLUMNA 21

class Raton : public Enemigo {
private:
    int cuadricula[FILA][COLUMNA];

public:
    Raton(int campo_vision,Node* posicion);
    void move();
};


#endif //ENEMY_RATON_H
