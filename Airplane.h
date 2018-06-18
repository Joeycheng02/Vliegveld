//
// Created by matth on 15/03/2018.
//

#ifndef VLIEGVELD_AIRPLANE_H
#define VLIEGVELD_AIRPLANE_H

#include <iostream>
#include <string>
#include "Airport.h"
#include "Time.h"

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
    unsigned int capacity;
    int gateNumber;
    unsigned int height;

    int fuel;
    int fuel_cost;

public:
    Airplane();

    const string &getNumber() const;

/**
\n REQUIRE(Airplane::number != number, "The variable already has this value");
\n ENSURE(getNumber() == number, "The variable is not set correctly");
*/
    void setNumber(const string &number);

    const string &getCallsign() const;

/**
\n REQUIRE(Airplane::callsign != callsign, "The variable already has this value");
\n ENSURE(getCallsign() == callsign, "The variable is not set correctly");
*/
    void setCallsign(const string &callsign);

    const string &getModel() const;

/**
\n REQUIRE(Airplane::model != model, "The variable already has this value");
\n ENSURE(getModel() == model, "The variable is not set correctly");
*/
    void setModel(const string &model);

    const string &getStatus() const;

/**
\n REQUIRE(Airplane::status != status, "The variable already has this value");
\n ENSURE(getStatus() == status, "The variable is not set correctly");
*/
    void setStatus(const string &status);

    unsigned int getHeight() const;

/**
\n REQUIRE(Airplane::height >= 0, "The variable is not properly initialized");
\n ENSURE(getHeight() == height, "The variable is not set correctly");
\n ENSURE(getHeight() >= 0, "The variable can't be a negative number");
*/
    void setHeight(unsigned int height);


    const string &getAirport() const;

/**
\n REQUIRE(Airplane::airport != airport, "The variable already has this value");
\n ENSURE(getAirport() == airport, "The variable is not set correctly");
*/
    void setAirport(const string &airport);

    int getGateNumber() const;

/**
\n REQUIRE(Airplane::gateNumber >= -1, "The variable is not properly initialized");
\n ENSURE(getGateNumber() == gateNumber, "The variable is not set correctly");
\n ENSURE(getGateNumber() >= -1, "The variable can't be less than -1");
*/
    void setGateNumber(int gateNumber);

    unsigned int getCapacity() const;

/**
\n REQUIRE(Airplane::capacity >=0, "The variable is not properly initialized");
\n ENSURE(getCapacity() == capacity, "The variable is not set correctly");
\n ENSURE(getCapacity() >= 0, "The variable can't be a negative number");
*/
    void setCapacity(unsigned int passengers);

    const string &getType() const;

/**
\n REQUIRE(Airplane::type !=type , "The variable already has this value");
\n ENSURE(getType() == type, "The variable is not set correctly");
*/
    void setType(const string &type);

    const string &getEngine() const;

/**
\n REQUIRE(Airplane::engine != engine, "The variable already has this value");
\n ENSURE(getEngine() == engine, "The variable is not set correctly");
*/
    void setEngine(const string &engine);

    const string &getSize() const;

/**
\n REQUIRE(Airplane::size != size, "The variable already has this value");
\n ENSURE(getSize() == size, "The variable is not set correctly");
*/
    void setSize(const string &size);

/**
\n REQUIRE (getStatus() == "Approaching", "Airplane is not approaching");
\n ENSURE(getStatus() == "Standing at gate", "Airplane is not standing at a gate");
\n ENSURE(getAirport() == airport.getName(), "Airplane is not standing at the right airport");
*/
    int descending(Airport &airport, Time &time);

/**
\n REQUIRE (getStatus() == "Standing at gate", "Airplane is not standing at a gate");
\n REQUIRE (getAirport() == airport.getName(), "This airplane does not belong to the given aiport.");
\n ENSURE(airport.getRunways()[runwayNumber].isVacant(), "Runway is still occupied");
\n ENSURE(getGateNumber() == -1, "Airplane is still at a gate");
*/
    int ascending(Airport &airport, Time &time);

    int getfuel_cost() const;

    void setFuel_cost(int fuel_cost);

    int getFuel() const;

    void setFuel(int fuel);
};



#endif //VLIEGVELD_AIRPLANE_H
