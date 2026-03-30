#include "database.hpp"

void DriverDatabase::addDriver(Driver* d){
    active.insert(d->getID(), d);
    allDrivers.push_back(d);
}

Driver* DriverDatabase::findDriver(int id){
    Driver** d = active.find(id);
    if (d) return *d;
    return nullptr;
}

void DriverDatabase::moveToInactive(int id){
    Driver** d = active.find(id);
    if (!d) return;

    inactive.insert(id, *d);
    active.remove(id);
}

Driver** DriverDatabase::getNewest(int N){
    LicenseSorter<Driver> sorter;

    int total = allDrivers.size();
    Driver** arr = new Driver*[total];

    for (int i = 0; i < total; i++){
        arr[i] = allDrivers[i];
    }

    return sorter.topN(arr, total, N, true);
}

Driver** DriverDatabase::getOldest(int N){
    LicenseSorter<Driver> sorter;

    int total = allDrivers.size();
    Driver** arr = new Driver*[total];

    for (int i = 0; i < total; i++){
        arr[i] = allDrivers[i];
    }

    return sorter.topN(arr, total, N, false);
}

int DriverDatabase::totalDrivers(){
    return allDrivers.size();
}
