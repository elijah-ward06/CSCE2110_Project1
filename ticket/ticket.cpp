#include "ticket.hpp"

#include "../tools/date.hpp"
#include "../tools/location.hpp"
#include <string>

Ticket::Ticket(std::string r, Date d, Location l){
    this->reason = r;
    this->date = d;
    this->location = l;
}

Ticket::Ticket(std::string r, Location l){
    this->reason = r;
    this->date = Date();
    this->location = l;
};

Date Ticket::getDate(){
    return this->date;
}

Location Ticket::getLocation(){
    return this->location;
}
