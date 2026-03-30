#include "driver.hpp"
#include <iostream>
using namespace std;

Driver::Driver(int id, string name, Date dob, Location loc,
               string work, int exp, string med, Date licenseDate){
    this->id = id;
    this->name = name;
    this->dob = dob;
    this->location = loc;
    this->workType = work;
    this->experienceYears = exp;
    this->medicalCondition = med;
    this->licenseDate = licenseDate;
}

int Driver::getID(){
    return id;
}

Date Driver::getLicenseDate(){
    return licenseDate;
}

void Driver::addTicket(Ticket t){
    tickets.Insert(t);
}

Tickets& Driver::getTickets(){
    return tickets;
}

void Driver::addLocation(const Location& loc){
    frequentLocations.push_back(loc);
}

MiniVector<Location>& Driver::getFrequentLocations(){
    return frequentLocations;
}

void Driver::display(){
    cout << "ID: " << id << " Name: " << name << endl;
}
