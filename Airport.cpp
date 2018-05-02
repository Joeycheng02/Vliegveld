//
// Created by matth on 15/03/2018.
//

#include "Airport.h"

const string &Airport::getName() const {
    return name;
}

void Airport::setName(const string &name) {
    Airport::name = name;
}

const string &Airport::getIata() const {
    return iata;
}

void Airport::setIata(const string &iata) {
    Airport::iata = iata;
}

const string &Airport::getCallsign() const {
    return callsign;
}

void Airport::setCallsign(const string &callsign) {
    Airport::callsign = callsign;
}

void Airport::addRunways(Runway runway) {
    runway.setVacant(true);
    runways.push_back(runway);
}

int Airport::getNumberOfGates() const {
    return numberOfGates;
}

void Airport::setNumberOfGates(int numberOfGates) {
    Airport::numberOfGates = numberOfGates;
    for (int i = 0; i < numberOfGates; ++i) {
        Gate gate;
        gates.push_back(gate);
        gates[i].setVacant(true);
        gates[i].setName(i+1);
        gates[i].setAirport(this->getName());
    }
}

vector<Gate> &Airport::getGates() {
    return gates;
}

vector<Runway> &Airport::getRunways() {
    return runways;
}

int Airport::getNumberOfRunways() const {
    return int(runways.size());
}

Airport::Airport() {
    heightCheck3000 = true;
    heightCheck5000 = true;
}

bool Airport::permissionToDescend(int height) {
    if (height == 10000) {
        return true;
    }
    if (height == 5000) {
        if(heightCheck3000){
            setHeightCheck5000(true);
            return true;
        }
        else {
            setHeightCheck5000(false);
            return false;
        }
    }
    if (height == 3000) {
        for (int i = 0; i < int(runways.size()); ++i) {
            if (runways[i].isVacant()) {
                setHeightCheck3000(true);
                return true;
            }
            else{
                setHeightCheck3000(false);
                return false;
            }
        }
    }
    return false;
}

bool Airport::isHeightCheck3000() const {
    return heightCheck3000;
}

void Airport::setHeightCheck3000(bool heightCheck3000) {
    Airport::heightCheck3000 = heightCheck3000;
}

bool Airport::isHeightCheck5000() const {
    return heightCheck5000;
}

void Airport::setHeightCheck5000(bool heightCheck5000) {
    Airport::heightCheck5000 = heightCheck5000;
}

bool Airport::permissionToAscend(int number) {
    if (number == -1) {
        return true;
    }
    else {
        return runways[number].isVacant();
    }
}
