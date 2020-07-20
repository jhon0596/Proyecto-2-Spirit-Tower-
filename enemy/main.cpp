#include <iostream>
#include "LinkedList.h"
#include "Node.h"
#include "Espectro.h"
#include "Rojo.h"
#include "Azul.h"
#include "Raton.h"
#include "Chuchu.h"
#include "Ojo.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    LinkedList *list = new LinkedList();
    list->addNode(3,18);
    list->addNode(3,17);
    list->addNode(4,17);
    list->addNode(5,17);
    list->addNode(5,16);
    list->addNode(5,15);
    list->addNode(5,14);
    list->addNode(5,13);
    list->addNode(6,13);
    list->addNode(7,13);
    list->addNode(8,13);
    list->addNode(9,13);
    list->addNode(10,13);
    list->addNode(11,13);
    list->addNode(11,14);
    list->addNode(11,15);
    list->addNode(11,16);
    list->addNode(11,17);
    list->addNode(12,17);
    list->addNode(13,17);
    list->addNode(13,16);
    list->addNode(13,15);
    list->addNode(13,14);
    list->addNode(13,13);

    LinkedList *list1 = new LinkedList();
    list1->addNode(3,11);
    list1->addNode(4,11);
    list1->addNode(5,11);
    list1->addNode(6,11);
    list1->addNode(7,11);
    list1->addNode(8,11);
    list1->addNode(9,11);
    list1->addNode(10,11);
    list1->addNode(11,11);
    list1->addNode(11,10);
    list1->addNode(11,9);
    list1->addNode(11,8);
    list1->addNode(11,7);
    list1->addNode(11,6);
    list1->addNode(11,5);
    list1->addNode(11,4);
    list1->addNode(10,3);
    list1->addNode(9,3);
    list1->addNode(8,3);
    list1->addNode(7,3);

    LinkedList *list2 = new LinkedList();
    list2->addNode(1,11);
    list2->addNode(1,10);
    list2->addNode(1,9);
    list2->addNode(1,8);
    list2->addNode(1,7);
    list2->addNode(1,6);
    list2->addNode(1,5);
    list2->addNode(1,4);
    list2->addNode(1,3);
    list2->addNode(1,2);
    list2->addNode(1,1);
    list2->addNode(2,1);
    list2->addNode(3,1);
    list2->addNode(3,2);
    list2->addNode(3,3);
    list2->addNode(4,3);
    list2->addNode(5,3);
    list2->addNode(5,4);
    list2->addNode(5,5);
    list2->addNode(5,6);
    list2->addNode(5,7);
    list2->addNode(4,7);
    list2->addNode(3,7);
    list2->addNode(3,8);

    LinkedList *list3 = new LinkedList();
    list3->addNode(3,9);
    list3->addNode(4,9);
    list3->addNode(5,9);
    list3->addNode(6,9);
    list3->addNode(7,9);
    list3->addNode(8,9);
    list3->addNode(9,9);
    list3->addNode(9,8);
    list3->addNode(9,7);
    list3->addNode(9,6);
    list3->addNode(9,5);

    Node *v = new Node();
    Node *inicio = new Node();
    inicio->set_x(1);
    inicio->set_y(1);
    Node *final = new Node();
    final->set_x(0);
    final->set_y(0);
    Espectro *gris = new Espectro(40,list,v,4,23);
    Rojo *rojo = new Rojo(40,list1,v,4,23,16);
    Azul *azul = new Azul(40,list2,v,4,23);
    Node* z = new Node();
    z->set_x(11);
    z->set_y(3);
    Raton *raton = new Raton(40,z);
    Node* t = new Node();
    t->set_x(11);
    t->set_y(3);
    Node* q = new Node();
    q->set_x(3);
    q->set_y(11);
    Chuchu *chuchu = new Chuchu(t);
    Ojo *ojo = new Ojo(40,list3,v,4,4);
   // gris->pathfinding(inicio, final);
    int i = 0;
    while (i != 30){
        if (final->get_x() != 0 && final->get_y() != 0){
            gris->pathfinding(gris->get_pos(), final);
            rojo->pathfinding(rojo->get_pos(),final);
         //   azul->pathfinding(azul->get_pos(),final);

        }

        gris->move();
        std::cout << "GRIS x: " + to_string(gris->get_pos()->get_x()) + " Y:  " + to_string(gris->get_pos()->get_y()) << std::endl;
        rojo->move();
        std::cout << "ROJO x: " + to_string(rojo->get_pos()->get_x()) + " Y:  " + to_string(rojo->get_pos()->get_y()) << std::endl;
      /*
        azul->move();
        std::cout << "AZUL x: " + to_string(azul->get_pos()->get_x()) + " Y:  " + to_string(azul->get_pos()->get_y()) << std::endl;
        raton->move();
        std::cout << "RATON x: " + to_string(raton->get_posicion()->get_x()) + " Y:  " + to_string(raton->get_posicion()->get_y()) << std::endl;
        chuchu->bre(q);
        chuchu->move();
        std::cout << "CHUCHU x: " + to_string(chuchu->get_posicion()->get_x()) + " Y:  " + to_string(chuchu->get_posicion()->get_y()) << std::endl;
       */
        ojo->moverandom();
        if (ojo->get_movilidad()){
        ojo->move();
        }
        std::cout << "OJO x: " + to_string(ojo->get_pos()->get_x()) + " Y:  " + to_string(ojo->get_pos()->get_y()) << std::endl;

        i++;
    }


    return 0;
}
