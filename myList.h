#ifndef MY_LIST_H
#define MY_LIST_H

#include "node.h"

template<class Data>
class MyList {

private:
    // Attributes
    Node<Data> *head;
    unsigned size;

    //Methods
    // PRE: 0 < pos <= tam
    // POST: Returns a pointer to the node
    Node<Data> *get_node(unsigned pos);

public:
    //Methods
    /*
    constructor
    PRE: -
    POST: Creates an empty list
    */
    MyList();

    /*
    PRE: -
    POST: Returns true or false whether the list is empty or not
    */
    bool is_empty();

    /*
    PRE: -
    POST: Gets the size of the list
    */
    unsigned get_size();

    /*
    PRE: -
    POST: Adds an element to the end of the list and increases the size by 1
    */
    void add(Data f);

    /*
    PRE: 0 < pos <= tam
    POST: Removes the node in the position passed by parameter
    */
    void remove(unsigned pos);

    /*
    PRE: 0 < pos <= tam
    POST: Gets the data in the position passed by parameter
    */
    Data get_data(unsigned pos);

    /*
    destructor
    PRE: -
    POST: eliminates the list
    */
    ~MyList();
};

template<class Data>
MyList<Data>::MyList() {
    head = nullptr;
    size = 0;
}

template<class Data>
void MyList<Data>::add(Data d) {
    Node<Data> *new_node = new Node<Data>(d);
    if (this->is_empty()) {
        head = new_node;
    } else {
        Node<Data> *removed_node = get_node(size);
        removed_node->set_next(new_node);
    }
    size++;
}

template<class Data>
Data MyList<Data>::get_data(unsigned pos) {
    return get_node(pos)->get_data();
}

template<class Data>
void MyList<Data>::remove(unsigned pos) {
    Node<Data> *removed_node = head;
    if (pos == 1) {
        head = removed_node->get_next();
    } else {
        Node<Data> *previous_node = get_node(pos - 1);
        removed_node = previous_node->get_next();
        previous_node->set_next(removed_node->get_next());
    }
    delete removed_node->get_data();
    delete removed_node;
    size--;
}

template<class Data>
unsigned MyList<Data>::get_size() {
    return size;
}

template<class Data>
Node<Data> *MyList<Data>::get_node(unsigned pos) {
    Node<Data> *aux = head;
    unsigned i = 1;
    while (i < pos) {
        aux = aux->get_next();
        i++;
    }
    return aux;
}

template<class Data>
bool MyList<Data>::is_empty() {
    return (head == nullptr);
}

template<class Data>
MyList<Data>::~MyList() {
    while (!(is_empty())) {
        remove(1);
    }
}

#endif //MY_LIST_H