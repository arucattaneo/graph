#ifndef NODE_H
#define NODE_H

template<class Data>
class Node {

private:
    //Attributes
    Data data;
    Node<Data> *next_node;

public:
    // Methods
    /*
    constructor
    PRE: -
    POST: Creates a node with the value d and points next_node to NULL
    */
    Node(Data d);

    /*
    PRE: -
    POST: Gets the data contained in the node.
    */
    Data get_data();

    /*
    PRE: -
    POST: Gets the pointer to the next node
    */
    Node<Data> *get_next();

    /*
    PRE: -
    POST: Sets the next node to the pointer passed by parameter
    */
    void set_next(Node *next);
};

template<class Data>
Node<Data>::Node(Data d) {
    data = d;
    next_node = nullptr;
}

template<class Data>
Data Node<Data>::get_data() {
    return data;
}

template<class Data>
void Node<Data>::set_next(Node *ps) {
    next_node = ps;
}

template<class Data>
Node<Data> *Node<Data>::get_next() {
    return next_node;
}


#endif //NODE_H
