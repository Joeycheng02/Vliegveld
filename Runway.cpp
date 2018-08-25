//
// Created by matth on 15/03/2018.
//

#include "Runway.h"
#include "DesignByContract.h"

Runway::Runway() {
    vacant = true;
    length = 0;
    _initCheck = this;
}

const string &Runway::getName() const {
    REQUIRE(properlyInitialized(), "This Runway object is not properly initialized.");
    return name;
}

void Runway::setName(const string &name) {
    REQUIRE(properlyInitialized(), "This Runway object is not properly initialized.");
    REQUIRE(Runway::name != name, "This Runway Name already has this value.");
    REQUIRE(!name.empty(), "A Runway Name can't have an empty string.");
    Runway::name = name;
    ENSURE(!getName().empty(), "A Runway Name can't have an empty string.");
    ENSURE(getName() == name, "This Runway Name is not set correctly.");
}

const string &Runway::getAirport() const {
    REQUIRE(properlyInitialized(), "This Runway object is not properly initialized.");
    return airport;
}

void Runway::setAirport(const string &airport) {
    REQUIRE(properlyInitialized(), "This Runway object is not properly initialized.");
    REQUIRE(Runway::airport != airport, "This Runway Airport already has this value.");
    Runway::airport = airport;
    ENSURE(getAirport() == airport, "This Runway Airport is not set correctly.");
}

bool Runway::isVacant() const {
    REQUIRE(properlyInitialized(), "This Runway object is not properly initialized.");
    return vacant;
}

void Runway::setVacant(bool vacant) {
    REQUIRE(properlyInitialized(), "This Runway object is not properly initialized.");
    REQUIRE(Runway::isVacant() or !Runway::isVacant(), "This Runway Vacant bool is not properly initialized.");
    Runway::vacant = vacant;
    ENSURE(isVacant() == vacant, "This Runway Vacant bool is not set correctly.");
}

const string &Runway::getType() const {
    REQUIRE(properlyInitialized(), "This Runway object is not properly initialized.");
    return type;
}

void Runway::setType(const string &type) {
    REQUIRE(properlyInitialized(), "This Runway object is not properly initialized.");
    REQUIRE(Runway::type != type, "This Runway Type already has this value.");
    REQUIRE(type == "grass" or type == "asphalt", "This Runway Type is not a valuable value.");
    Runway::type = type;
    ENSURE(getType() == type, "The Runway Type is not set correctly.");
}

const int &Runway::getLength() const {
    REQUIRE(properlyInitialized(), "This Runway object is not properly initialized.");
    return length;
}

void Runway::setLength(const int &length) {
    REQUIRE(properlyInitialized(), "This Runway object is not properly initialized.");
    REQUIRE(Runway::length >= 0, "This Runway Length is not properly initialized.");
    Runway::length = length;
    ENSURE(getLength() == length, "This Runway Length is not set correctly.");
    ENSURE(getLength() >= 0, "This Runway Length can't be a negative number.");
}

void Runway::addTaxipoint(string taxipoint) {
    REQUIRE(properlyInitialized(), "This Runway object is not properly initialized.");
    taxipoints.push_back(taxipoint);
    ENSURE(getTaxipoint()[getTaxipoint().size() - 1]== taxipoint, "The Runway Taxipoint is not set correctly.");
}

vector<string> Runway::getTaxipoint() {
    REQUIRE(properlyInitialized(), "This Runway object is not properly initialized.");
    return taxipoints;
}

void Runway::addCrossing(Runway* crossing) {
    REQUIRE(properlyInitialized(), "This Runway object is not properly initialized.");
    crossings.push_back(crossing);
    ENSURE(getCrossing()[getCrossing().size() - 1]== crossing, "This Runway Crossing is not set correctly.");

}

vector<Runway*> Runway::getCrossing() {
    REQUIRE(properlyInitialized(), "This Runway object is not properly initialized.");
    return crossings;
}

const vector<string> &Runway::getCrossings_string() const {
    REQUIRE(properlyInitialized(), "This Runway object is not properly initialized.");
    return crossings_string;
}

void Runway::addCrossings_string(string &crossings_string) {
    REQUIRE(properlyInitialized(), "This Runway object is not properly initialized.");
    Runway::crossings_string.push_back(crossings_string);
    ENSURE(getCrossings_string()[getCrossings_string().size() - 1]== crossings_string, "This Runway Crossing is not set correctly.");

}

const bool Runway::properlyInitialized() const {
    return _initCheck == this;
}
