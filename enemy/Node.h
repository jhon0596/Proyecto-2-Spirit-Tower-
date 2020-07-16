#ifndef NODE_H
#define NODE_H

#include<cstddef>
#include <string>

class Node{
private:
    int id;
    int x,y;
    Node* next;

public:
    Node();
    Node(int id,int x, int y);
    int get_x();
    void set_x(int posx);
    int getID();
    void setID(int ID);
    Node* getNext();
    void setNext(Node* node);
    int get_y();
    void set_y(int posy);
};

#endif