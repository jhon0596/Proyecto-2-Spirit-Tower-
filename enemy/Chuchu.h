//
// Created by grero on 7/19/2020.
//

#ifndef ENEMY_CHUCHU_H
#define ENEMY_CHUCHU_H
#include "Enemigo.h"

class Chuchu : public Enemigo {
private:
    LinkedList* rutabre;
public:
    Chuchu(Node* pos);
    void set_rutabre(LinkedList* rutabre);
    LinkedList* get_rutabre();
    void bre(Node* n);
    void move();
};


#endif //ENEMY_CHUCHU_H
