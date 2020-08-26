#include "vertex.h"

using namespace std;

Vertex::Vertex(string iata_code, unsigned value, float hours) {
    this->iata_code = iata_code;
    this->ticket_value = value;
    this->flight_hours = hours;
}

Vertex::Vertex(string iata_code) {
    this->iata_code = iata_code;
    this->ticket_value = 0;
    this->flight_hours = 0;
}

string Vertex::get_iata_code() {
    return iata_code;
}

unsigned Vertex::get_ticket_value() {
    return ticket_value;
}

float Vertex::get_flight_hours() {
    return flight_hours;
}

