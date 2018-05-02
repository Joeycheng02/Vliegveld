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
/**
\n REQUIRE (getStatus() == "Approaching", "Airplane is not approaching");
\n ENSURE(getStatus() == "Standing at gate", "Airplane is not standing at a gate");
\n ENSURE(getAirport() == airport.getName(), "Airplane is not standing at the right airport");
*/
    int descending(Airport &airport);

/**
\n REQUIRE (getStatus() == "Standing at gate", "Airplane is not standing at a gate");
\n REQUIRE (getAirport() == airport.getName(), "This airplane does not belong to the given aiport.");
\n ENSURE(airport.getRunways()[runwayNumber].isVacant(), "Runway is still occupied");
\n ENSURE(getGateNumber() == -1, "Airplane is still at a gate");
*/
    int ascending (Airport &airport);

/**
\n REQUIRE(getStatus() == "Departed", "Airplane is not in the air or is already approaching");
\n ENSURE(getStatus() == "Approaching", "Airplane is not approaching");
*/
    int approaching ();
};


#endif //VLIEGVELD_AIRPLANE_H
