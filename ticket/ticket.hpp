#ifndef TICKET_HPP
#define TICKET_HPP

#include "../tools/date.hpp"
#include "../tools/location.hpp"
#include <string>

class Ticket{
    private:
        std::string reason = "null";
        Date date;
        Location location;
    public:
        Ticket(std::string r, Date d, Location l);
        
        //Ticket that defaults to current date
        Ticket(std::string r, Location l);

        ~Ticket();
        Date getDate();
        Location getLocation();
};


#endif