//
// Created by jrodr on 20/7/2020.
//

#ifndef PRUEBASERVER_NODE_H
#define PRUEBASERVER_NODE_H

template <class T>
class Node {
private:
    T data;
    Node<T> *next;

public:
    /**
     * @brief Node
     * @param data
     */
    Node(T data) {
        Node::data = data;
        next = nullptr;
    }
    /**
     * @brief setData
     * @param data
     */
    void setData(T data) {
        Node::data = data;
    }
    /**
     * @brief getData
     * @return
     */
    T getData() {
        return data;
    }
    /**
     * @brief setNext
     * @param next
     */
    void setNext(Node *next) {
        Node::next = next;
    }
    /**
     * @brief getNext
     * @return
     */
    Node* getNext() {
        return next;
    }
};


#endif //PRUEBASERVER_NODE_H
