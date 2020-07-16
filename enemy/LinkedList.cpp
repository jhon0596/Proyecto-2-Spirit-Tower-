#include "LinkedList.h"
#include<iostream>

LinkedList::LinkedList(){
    size = 0;
    id = 0;
    head = NULL;
    last = NULL;
}

Node* LinkedList::getHead(){
    return head;
}

Node* LinkedList::getLast(){
    return last;
}
void LinkedList::addNode(int x, int y){
    Node* node = new Node(this->id, x, y);
    this->id++;
    if (isEmpty()){
        head = node;
        last = node;
        size++;
    } else {
        Node* current = getHead();
        while(current->getNext() != NULL){
            current = current->getNext();
        }
        current->setNext(node);
        last = node;
        size++;
    }
}
Node* LinkedList::getNode(int id){
    Node* current = getHead();
    while(current->getNext() != NULL){
        if (current->getID() == id){
            return current;
        } else {
            current = current->getNext();
        }
    }
    if (current->getID() == id){
        return current;
    }
    return NULL;
}
void LinkedList::removeNode(int id){
    Node* current = getHead();
    if (current->getID() == id){
        head = current->getNext();
        if (size == 1){
            last = current->getNext();
        }
        size --;
    } else {
        while(current->getNext() != NULL){
            if(current->getNext()->getID() == id){
                current->setNext(current->getNext()->getNext());
                if ( last->getID()== id){
                    last=current;
                }

                size--;
            } else {
                current = current->getNext();
            }
            
        }
        
    }
}
void LinkedList::deletelast(){
    Node* current = getHead();
    if (current->getNext() ==  NULL){
        head = NULL;
        last = NULL;

    }
    while(current->getNext() != NULL){
        if(current->getNext()->getID() == last->getID()){
            current->setNext(NULL);
            size--;
            last=current;

        } else {
            current = current->getNext();
        }}
}

bool LinkedList::isEmpty(){
    return size==0;
}

int LinkedList::getSize(){
    return size;
}

void LinkedList::printList() {
    if (!isEmpty()) {
        cout << "La lista posee:" << endl;
        Node *current = getHead();
        for (int i = 0; i < size; i++) {
            printf("El nodo %d:\n", i);
            cout << "posx " + to_string(current->get_x()) << endl;
            cout << "posy " + to_string(current->get_y()) << endl;
            current = current->getNext();
        }
    } else {
        cout << "List is empty." << endl;
    }
}

Node* LinkedList::backtracking() {
    Node *current = getLast();
    deletelast();
    return current;
}
