//
// Created by matth on 15/03/2018.
//

#include "Airplane.h"
#include "DesignByContract.h"
#include "output.h"

const string &Airplane::getNumber() const {
    return number;
}

void Airplane::setNumber(const string &number) {
    REQUIRE(Airplane::number != number, "The variable already has this value");
    Airplane::number = number;
    ENSURE(getNumber() == number, "The variable is not set correctly");
}

const string &Airplane::getCallsign() const {
    return callsign;
}

void Airplane::setCallsign(const string &callsign) {
    REQUIRE(Airplane::callsign != callsign, "The variable already has this value");
    Airplane::callsign = callsign;
    ENSURE(getCallsign() == callsign, "The variable is not set correctly");
}

const string &Airplane::getModel() const {
    return model;
}

void Airplane::setModel(const string &model) {
    REQUIRE(Airplane::model != model, "The variable already has this value");
    Airplane::model = model;
    ENSURE(getModel() == model, "The variable is not set correctly");
}

const string &Airplane::getStatus() const {
    return status;
}

void Airplane::setStatus(const string &status) {
    REQUIRE(Airplane::status != status, "The variable already has this value");
    Airplane::status = status;
    ENSURE(getStatus() == status, "The variable is not set correctly");
}

int Airplane::getHeight() const {
    return height;
}

void Airplane::setHeight(int height) {
    REQUIRE(Airplane::height >= 0, "The variable is not properly initialized");
    Airplane::height = height;
    ENSURE(getHeight() == height, "The variable is not set correctly");
    ENSURE(getHeight() >= 0, "The variable can't be a negative number");
}

const string &Airplane::getAirport() const {
    return airport;
}

void Airplane::setAirport(const string &airport) {
    REQUIRE(Airplane::airport != airport, "The variable already has this value");
    Airplane::airport = airport;
    ENSURE(getAirport() == airport, "The variable is not set correctly");
}

int Airplane::getGateNumber() const {
    return gateNumber;
}

void Airplane::setGateNumber(int gateNumber) {
    REQUIRE(Airplane::gateNumber >= -1, "The variable is not properly initialized");
    Airplane::gateNumber = gateNumber;
    ENSURE(getGateNumber() == gateNumber, "The variable is not set correctly");
    ENSURE(getGateNumber() >= -1, "The variable can't be less than -1");
}

int Airplane::getCapacity() const {
    return capacity;
}

void Airplane::setCapacity(int capacity) {
    REQUIRE(Airplane::capacity >=0, "The variable is not properly initialized");
    Airplane::capacity = capacity;
    ENSURE(getCapacity() == capacity, "The variable is not set correctly");
    ENSURE(getCapacity() >= 0, "The variable can't be a negative number");
}

const string &Airplane::getType() const {
    return type;
}

void Airplane::setType(const string &type) {
    REQUIRE(Airplane::type !=type , "The variable already has this value");
    Airplane::type = type;
    ENSURE(getType() == type, "The variable is not set correctly");
}

const string &Airplane::getEngine() const {
    return engine;
}

void Airplane::setEngine(const string &engine) {
    REQUIRE(Airplane::engine != engine, "The variable already has this value");
    Airplane::engine = engine;
    ENSURE(getEngine() == engine, "The variable is not set correctly");
}

const string &Airplane::getSize() const {
    return size;
}

void Airplane::setSize(const string &size) {
    REQUIRE(Airplane::size != size, "The variable already has this value");
    Airplane::size = size;
    ENSURE(getSize() == size, "The variable is not set correctly");
}

Airplane::Airplane() {
    gateNumber = -1;
    height = 0;
    capacity = 0;
}

int Airplane::descending(Airport &airport) {

    REQUIRE (getStatus() == "Approaching", "Airplane is not approaching");

    Gate gate;
    for (int i = 0; i <= airport.getNumberOfGates(); ++i) {
        if (i == airport.getNumberOfGates()) {
            cout << "Instructing " << getCallsign() << " to take a holding pattern untill a clearance is made to land." << endl;
            output::landing(*this, airport, airport.getRunways()[0], 2);
            return -1;
        }
        if (airport.getGates()[i].isVacant()) {
            airport.getGates()[i].setVacant(false);
            gate = airport.getGates()[i];
            break;
        }
    }

    int runwayNumber;
    for (int i = 0; i <= airport.getNumberOfRunways(); ++i) {
        if (i == airport.getNumberOfRunways()) {
            cout << "Instructing " << getCallsign() << " to wait untill there is a free runway." << endl;
            output::landing(*this, airport, airport.getRunways()[0], 2);
            return -1;
        }

        if (airport.getRunways()[i].isVacant()) {
            runwayNumber = i;
            break;
        }
    }

    if (getHeight() != 10000) {
        cout << "Instructing " << getCallsign() << " to get an height of 10.000ft." << endl;
        setHeight(10000);
    }
    cout << getCallsign() << " is approaching " << airport.getName() << " at 10.000ft." << endl;
    output::landing(*this, airport, airport.getRunways()[runwayNumber], 1);
    while (getHeight() > 1000) {
        if(getHeight() == 10000 or getHeight() == 5000 or getHeight() == 3000) {
            if (!airport.permissionToDescend(getHeight())) {
                return -1;
            }
        }
        setHeight(getHeight() - 1000);
        cout << getCallsign() << " descended to " << getHeight() << " ft." << endl;
    }
    setHeight(getHeight() - 1000);
    airport.getRunways()[runwayNumber].setVacant(false);
    cout << getCallsign() << " is landing at "<< airport.getName() << " on runway " << airport.getRunways()[runwayNumber].getName() << endl;
    cout << getCallsign() << " has landed at "<< airport.getName() << " on runway " << airport.getRunways()[runwayNumber].getName() << endl;
    cout << getCallsign() << " is taxiing to Gate " << gate.getName() << endl;
    cout << getCallsign() << " is standing at Gate " << gate.getName() << endl;
    airport.getRunways()[runwayNumber].setVacant(true);
    setAirport(airport.getName());
    setGateNumber(gate.getName());
    setStatus("Standing at gate");
    cout << getCapacity() << " passengers exited " << getCallsign() << " at gate " << gate.getName() << " of " << airport.getName() << endl;
    cout << getCallsign() << " has been checked for technical malfunctions" << endl << endl;

    ENSURE(getStatus() == "Standing at gate", "Airplane is not standing at a gate");
    ENSURE(getAirport() == airport.getName(), "Airplane is not standing at the right airport");

    return 0;
}


int Airplane::ascending (Airport &airport) {

    REQUIRE (getStatus() == "Standing at gate", "Airplane is not standing at a gate");

    REQUIRE (getAirport() == airport.getName(), "This airplane does not belong to the given aiport.");

    int runwayNumber;

    for (int i = 0; i <= airport.getNumberOfRunways(); ++i) {
        if (i == airport.getNumberOfRunways()) {
            cout << "Instructing " << getCallsign() << " to wait untill there is a free runway." << endl;
            return -1;
        }

        if (airport.getRunways()[i].isVacant()) {
            runwayNumber = i;
            break;
        }
    }

    cout << getCallsign() << " has been refueled" << endl;
    cout << getCapacity() << " passengers boarded " << getCallsign() << " at gate " << airport.getGates()[getGateNumber()-1].getName() << " of " << airport.getName() << endl;

    airport.getGates()[getGateNumber()-1].setVacant(true);
    setGateNumber(-1);

    airport.permissionToAscend(-1);
    cout << getCallsign() << " is taxiing to runway " << airport.getRunways()[runwayNumber].getName() << "." << endl;
    if (!airport.permissionToAscend(runwayNumber)) {
        return -1;
    }
    airport.getRunways()[runwayNumber].setVacant(false);
    cout << getCallsign() << " is taking off at " << airport.getName() << " on runway " << airport.getRunways()[runwayNumber].getName() << endl;

    while (getHeight() < 5000) {
        setHeight(getHeight() + 1000);
        cout << getCallsign() << " has ascended to " << getHeight() << " ft." << endl;
    }
    cout << getCallsign() << " has left " << airport.getName() << endl << endl;
    airport.getRunways()[runwayNumber].setVacant(true);
    setAirport("No airport assigned");
    setStatus("Departed");
    return 0;

    ENSURE(airport.getRunways()[runwayNumber].isVacant(), "Runway is still occupied");
    ENSURE(getGateNumber() == -1, "Airplane is still at a gate");
}
