#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <iostream>
#include <string>
#include "../tools/date.hpp"
#include "../tools/location.hpp"
#include "tickets.hpp"
#include "minivector.hpp"
using namespace std;

class Driver {
protected:
    int id;
    string name;
    Date dob;
    Location location;
    string workType;
    int experienceYears;
    string medicalCondition;
    Date licenseDate;
    Tickets tickets;

private:
    MiniVector<Location> frequentLocations;

public:
    Driver(int id, string name, Date dob, Location loc,
           string work, int exp, string med, Date licenseDate);

    int getID();
    Date getLicenseDate();
    void addTicket(Ticket t);
    Tickets& getTickets();
    void addLocation(const Location& loc);
    MiniVector<Location>& getFrequentLocations();
    void display();
};

// Derived classes
class YouthDriver : public Driver { public: using Driver::Driver; };
class MiddleAgedDriver : public Driver { public: using Driver::Driver; };
class SeniorDriver : public Driver { public: using Driver::Driver; };

// Work-based
class StudentDriver : public Driver { public: using Driver::Driver; };
class GovtEmployeeDriver : public Driver { public: using Driver::Driver; };
class SelfEmployedDriver : public Driver { public: using Driver::Driver; };
class BusinessOwnerDriver : public Driver { public: using Driver::Driver; };
class PrivateEmployeeDriver : public Driver { public: using Driver::Driver; };

// Experience-based
class NewDriver : public Driver { public: using Driver::Driver; };
class ModerateDriver : public Driver { public: using Driver::Driver; };
class HighlyExperiencedDriver : public Driver { public: using Driver::Driver; };

// Medical-condition-based
class FitDriver : public Driver { public: using Driver::Driver; };
class VisionImpairedDriver : public Driver { public: using Driver::Driver; };
class UpperExtremityDriver : public Driver { public: using Driver::Driver; };
class LocomotorDriver : public Driver { public: using Driver::Driver; };

#endif
