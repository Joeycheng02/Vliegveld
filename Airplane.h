//
// Created by matth on 15/03/2018.
//

#ifndef VLIEGVELD_AIRPLANE_H
#define VLIEGVELD_AIRPLANE_H

#include <iostream>
#include <string>
#include "Airport.h"

using namespace std;

class Airplane {
private:
    string number;
    string callsign;
    string model;
    string type;
    string engine;
    string size;
    string status;
    string airport;
    int capacity;
    int gateNumber;
    int height;
    
public:
    const string &getAirport() const;

    void setAirport(const string &airport);
    
public:
    Airplane();
    
    int getHeight() const;

    int getCapacity() const;

    void setCapacity(int passengers);

    void setHeight(int height);

    int getGateNumber() const;

    void setGateNumber(int gateNumber);

    const string &getNumber() const;

    void setNumber(const string &number);

    const string &getCallsign() const;

    void setCallsign(const string &callsign);

    const string &getModel() const;

    void setModel(const string &model);

    const string &getType() const;

    void setType(const string &type);

    const string &getEngine() const;

    void setEngine(const string &engine);

    const string &getSize() const;

    void setSize(const string &size);

    const string &getStatus() const;

    void setStatus(const string &status);

    //REQUIRE airplane must have the status "Approaching"
    int descending(Airport &airport);
    //ENSURE airplane must stand at a gate of the given airport

    //REQUIRE airplane
    int ascending (Airport &airport);
    //ENSURE the runway and gate are vacant

    //REQUIRE airplane is in the air and not approaching
    int approaching ();
    //ENSURE airplane is approaching
};


#endif //VLIEGVELD_AIRPLANE_H
