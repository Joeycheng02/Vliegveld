//
// Created by matth on 15/03/2018.
//

#include "Runway.h"
#include "DesignByContract.h"

Runway::Runway() {
    vacant = true;
    length = 0;
}

const string &Runway::getName() const {
    return name;
}

void Runway::setName(const string &name) {
    REQUIRE(Runway::name != name, "The variable already has this value");
    Runway::name = name;
    ENSURE(getName() == name, "The variable is not set correctly");
}

const string &Runway::getAirport() const {
    return airport;
}

void Runway::setAirport(const string &airport) {
    REQUIRE(Runway::airport != airport, "The variable already has this value");
    Runway::airport = airport;
    ENSURE(getAirport() == airport, "The variable is not set correctly");
}

bool Runway::isVacant() const {
    return vacant;
}

void Runway::setVacant(bool vacant) {
    REQUIRE(Runway::isVacant() or !Runway::isVacant(), "The variable is not properly initialized");
    Runway::vacant = vacant;
    ENSURE(isVacant() == vacant, "The variable is not set correctly");
}

const string &Runway::getType() const {
    return type;
}

void Runway::setType(const string &type) {
    REQUIRE(Runway::type != type, "The variable already has this value");
    Runway::type = type;
    ENSURE(getType() == type, "The variable is not set correctly");
}

const unsigned int &Runway::getLength() const {
    return length;
}

void Runway::setLength(const unsigned int &length) {
    REQUIRE(Runway::length >= 0, "The variable is not properly initialized");
    Runway::length = length;
    ENSURE(getLength() == length, "The variable is not set correctly");
    ENSURE(getLength() >= 0, "The variable can't be a negative number");
}

void Runway::addTaxipoint(string taxipoint) {
    taxipoints.push_back(taxipoint);
    ENSURE(getTaxipoint()[getTaxipoint().size() - 1]== taxipoint, "The variable is not set correctly");
}

vector<string> Runway::getTaxipoint() {
    return taxipoints;
}

void Runway::addCrossing(Runway* crossing) {
    crossings.push_back(crossing);
}

vector<Runway*> Runway::getCrossing() {
    return crossings;
}

const vector<string> &Runway::getCrossings_string() const {
    return crossings_string;
}

void Runway::addCrossings_string(string &crossings_string) {
    Runway::crossings_string.push_back(crossings_string);
}
