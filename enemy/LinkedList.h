#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<cstddef>
#include "Node.h"
#include <string>
#include <iostream>
using namespace std;


class LinkedList{
private:
    int id;
    Node* head;
    int size;
    Node* last;
public:
    LinkedList();
    Node* getHead();
    Node* getLast();
    int getSize();
    void addNode(int x, int y);
    Node* getNode(int id);
    void removeNode(int id);
    bool isEmpty();
    void printList();
    void deletelast();
    Node* backtracking();
    void deletehead();
};
#endif