//
// Created by matth on 15/03/2018.
//

#include "Airport.h"
#include "DesignByContract.h"

Airport::Airport() {
    heightCheck3000 = true;
    heightCheck5000 = true;
    numberOfGates = 0;
}

vector<bool> &Airport::getGates() {
    return gates;
}

vector<Runway> &Airport::getRunways() {
    return runways;
}

void Airport::addRunways(Runway runway) {
    runway.setVacant(true);
    runways.push_back(runway);
    ENSURE(getRunways()[getRunways().size() - 1].isVacant() == runway.isVacant(), "The variable is not set correctly");
}

int Airport::getNumberOfRunways() const {
    return int(runways.size());
}

int Airport::getNumberOfGates() const {
    return numberOfGates;
}

void Airport::setNumberOfGates(int numberOfGates) {
    REQUIRE(Airport::numberOfGates >= 0, "The variable is not properly initialized");
    Airport::numberOfGates = numberOfGates;
    for (int i = 0; i < numberOfGates; ++i) {
        gates.push_back(true);
    }
    ENSURE(getNumberOfGates() == numberOfGates, "The variable is not set correctly");
    ENSURE(getNumberOfGates() >= 0, "The variable can't be a negative number");
}

const string &Airport::getName() const {
    return name;
}

void Airport::setName(const string &name) {
    REQUIRE(Airport::name != name, "The variable already has this value");
    Airport::name = name;
    ENSURE(getName() == name, "The variable is not set correctly");
}

const string &Airport::getIata() const {
    return iata;
}

void Airport::setIata(const string &iata) {
    REQUIRE(Airport::iata != iata, "The variable already has this value");
    Airport::iata = iata;
    ENSURE(getIata() == iata, "The variable is not set correctly");
}

const string &Airport::getCallsign() const {
    return callsign;
}

void Airport::setCallsign(const string &callsign) {
    REQUIRE(Airport::callsign != callsign, "The variable already has this value");
    Airport::callsign = callsign;
    ENSURE(getCallsign() == callsign, "The variable is not set correctly");
}

bool Airport::permissionToDescend(int height) {
    REQUIRE(height >= 0, "The variable can't be a negative number");
    if (height == 10000) {
        return true;
    }
    if (height == 5000) {
        if(heightCheck3000){
            setHeightCheck5000(true);
            ENSURE(isHeightCheck5000(), "The variable is not set correctly");
            return true;
        }
        else {
            setHeightCheck5000(false);
            ENSURE(!isHeightCheck5000(), "The variable is not set correctly");
            return false;
        }
    }
    if (height == 3000) {
        for (int i = 0; i < int(runways.size()); ++i) {
            if (runways[i].isVacant()) {
                setHeightCheck3000(true);
                ENSURE(isHeightCheck3000(), "The variable is not set correctly");
                return true;
            }
            else{
                setHeightCheck3000(false);
                ENSURE(!isHeightCheck3000(), "The variable is not set correctly");
                return false;
            }
        }
    }
    ENSURE(height != 10000 and height != 5000 and height != 3000, "The function did not correctly end");
    return false;
}

bool Airport::isHeightCheck3000() const {
    return heightCheck3000;
}

void Airport::setHeightCheck3000(bool heightCheck3000) {
    REQUIRE(Airport::heightCheck3000 or !Airport::heightCheck3000, "The variable is not properly initialized");
    Airport::heightCheck3000 = heightCheck3000;
    ENSURE(isHeightCheck3000() == heightCheck3000, "The variable is not set correctly");
}

bool Airport::isHeightCheck5000() const {
    return heightCheck5000;
}

void Airport::setHeightCheck5000(bool heightCheck5000) {
    REQUIRE(Airport::heightCheck5000 or !Airport::heightCheck5000, "The variable is not properly initialized");
    Airport::heightCheck5000 = heightCheck5000;
    ENSURE(isHeightCheck3000() == heightCheck3000, "The variable is not set correctly");
}

bool Airport::permissionToAscend(int number) {
    REQUIRE(number >= -1, "The value can't be less than -1");
    if (number == -1) {
        return true;
    }
    else {
        return runways[number].isVacant();
    }
}