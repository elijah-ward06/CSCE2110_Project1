#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "driver.hpp"
#include "engine/HashTable.hpp"
#include "engine/MiniVector.hpp"
#include "engine/LicenseSorter.hpp"

class DriverDatabase {
private:
    HashTable<Driver*> active;
    HashTable<Driver*> inactive;

    MiniVector<Driver*> allDrivers;

public:
    void addDriver(Driver* d);
    Driver* findDriver(int id);

    void moveToInactive(int id);

    Driver** getNewest(int N);
    Driver** getOldest(int N);

    int totalDrivers();
};

#endif
