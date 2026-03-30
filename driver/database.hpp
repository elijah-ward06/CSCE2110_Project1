#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "driver.hpp"
#include "structures/hashtable.hpp"
#include "structures/minivector.hpp"
#include "structures/licensesorter.hpp"

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
