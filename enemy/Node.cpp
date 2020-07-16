#include "Node.h"


Node::Node(int id,int x, int y){
    this->id = id;
    this->x = x;
    this->y = y;
    this->next = NULL;
}


int Node::get_x(){
    return this->x;
}

void Node::setID(int ID){
    this->id = ID;
}

int Node::getID(){
    return this->id;
}

void Node::set_x(int posx){
    this->x = posx;
}

Node* Node::getNext(){
    return next;
}

void Node::setNext(Node* node){
    next = node;
}

Node::Node() {
    id = 0;
    x = 0;
    y = 0;
    next = NULL;
}

int Node::get_y() {
    return this->y;
}

void Node::set_y(int posy) {
    this->y = posy;

}
