//
// Created by jrodr on 14/7/2020.
//

#include "ListaEspectros.h"

ListaEspectros::ListaEspectros(){
    head = nullptr;
    tail = nullptr;
    size = 0;

}
void ListaEspectros:: add(Espectro *i) {
    NodoEspectro *temp = new NodoEspectro();
    temp->setEspectro(i);
    temp->setNext(nullptr);
    if(head == nullptr){
        head = temp;
        tail= temp;
        temp = nullptr;
    }
    else{
        tail->setNext(temp);
        tail = temp;
    }
    size++;
}

void ListaEspectros::deleteF() {
    NodoEspectro *temp;
    temp = head;
    head = head->getNext();
    delete temp;
    size--;

}

void ListaEspectros::deleteL() {
    NodoEspectro *current;
    NodoEspectro *prev;
    current = head;
    while (current->getNext()!= nullptr){
        prev = current;
        current = current->getNext();
    }
    tail = prev;
    prev->setNext(nullptr);
    size--;
    delete current;
}

int ListaEspectros::getSize() const {
    return size;

}

void ListaEspectros::setSize(int size) {
    ListaEspectros::size = size;
}
ListaEspectros::~ListaEspectros() {
    head= nullptr;
    tail = nullptr;
    size=0;
}