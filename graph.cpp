#include "graph.h"

Graph::Graph() {
    vertices_list = new MyList<MyList<Vertex *> *>;
}

MyList<Vertex *> *Graph::find_sublist(string iata_code, MyList<MyList<Vertex *> *> &list_of_lists) {
    for (unsigned i = 1; i <= list_of_lists.get_size(); i++) {
        MyList<Vertex *> *read_list = list_of_lists.get_data(i);
        if (!read_list->is_empty()) {
            Vertex *read_vertex = read_list->get_data(1);
            if (iata_code == read_vertex->get_iata_code())
                return read_list;
        }
    }
    return nullptr;
}

void Graph::insert_vertex(string iata_code, Vertex *vertex_to_insert) {
    MyList<Vertex *> *found_list = find_sublist(iata_code, *vertices_list);
    if (found_list != nullptr)
        found_list->add(vertex_to_insert);
    else {
        Vertex *nuevo_vertice = new Vertex(iata_code);
        MyList<Vertex *> *nueva_lista = new MyList<Vertex *>;
        nueva_lista->add(nuevo_vertice);
        nueva_lista->add(vertex_to_insert);
        vertices_list->add(nueva_lista);
    }
}

void Graph::load_graph(MyList<Edge *> *edges_list) {
    for (unsigned i = 1; i <= edges_list->get_size(); i++) {
        Edge *read_edge = edges_list->get_data(i);

        string origin_iata_code = read_edge->get_origen();
        string destination_iata_code = read_edge->get_destination();
        unsigned ticket_value = read_edge->get_ticket_value();
        float flight_hours = read_edge->get_flight_hours();

        Vertex *new_vertex = new Vertex(destination_iata_code, ticket_value, flight_hours);
        insert_vertex(origin_iata_code, new_vertex);
    }
}

void Graph::show_graph() {
    for (unsigned i = 1; i <= vertices_list->get_size(); i++) {
        MyList<Vertex *> *read_list = vertices_list->get_data(i);
        if (!read_list->is_empty()) {
            for (unsigned j = 2; j <= read_list->get_size(); j++) {
                cout << "Origin: " << read_list->get_data(1)->get_iata_code();
                cout << " Destination: " << read_list->get_data(j)->get_iata_code() << endl;
                cout << "Ticket price: $" << read_list->get_data(j)->get_ticket_value() << endl;
                cout << "Flight hours: " << read_list->get_data(j)->get_flight_hours() << "\n\n";
            }
        }
    }
}

Graph::~Graph() {
    delete vertices_list;
}
