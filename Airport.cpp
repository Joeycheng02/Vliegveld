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
