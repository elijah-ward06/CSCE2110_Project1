#ifndef DATE_HPP
#define DATE_HPP

#include <string>

class Date{
    private:

    int Year;
    int Day;
    int Month;

    public:

    Date();
    Date(std::string input);
    ~Date();
    int getAge() const;
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    bool operator>(const Date& other);
    bool operator<(const Date& other);

    bool operator==(const Date& other);
};

#endif