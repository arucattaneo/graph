#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include "vertex.h"
#include "edge.h"
#include "myList.h"

using namespace std;

class Graph {

private:
    // Attributes
    MyList<MyList<Vertex *> *> *vertices_list;

    // Methods
    void insert_vertex(string iata_code, Vertex *vertex_to_insert);

public:
    //Constructor
    //PRE: -
    //POST: Creates an empty list of vertices
    Graph();

    //PRE: -
    //POST: Recorre lista_de_listas y si contiene alguna lista cuyo primer elemento coincida con el iata_code devuelve un puntero a ella
    MyList<Vertex *> *find_sublist(string iata_code, MyList<MyList< Vertex *> *> &list_of_lists);

    //PRE: -
    //POST: Loads the graph with the list of edges passed by parameter
    void load_graph(MyList<Edge *> *edges_list);

    //PRE: -
    //POST: Shows the graph
    void show_graph();

    //Destructor
    //PRE: -
    //POST: Deletes the graph and frees the heap memory
    ~Graph();
};

#endif //GRAPH_H
