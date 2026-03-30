#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <iostream>
#include <string>
#include "../tools/date.hpp"
#include "../tools/location.hpp"
#include "tickets.hpp"
#include "minivector.hpp"

using namespace std;

// Enums for Categories 
enum class AgeCategory { Youth, MiddleAged, Senior };
enum class WorkCategory { Student, GovtEmployee, SelfEmployed, BusinessOwner, PrivateEmployee };
enum class ExperienceCategory { New, Moderate, HighlyExperienced };
enum class MedicalCategory { Fit, VisionImpaired, UpperExtremity, Locomotor };

//  Driver Base Class
class Driver {
protected:
    int id;
    string name;
    Date dob;
    Location location;
    AgeCategory ageCategory;
    WorkCategory workCategory;
    int experienceYears;
    ExperienceCategory experienceCategory;
    MedicalCategory medicalCategory;
    Date licenseDate;
    Tickets tickets;

private:
    MiniVector<Location> frequentLocations;

public:
    // Constructor
    Driver(int id, string name, Date dob, Location loc,
           WorkCategory workCat, int exp, MedicalCategory medCat, Date licenseDate) 
    {
        this->id = id;
        this->name = name;
        this->dob = dob;
        this->location = loc;
        this->workCategory = workCat;
        this->experienceYears = exp;
        this->medicalCategory = medCat;
        this->licenseDate = licenseDate;

        // Automatic age category assignment
        int age = 2026 - dob.getYear();
        if (age <= 28) ageCategory = AgeCategory::Youth;
        else if (age <= 50) ageCategory = AgeCategory::MiddleAged;
        else ageCategory = AgeCategory::Senior;

        // Automatic experience category assignment
        if (exp <= 5) experienceCategory = ExperienceCategory::New;
        else if (exp <= 15) experienceCategory = ExperienceCategory::Moderate;
        else experienceCategory = ExperienceCategory::HighlyExperienced;
    }

    // Getters
    int getID() { return id; }
    int getAge() const { return 2026 - dob.getYear(); }
    Date getLicenseDate() { return licenseDate; }
    AgeCategory getAgeCategory() const { return ageCategory; }
    WorkCategory getWorkCategory() const { return workCategory; }
    ExperienceCategory getExperienceCategory() const { return experienceCategory; }
    MedicalCategory getMedicalCategory() const { return medicalCategory; }

    Tickets& getTickets() { return tickets; }
    MiniVector<Location>& getFrequentLocations() { return frequentLocations; }

    // Add ticket
    void addTicket(Ticket t) { tickets.Insert(t); }

    // Add frequently visited location
    void addLocation(const Location& loc) { frequentLocations.push_back(loc); }

    // Display basic info
    void display() {
        cout << "ID: " << id << " Name: " << name << endl;
    }
};

//Age-based Derived Classes
class YouthDriver : public Driver {
public:
    using Driver::Driver;
    void youthInfo() { cout << "Youth driver under 28\n"; }
};

class MiddleAgedDriver : public Driver {
public:
    using Driver::Driver;
    void middleInfo() { cout << "Middle-aged driver\n"; }
};

class SeniorDriver : public Driver {
public:
    using Driver::Driver;
    void seniorInfo() { cout << "Senior driver\n"; }
};

// Work-based Derived Classes 
class StudentDriver : public Driver { public: using Driver::Driver; void studentInfo() { cout << "Student driver\n"; } };
class GovtEmployeeDriver : public Driver { public: using Driver::Driver; void govtInfo() { cout << "Government employee\n"; } };
class SelfEmployedDriver : public Driver { public: using Driver::Driver; void selfEmpInfo() { cout << "Self-employed driver\n"; } };
class BusinessOwnerDriver : public Driver { public: using Driver::Driver; void businessInfo() { cout << "Business owner driver\n"; } };
class PrivateEmployeeDriver : public Driver { public: using Driver::Driver; void privateInfo() { cout << "Private sector driver\n"; } };

//  Experience-based Derived Classes
class NewDriver : public Driver { public: using Driver::Driver; void newInfo() { cout << "New driver (0-5 years)\n"; } };
class ModerateDriver : public Driver { public: using Driver::Driver; void moderateInfo() { cout << "Moderately experienced driver (5-15 years)\n"; } };
class HighlyExperiencedDriver : public Driver { public: using Driver::Driver; void highExpInfo() { cout << "Highly experienced driver (>15 years)\n"; } };

// Medical-condition-based Derived Classes 
class FitDriver : public Driver { public: using Driver::Driver; void fitInfo() { cout << "Driver is fit\n"; } };
class VisionImpairedDriver : public Driver { public: using Driver::Driver; void visionInfo() { cout << "Driver has vision impairment\n"; } };
class UpperExtremityDriver : public Driver { public: using Driver::Driver; void upperInfo() { cout << "Driver has upper extremity impairment\n"; } };
class LocomotorDriver : public Driver { public: using Driver::Driver; void locomotorInfo() { cout << "Driver has locomotor disability\n"; } };

#endif
