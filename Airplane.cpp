//
// Created by matth on 15/03/2018.
//

#include <fstream>
#include "Airplane.h"
#include "DesignByContract.h"
#include "output.h"
#include "Simulation.h"

Airplane::Airplane() {
    gateNumber = -1;
    height = 0;
    capacity = 0;
    fuel = 0;
    fuel_cost = 0;
    _initCheck = this;
}

const string &Airplane::getNumber() const {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    return number;
}

void Airplane::setNumber(const string &number) {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    REQUIRE(Airplane::number != number, "The variable already has this value");
    Airplane::number = number;
    ENSURE(getNumber() == number, "The variable is not set correctly");
}

const string &Airplane::getCallsign() const {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    return callsign;
}

void Airplane::setCallsign(const string &callsign) {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    REQUIRE(Airplane::callsign != callsign, "The variable already has this value");
    Airplane::callsign = callsign;
    ENSURE(getCallsign() == callsign, "The variable is not set correctly");
}

const string &Airplane::getModel() const {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    return model;
}

void Airplane::setModel(const string &model) {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    REQUIRE(Airplane::model != model, "The variable already has this value");
    Airplane::model = model;
    ENSURE(getModel() == model, "The variable is not set correctly");
}

const string &Airplane::getStatus() const {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    return status;
}

void Airplane::setStatus(const string &status) {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    REQUIRE(Airplane::status != status, "The variable already has this value");
    Airplane::status = status;
    ENSURE(getStatus() == status, "The variable is not set correctly");
}

int Airplane::getHeight() const {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    return height;
}

void Airplane::setHeight(int height) {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    REQUIRE(Airplane::height >= 0, "The variable is not properly initialized");
    Airplane::height = height;
    ENSURE(getHeight() == height, "The variable is not set correctly");
    ENSURE(getHeight() >= 0, "The variable can't be a negative number");
}

const string &Airplane::getAirport() const {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    return airport;
}

void Airplane::setAirport(const string &airport) {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    REQUIRE(Airplane::airport != airport, "The variable already has this value");
    Airplane::airport = airport;
    ENSURE(getAirport() == airport, "The variable is not set correctly");
}

int Airplane::getGateNumber() const {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    return gateNumber;
}

void Airplane::setGateNumber(int gateNumber) {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    REQUIRE(Airplane::gateNumber >= -1, "The variable is not properly initialized");
    Airplane::gateNumber = gateNumber;
    ENSURE(getGateNumber() == gateNumber, "The variable is not set correctly");
    ENSURE(getGateNumber() >= -1, "The variable can't be less than -1");
}

int Airplane::getCapacity() const {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    return capacity;
}

void Airplane::setCapacity(int capacity) {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    REQUIRE(Airplane::capacity >=0, "The variable is not properly initialized");
    Airplane::capacity = capacity;
    ENSURE(getCapacity() == capacity, "The variable is not set correctly");
    ENSURE(getCapacity() >= 0, "The variable can't be a negative number");
}

const string &Airplane::getType() const {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    return type;
}

void Airplane::setType(const string &type) {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    REQUIRE(Airplane::type !=type , "The variable already has this value");
    Airplane::type = type;
    ENSURE(getType() == type, "The variable is not set correctly");
}

const string &Airplane::getEngine() const {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    return engine;
}

void Airplane::setEngine(const string &engine) {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    REQUIRE(Airplane::engine != engine, "The variable already has this value");
    Airplane::engine = engine;
    ENSURE(getEngine() == engine, "The variable is not set correctly");
}

const string &Airplane::getSize() const {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    return size;
}

void Airplane::setSize(const string &size) {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    REQUIRE(Airplane::size != size, "The variable already has this value");
    Airplane::size = size;
    ENSURE(getSize() == size, "The variable is not set correctly");
}

int Airplane::descending(Airport* &airport, Time* &time) {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    REQUIRE (getStatus() == "approaching", "Airplane is not approaching");

    ofstream console ("console_output.txt", fstream::app);
    if (!console) {
        cout << "Couldn't open the file." << endl;
        return -1;
    }

    for (int i = 0; i <= airport->getNumberOfGates(); ++i) {
        if (i == airport->getNumberOfGates()) {
            console << "[" << time->printTime() << "] " << "Instructing " << getCallsign() << " to take a holding pattern untill a clearance is made to land." << endl;
            output::landing(*this, *airport, *airport->getRunways()[0], 2, time);
            return -1;
        }

        if (airport->getGates()[i]) {
            airport->getGates()[i] = false;
            setGateNumber(i+1);
            break;
        }
    }

    int runwayNumber = -1;
    for (unsigned int i = 0; i <= airport->getNumberOfRunways(); ++i) {
        if (i == airport->getNumberOfRunways()) {
            console << "[" << time->printTime() << "] " << "Instructing " << getCallsign() << " to wait untill there is a free runway." << endl;
            output::landing(*this, *airport, *airport->getRunways()[0], 2, time);
            return -1;
        }

        if (airport->getRunways()[i]->isVacant()) {
            runwayNumber = i;
            break;
        }
    }

    if (getHeight() != 10000) {
        console << "[" << time->printTime() << "] " << "Instructing " << getCallsign() << " to get an height of 10.000ft." << endl;
        setHeight(10000);
    }
    console << "[" << time->printTime() << "] " << getCallsign() << " is approaching " << airport->getName() << " at 10.000ft." << endl;
    while (getHeight() > 1000) {
        if(getHeight() == 10000 or getHeight() == 5000 or getHeight() == 3000) {
            if (!airport->permissionToDescend(getHeight())) {
                return -1;
            }
            if(getHeight() == 10000){
                output::landing(*this, *airport, *airport->getRunways()[runwayNumber], 1, time);
            }
            if(getHeight() == 5000){
                output::landing(*this, *airport, *airport->getRunways()[runwayNumber], 3, time);
            }
            if(getHeight() == 3000){
                output::landing(*this, *airport, *airport->getRunways()[runwayNumber], 4, time);
            }
        }
        setHeight(getHeight() - 1000);
        if (getEngine() == "propeller") {
            time->addTime(2);
            setFuel(getFuel() - getFuelCost() * 2);
        }
        else {
            time->addTime(1);
            setFuel(getFuel() - getFuelCost());
        }
        console << "[" << time->printTime() << "] " << getCallsign() << " descended to " << getHeight() << " ft." << endl;
    }
    setHeight(getHeight() - 1000);
    airport->getRunways()[runwayNumber]->setVacant(false);
    console << "[" << time->printTime() << "] " << getCallsign() << " is landing at "<< airport->getName() << " on runway " << airport->getRunways()[runwayNumber]->getName() << endl;
    time->addTime(2);
    setFuel(getFuel() - getFuelCost() * 2);
    console << "[" << time->printTime() << "] " << getCallsign() << " has landed at "<< airport->getName() << " on runway " << airport->getRunways()[runwayNumber]->getName() << endl;
    console << "[" << time->printTime() << "] " << getCallsign() << " is taxiing to Gate " << getGateNumber() << endl;
    output::landing(*this, *airport, *airport->getRunways()[runwayNumber], 5, time);
    for(unsigned int r = 0; r < airport->getRunways()[runwayNumber]->getCrossing().size(); r++){
        output::taxien(*this, *airport, *airport->getRunways()[runwayNumber], 1, time, airport->getRunways()[runwayNumber]->getTaxipoint()[r], gateNumber);
        console << "[" << time->printTime() << "] " << this->getCallsign() << " is standing at taxipoint " <<  airport->getRunways()[runwayNumber]->getTaxipoint()[r] << " and is waiting for permission to cross runway " << airport->getRunways()[runwayNumber]->getCrossing()[r]->getName() << "." << endl;
        output::taxien(*this, *airport, *airport->getRunways()[runwayNumber], 4, time, airport->getRunways()[runwayNumber]->getTaxipoint()[r], gateNumber);
        while(!airport->getRunways()[runwayNumber]->getCrossing()[r]->isVacant()){
            console << "[" << time->printTime() << "] " << this->getCallsign() << " has no permission to cross and is waiting." << endl;
        }
        console << "[" << time->printTime() << "] " << this->getCallsign() << " is crossing runway " << airport->getRunways()[runwayNumber]->getCrossing()[r]->getName() << " to taxipoint " << airport->getRunways()[runwayNumber]->getTaxipoint()[r+1] << "." << endl;
        time->addTime(1);
        output::taxien(*this, *airport, *airport->getRunways()[runwayNumber], 3, time, airport->getRunways()[runwayNumber]->getTaxipoint()[r], gateNumber);

    }
    console << "[" << time->printTime() << "] " << getCallsign() << " is standing at Gate " << getGateNumber() << endl;
    airport->getRunways()[runwayNumber]->setVacant(true);
    setAirport(airport->getName());
    setStatus("standing at gate");
    time->addTime(getCapacity()/2);
    console << "[" << time->printTime() << "] " << getCapacity() << " passengers exited " << getCallsign() << " at gate " << getGateNumber() << " of " << airport->getName() << endl;
    if (getSize() == "small") {
        time->addTime(1);
    }
    else if (getSize() == "medium") {
        time->addTime(2);
    }
    else {
        time->addTime(3);
    }
    console << "[" << time->printTime() << "] " << getCallsign() << " has been checked for technical malfunctions" << endl << endl;

    ENSURE(getStatus() == "standing at gate", "Airplane is not standing at a gate");
    ENSURE(getAirport() == airport->getName(), "Airplane is not standing at the right airport");

    console.close();
    return 0;
}


int Airplane::ascending (Airport* &airport, Time* &time) {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    REQUIRE (getStatus() == "standing at gate", "Airplane is not standing at a gate");
    REQUIRE (getAirport() == airport->getName(), "This airplane does not belong to the given aiport.");

    ofstream console("console_output.txt", fstream::app);
    if (!console) {
        cout << "Couldn't open the file." << endl;
        return -1;
    }

    int runwayNumber = -1;

    for (unsigned int i = 0; i <= airport->getNumberOfRunways(); ++i) {
        if (i == airport->getNumberOfRunways()) {
            console << "[" << time->printTime() << "] " << "Instructing " << getCallsign() << " to wait untill there is a free runway." << endl;
            return -1;
        }

        if (airport->getRunways()[i]->isVacant()) {
            runwayNumber = i;
            break;
        }
    }
    time->addTime(getFuel()/10000);
    console << "[" << time->printTime() << "] " << getCallsign() << " has been refueled" << endl;
    time->addTime(getCapacity()/2);
    console << "[" << time->printTime() << "] " << getCapacity() << " passengers boarded " << getCallsign() << " at gate " << getGateNumber() << " of " << airport->getName() << endl;

    output::ascending(*this, *airport, *airport->getRunways()[runwayNumber], 1, time);
    output::ascending(*this, *airport, *airport->getRunways()[runwayNumber], 2, time);

    airport->getGates()[getGateNumber()-1] = true;
    setGateNumber(-1);

    airport->permissionToAscend(-1);
    output::ascending(*this, *airport, *airport->getRunways()[runwayNumber], 3, time);
    output::ascending(*this, *airport, *airport->getRunways()[runwayNumber], 4, time);
    console << "[" << time->printTime() << "] " << getCallsign() << " is taxiing to runway " << airport->getRunways()[runwayNumber]->getName() << "." << endl;
    if (!airport->getRunways()[runwayNumber]->getCrossing().empty()) {
        for (long r = airport->getRunways()[runwayNumber]->getCrossing().size()-1; r > -1; r--) {
            output::taxien(*this, *airport, *airport->getRunways()[runwayNumber], 1, time, airport->getRunways()[runwayNumber]->getTaxipoint()[r], gateNumber);
            console << "[" << time->printTime() << "] " << this->getCallsign() << " is standing at taxipoint "
                    << airport->getRunways()[runwayNumber]->getTaxipoint()[r+1]
                    << " and is waiting for permission to cross runway "
                    << airport->getRunways()[runwayNumber]->getCrossing()[r]->getName() << "." << endl;
            output::taxien(*this, *airport, *airport->getRunways()[runwayNumber], 4, time, airport->getRunways()[runwayNumber]->getTaxipoint()[r], gateNumber);
            while(!airport->getRunways()[runwayNumber]->getCrossing()[r]->isVacant()){
                console << "[" << time->printTime() << "] " << this->getCallsign() << " has no permission to cross and is waiting." << endl;
            }
            console << "[" << time->printTime() << "] " << this->getCallsign() << " is crossing runway "
                    << airport->getRunways()[runwayNumber]->getCrossing()[r]->getName() << " to taxipoint " << airport->getRunways()[runwayNumber]->getTaxipoint()[r] << "." << endl;
            time->addTime(1);
            output::taxien(*this, *airport, *airport->getRunways()[runwayNumber], 2, time, airport->getRunways()[runwayNumber]->getTaxipoint()[r], gateNumber);
        }
    }
    output::ascending(*this, *airport, *airport->getRunways()[runwayNumber], 5, time);
    if (!airport->permissionToAscend(runwayNumber)) {
        return -1;
    }
    output::ascending(*this, *airport, *airport->getRunways()[runwayNumber], 6, time);
    airport->getRunways()[runwayNumber]->setVacant(false);
    output::ascending(*this, *airport, *airport->getRunways()[runwayNumber], 7, time);
    console << "[" << time->printTime() << "] " << getCallsign() << " is taking off at " << airport->getName() << " on runway " << airport->getRunways()[runwayNumber]->getName() << endl;
    if (getEngine() == "propeller") {
        time->addTime(3);
        setFuel(getFuel() - getFuelCost() * 3);
    }
    else {
        time->addTime(2);
        setFuel(getFuel() - getFuelCost() * 2);
    }
    console << "[" << time->printTime() << "] " << getCallsign() << " has departed" << endl;
    setStatus("departed");
    while (getHeight() < 5000) {
        setHeight(getHeight() + 1000);
        if (getEngine() == "propeller") {
            time->addTime(2);
            setFuel(getFuel() - getFuelCost() * 2);
        }
        else {
            time->addTime(1);
            setFuel(getFuel() - getFuelCost());
        }
        console << "[" << time->printTime() << "] " << getCallsign() << " has ascended to " << getHeight() << " ft." << endl;

    }
    console << "[" << time->printTime() << "] " << getCallsign() << " has left " << airport->getName() << endl << endl;
    airport->getRunways()[runwayNumber]->setVacant(true);
    setAirport("No airport assigned");

    ENSURE(airport->getRunways()[runwayNumber]->isVacant(), "Runway is still occupied");
    ENSURE(getGateNumber() == -1, "Airplane is still at a gate");
    console.close();
    return 0;
}

int Airplane::getFuelCost() const {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    return fuel_cost;
}

void Airplane::setFuelCost(int fuel_cost) {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    REQUIRE(Airplane::fuel_cost != fuel_cost, "The variable already has this value");
    Airplane::fuel_cost = fuel_cost;
    ENSURE(getFuelCost() == fuel_cost, "The variable is not set correctly");
    ENSURE(getFuelCost() >= 0, "The variable can't be a negative number");

}

int Airplane::getFuel() const {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    return fuel;
}

void Airplane::setFuel(int fuel) {
    REQUIRE(properlyInitialized(), "This Airplane object is not properly initialized");
    REQUIRE(Airplane::fuel != fuel, "The variable already has this value");
    Airplane::fuel = fuel;
    ENSURE(getFuel() == fuel, "The variable is not set correctly");
    ENSURE(getFuel() >= 0, "The variable can't be a negative number");

}

const bool Airplane::properlyInitialized() const {
    return _initCheck == this;
}

