#include "date.hpp"

#include <string>

Date::Date(){
    //Defaults to Current Day (April 1st)
    this->Day = 1;
    this->Month = 4;
    this->Year = 2026;
}

// M/D/Y
/*Date::Date(std::string input){
    this->Month = stoi(input.substr(0, input.find("/")));
    input.erase(input.find("/"));
    this->Day = stoi(input.substr(0, input.find("/")));
    input.erase(input.find("/"));
    this->Year = stoi(input);
}*/

//above code block was erasing from the first / to the end of the string -aliaan
Date::Date(std::string input){
    size_t p;
    p = input.find("/");
    this->Month = stoi(input.substr(0, p));
    input = input.substr(p + 1);
    p = input.find("/");
    this->Day = stoi(input.substr(0, p));
    input = input.substr(p + 1);
    this->Year = stoi(input);
}

Date::~Date(){

}

int Date::getDay() const {
    return this->Day;
}

int Date::getMonth() const {
    return this->Month;
}

int Date::getYear() const {
    return this->Year;
}

int Date::getAge() const {
    return this->Year - 2026;
}

bool Date::operator<(const Date &other){
    int date1 = (this->Year * 365) + (this->Month * 30) + (this->Day);
    int date2 = (other.getYear() * 365) + (other.getMonth() * 30) + other.Day;

    return date1 < date2;
}

bool Date::operator>(const Date &other){
    int date1 = (this->Year * 365) + (this->Month * 30) + (this->Day);
    int date2 = (other.getYear() * 365) + (other.getMonth() * 30) + other.Day;

    return date1 > date2;
}

bool Date::operator==(const Date &other){
    int date1 = (this->Year * 365) + (this->Month * 30) + (this->Day);
    int date2 = (other.getYear() * 365) + (other.getMonth() * 30) + other.Day;

    return date1 == date2;
}
