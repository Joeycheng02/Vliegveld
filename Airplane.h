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
    int capacity; // unsigned int werkte niet
    int gateNumber;
    int height;
    int fuel;
    int fuel_cost;
    Airplane* _initCheck;
public:
    Airplane();

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
*/
    const string &getNumber() const;

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
\n REQUIRE(Airplane::number != number, "This Airplane Number already has this value.");
\n ENSURE(getNumber() == number, "This Airplane Number is not set correctly.");
*/
    void setNumber(const string &number);

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
*/
    const string &getCallsign() const;

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
\n REQUIRE(Airplane::callsign != callsign, "This Airplane Callsign already has this value.");
\n ENSURE(getCallsign() == callsign, "This Airplane Callsign is not set correctly.");
*/
    void setCallsign(const string &callsign);

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
*/
    const string &getModel() const;

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
\n REQUIRE(Airplane::model != model, "This Airplane Model already has this value.");
\n ENSURE(getModel() == model, "This Airplane Model is not set correctly.");
*/
    void setModel(const string &model);

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
*/
    const string &getStatus() const;

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
\n REQUIRE(Airplane::status != status, "This Airplane Status already has this value.");
\n ENSURE(getStatus() == status, "This Airplane Status is not set correctly.");
*/
    void setStatus(const string &status);

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
*/
    int getHeight() const;

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
\n REQUIRE(Airplane::height >= 0, "This Airplane Height is not properly initialized.");
\n ENSURE(getHeight() == height, "This Airplane Height is not set correctly.");
\n ENSURE(getHeight() >= 0, "This Airplane Height can't be a negative number.");
*/
    void setHeight(int height);


/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
*/
    const string &getAirport() const;

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
\n REQUIRE(Airplane::airport != airport, "This Airplane Airport already has this value.");
\n ENSURE(getAirport() == airport, "This Airplane Airport is not set correctly.");
*/
    void setAirport(const string &airport);

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
*/
    int getGateNumber() const;

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
\n REQUIRE(Airplane::gateNumber >= -1, "This Airplane gateNumber is not properly initialized.");
\n ENSURE(getGateNumber() == gateNumber, "This Airplane gateNumber is not set correctly.");
\n ENSURE(getGateNumber() >= -1, "This Airplane gateNumber can't be less than -1.");
*/
    void setGateNumber(int gateNumber);

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
*/
    int getCapacity() const;

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
\n REQUIRE(Airplane::capacity >=0, "This Airplane Capacity is not properly initialized.");
\n ENSURE(getCapacity() == capacity, "This Airplane Capacity is not set correctly.");
\n ENSURE(getCapacity() >= 0, "This Airplane Capacity can't be a negative number.");
*/
    void setCapacity(int passengers);

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
*/
    const string &getType() const;

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
\n REQUIRE(Airplane::type !=type , "This Airplane Type already has this value.");
\n REQUIRE(type == "private" or type == "airline" or type == "military" or type == "emergency", "This Airplane Type is not a valuable value.");
\n ENSURE(getType() == type, "This Airplane Type is not set correctly.");
*/
    void setType(const string &type);

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
*/
    const string &getEngine() const;

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
\n REQUIRE(Airplane::engine != engine, "This Airplane Engine already has this value.");
\n REQUIRE(engine == "jet" or engine == "propeller", "This Airplane Engine already has this value.");
\n ENSURE(getEngine() == engine, "This Airplane Engine is not set correctly.");
*/
    void setEngine(const string &engine);

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
*/
    const string &getSize() const;

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
\n REQUIRE(Airplane::size != size, "This Airplane Size already has this value.");
\n REQUIRE(size == "small" or size == "medium" or size == "large", "This Airplane Size already has this value.");
\n ENSURE(getSize() == size, "This Airplane Size is not set correctly.");
*/
    void setSize(const string &size);

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
\n REQUIRE (getStatus() == "Approaching", "Airplane is not approaching.");
\n ENSURE(getStatus() == "Standing at gate", "Airplane is not standing at a gate.");
\n ENSURE(getAirport() == airport.getName(), "Airplane is not standing at the right airport.");
*/
    int descending(Airport* &airport, Time* &time);

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
\n REQUIRE (getStatus() == "Standing at gate", "Airplane is not standing at a gate.");
\n REQUIRE (getAirport() == airport.getName(), "This Airplane does not belong to the given Airport.");
\n ENSURE(airport.getRunways()[runwayNumber].isVacant(), "Runway is still occupied.");
\n ENSURE(getGateNumber() == -1, "Airplane is still at a gate.");
*/
    int ascending(Airport* &airport, Time* &time);

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
*/
    int getFuelCost() const;

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
\n REQUIRE(Airplane::fuel_cost != fuel_cost, "This Airplane FuelCost already has this value.");
\n ENSURE(getFuelCost() == fuel_cost, "This Airplane FuelCost is not set correctly.");
\n ENSURE(getFuelCost() >= 0, "This Airplane FuelCost can't be a negative number.");
*/
    void setFuelCost(int fuel_cost);

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
*/
    int getFuel() const;

/**
\n REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized.");
\n REQUIRE(Airplane::fuel != fuel, "This Airplane Fuel already has this value.");
\n ENSURE(getFuel() == fuel, "This Airplane Fuel is not set correctly.");
\n ENSURE(getFuel() >= 0, "This Airplane Fuel can't be a negative number.");
*/
    void setFuel(int fuel);

    const bool properlyInitialized() const;
};



#endif //VLIEGVELD_AIRPLANE_H
