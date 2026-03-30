#ifndef DRIVER_HPP
#define DRIVER_HPP

#include "tools/date.hpp"
#include "tools/location.hpp"
#include "ticket/tickets.hpp"
#include <string>
using namespace std;

class Driver {
private:
    int id;
    string name;
    Date dob;
    Location location;

    string workType;
    int experienceYears;
    string medicalCondition;

    Date licenseDate;
    Tickets tickets;

public:
    Driver(int id, string name, Date dob, Location loc,
           string work, int exp, string med, Date licenseDate);

    int getID();
    Date getLicenseDate();

    void addTicket(Ticket t);
    void display();
};

#endif
