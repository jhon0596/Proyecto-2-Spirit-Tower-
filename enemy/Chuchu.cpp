//
// Created by grero on 7/19/2020.
//

#include "Chuchu.h"


Chuchu::Chuchu(Node *pos) {
    this->set_posicion(pos);
    this-> set_ruta(new LinkedList());
    rutabre = new LinkedList();

}

void Chuchu::set_rutabre(LinkedList *rutabre) {
    this->rutabre = rutabre;

}

LinkedList *Chuchu::get_rutabre() {
    return this->rutabre;
}
//parte de esta funcion se uso de refencia de https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/
void Chuchu::bre(Node *n) {
    if (this->get_posicion()->get_x() != n->get_x() && this->get_posicion()->get_y() != n->get_y()){
    int m_new = 2 * (n->get_y() - this->get_posicion()->get_y());
    int slope_error_new = m_new - (n->get_x() - this->get_posicion()->get_x());
    int y = this->get_posicion()->get_y();
    for (int x = this->get_posicion()->get_x();  x >= n->get_x(); x--)
    {
        this->rutabre->addNode(x,y);

        slope_error_new += m_new;

        if (slope_error_new >= 0)
        {
            y++;
            slope_error_new  -= 2 * (n->get_x() - this->get_posicion()->get_x());
        }
    }
    this->get_ruta()->addNode(this->rutabre->getHead()->getNext()->get_x(), this->rutabre->getHead()->getNext()->get_y());
    this->rutabre = new LinkedList();
}
    else {
        this->get_ruta()->addNode(this->get_posicion()->get_x(),this->get_posicion()->get_y());
    }}

void Chuchu::move() {
        this->set_posicion(this->get_ruta()->getHead());
        this->set_ruta(new LinkedList());

}

