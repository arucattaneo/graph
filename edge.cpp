#include "edge.h"

using namespace std;

Edge::Edge(string origin_iata_code, string destination_iata_code, unsigned int ticket_value, float flight_hours) {
    this->origin_iata_code = origin_iata_code;
    this->destination_iata_code = destination_iata_code;
    this->ticket_value = ticket_value;
    this->flight_hours = flight_hours;
}

string Edge::get_origen() {
    return origin_iata_code;
}

string Edge::get_destination() {
    return destination_iata_code;
}

unsigned Edge::get_ticket_value() {
    return ticket_value;
}

float Edge::get_flight_hours() {
    return flight_hours;
}