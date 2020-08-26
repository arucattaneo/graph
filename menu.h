#ifndef MENU_H
#define MENU_H

#include "graph.h"

using namespace std;

class Menu {
    //Attributes
    Graph *head;

public:
    //Methods
    //Constructor
    //PRE: -
    //POST: Creates an empty graph
    Menu();

    //PRE: -
    //POST: Loads the data of a file whose name is passed by parameter onto the graph. If the file doesn't exist prints an error
    void load_data(string file_name);

    //Destrcutor
    //POST: Libera recursos utilizados
    ~Menu();
};

#endif //MENU_H
