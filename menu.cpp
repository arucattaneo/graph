#include "menu.h"
#include <iostream>
#include <fstream>

Menu::Menu() {
    head = new Graph;
}

void Menu::load_data(string file_name) {
    ifstream file(file_name);

    if (!file.fail()) {
        string origin_iata, destination_iata;
        unsigned ticket_value;
        float flight_hours;
        MyList<Edge *> *edges_list = new MyList<Edge *>;

        while (file >> origin_iata) {
            file >> destination_iata;
            file >> ticket_value;
            file >> flight_hours;
            Edge *new_edge = new Edge(origin_iata, destination_iata, ticket_value, flight_hours);
            edges_list->add(new_edge);
        }
        file.close();
        head->load_graph(edges_list);
        head->show_graph();
        delete edges_list;

    } else
        cout << "Error, the file: " << file_name << " could not be opened." << endl;
}

Menu::~Menu() {
    delete head;
}
