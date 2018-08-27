//
// Created by matth on 15/03/2018.
//

#include "Airport.h"
#include "DesignByContract.h"

Airport::Airport() {
    heightCheck3000 = true;
    heightCheck5000 = true;
    numberOfGates = 0;
    _initCheck = this;
}

vector<bool> &Airport::getGates() {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    return gates;
}

vector<Runway*> &Airport::getRunways() {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    return runways;
}

void Airport::addRunways(Runway* runway) {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    runway->setVacant(true);
    runways.push_back(runway);
    ENSURE(getRunways()[getRunways().size() - 1]->isVacant() == runway->isVacant(), "This Airport addRunways is not set correctly.");
}

unsigned int Airport::getNumberOfRunways() const {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    return unsigned (runways.size());
}

int Airport::getNumberOfGates() const {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    return numberOfGates;
}

void Airport::setNumberOfGates(int numberOfGates) {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    REQUIRE(Airport::numberOfGates >= 0, "This Airport numberOfGates can't be a negative number.");
    Airport::numberOfGates = numberOfGates;
    vector<bool> temp;
    for (int i = 0; i < numberOfGates; ++i) {
        temp.push_back(true);
    }
    gates = temp;

    ENSURE(getNumberOfGates() == numberOfGates, "This Airport numberOfGates is not set correctly.");
    ENSURE(getNumberOfGates() >= 0, "This Airport numberOfGates can't be a negative number.");
}

const string &Airport::getName() const {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    return name;
}

void Airport::setName(const string &name) {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    REQUIRE(Airport::name != name, "This Airport Name already has this value.");
    Airport::name = name;
    ENSURE(getName() == name, "This Airport Name is not set correctly.");
}

const string &Airport::getIata() const {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    return iata;
}

void Airport::setIata(const string &iata) {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    REQUIRE(Airport::iata != iata, "This Airport Iata already has this value.");
    Airport::iata = iata;
    ENSURE(getIata() == iata, "This Airport Iata is not set correctly.");
}

const string &Airport::getCallsign() const {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    return callsign;
}

void Airport::setCallsign(const string &callsign) {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    REQUIRE(Airport::callsign != callsign, "This Airport Callsign already has this value.");
    Airport::callsign = callsign;
    ENSURE(getCallsign() == callsign, "This Airport Callsign is not set correctly.");
}

bool Airport::permissionToDescend(int height) {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    REQUIRE(height >= 0, "This Airport Height can't be a negative number.");
    if (height == 10000) {
        return true;
    }
    if (height == 5000) {
        if(heightCheck3000){
            setHeightCheck5000(true);
            ENSURE(isHeightCheck5000(), "This Airport Height is not set correctly.");
            return true;
        }
        else {
            setHeightCheck5000(false);
            ENSURE(!isHeightCheck5000(), "This Airport Height is not set correctly.");
            return false;
        }
    }
    if (height == 3000) {
        for (int i = 0; i < int(runways.size()); ++i) {
            if (runways[i]->isVacant()) {
                setHeightCheck3000(true);
                ENSURE(isHeightCheck3000(), "This Airport Height is not set correctly.");
                return true;
            }
            else{
                setHeightCheck3000(false);
                ENSURE(!isHeightCheck3000(), "This Airport Height is not set correctly.");
                return false;
            }
        }
    }
    ENSURE(height != 10000 and height != 5000 and height != 3000, "This Airport Height function did not correctly end.");
    return false;
}

bool Airport::isHeightCheck3000() const {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    return heightCheck3000;
}

void Airport::setHeightCheck3000(bool heightCheck3000) {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    REQUIRE(Airport::heightCheck3000 or !Airport::heightCheck3000, "This Airport Height is not properly initialized.");
    Airport::heightCheck3000 = heightCheck3000;
    ENSURE(isHeightCheck3000() == heightCheck3000, "This Airport Height is not set correctly.");
}

bool Airport::isHeightCheck5000() const {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    return heightCheck5000;
}

void Airport::setHeightCheck5000(bool heightCheck5000) {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    REQUIRE(Airport::heightCheck5000 or !Airport::heightCheck5000, "This Airport Height is not properly initialized.");
    Airport::heightCheck5000 = heightCheck5000;
    ENSURE(isHeightCheck3000() == heightCheck3000, "This Airport Height is not set correctly.");
}

bool Airport::permissionToAscend(int number) {
    REQUIRE(properlyInitialized(), "This Airport object is not properly initialized.");
    REQUIRE(number >= -1, "This Airport Permission can't be less than -1.");
    if (number == -1) {
        return true;
    }
    else {
        return runways[number]->isVacant();
    }
}

const bool Airport::properlyInitialized() const {
    return _initCheck == this;
}