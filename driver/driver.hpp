#ifndef DRIVER_HPP
#define DRIVER_HPP

#include "../tools/date.hpp"
#include "../tools/location.hpp"
#include "../tickets/tickets.hpp"
#include "../structures/minivector.hpp"
#include <string>

enum class AgeCategory { Youth, MiddleAged, Senior };
enum class WorkCategory { Student, GovtEmployee, SelfEmployed, BusinessOwner, PrivateEmployee };
enum class ExperienceCategory { NewDriver, ModerateDriver, HighlyExperiencedDriver };
enum class MedicalCondition { Fit, VisionImpaired, UpperExtremity, Locomotor };

class Driver {
protected:
    int id;
    std::string name;
    Date dob;
    Location address;
    AgeCategory ageCat;
    WorkCategory workCat;
    ExperienceCategory expCat;
    MedicalCondition medCond;
    Date licenseDate;

    Tickets tickets; // composition
    MiniVector<Location> frequentLocations;

public:
    Driver(int id, const std::string& name, const Date& dob, const Location& addr,
           AgeCategory ageCat, WorkCategory workCat, ExperienceCategory expCat,
           MedicalCondition medCond, const Date& licenseDate)
        : id(id), name(name), dob(dob), address(addr),
          ageCat(ageCat), workCat(workCat), expCat(expCat),
          medCond(medCond), licenseDate(licenseDate) {}

    virtual ~Driver() {}

    int getID() const { return id; }
    std::string getName() const { return name; }
    Date getDOB() const { return dob; }
    Location getAddress() const { return address; }
    AgeCategory getAgeCategory() const { return ageCat; }
    WorkCategory getWorkCategory() const { return workCat; }
    ExperienceCategory getExpCategory() const { return expCat; }
    MedicalCondition getMedicalCondition() const { return medCond; }
    Date getLicenseDate() const { return licenseDate; }

    Tickets& getTickets() { return tickets; }
    MiniVector<Location>& getFrequentLocations() { return frequentLocations; }

    void addTicket(const Ticket& t) {
        tickets.Insert(t);
    }

    void addLocation(const Location& loc) {
        frequentLocations.push_back(loc);
    }
};

#endif
