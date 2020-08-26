#ifndef VERTEX_H
#define VERTEX_H

#include <string>

using namespace std;

class Vertex {

private:

    // Attributes
    string iata_code;
    unsigned ticket_value;
    float flight_hours;

public:

    // Methods
    // Constructor
    Vertex(string iata_code, unsigned value, float hours);

    //PRE: -
    //POST: Creates a vertex with the iata code passed by parameter and sets the rest of the attributes to 0
    Vertex(string iata_code);

    //PRE: -
    //POST: Gets the iata code of the vertex
    string get_iata_code();

    //PRE: -
    //POST: Gets the ticket value of the vertex
    unsigned get_ticket_value();

    //PRE: -
    //POST: Gets the flight hours of the vertex
    float get_flight_hours();
};


#endif //VERTEX_H
