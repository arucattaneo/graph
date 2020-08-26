#ifndef ARISTA_H
#define ARISTA_H

#include <string>

using namespace std;

class Edge {

private:
    // Attributes
    string origin_iata_code, destination_iata_code;
    unsigned ticket_value;
    float flight_hours;

public:
    // Methods
    //PRE: -
    //POST: Creates a new edge setting the attributes to the values passed by parameter
    Edge(string origin_iata_code, string destination_iata_code, unsigned ticket_value, float flight_hours);

    //PRE: -
    //POST: Returns the origin iata code
    string get_origen();

    //PRE: -
    //POST: Returns the destination iata code
    string get_destination();

    //PRE: -
    //POST: Returns the value of the ticket
    unsigned get_ticket_value();

    //PRE:
    //POST: Returns the number of hours the flight takes
    float get_flight_hours();
};

#endif //ARISTA_H