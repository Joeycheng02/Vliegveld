//
// Created by matth on 15/03/2018.
//

#include "Runway.h"

const string &Runway::getName() const {
    return name;
}

void Runway::setName(const string &name) {
    Runway::name = name;
}

const string &Runway::getAirport() const {
    return airport;
}

void Runway::setAirport(const string &airport) {
    Runway::airport = airport;
}

bool Runway::isVacant() const {
    return vacant;
}

void Runway::setVacant(bool vacant) {
    Runway::vacant = vacant;
}

Runway::Runway() {
    vacant = true;
}

const string &Runway::getType() const {
    return type;
}

void Runway::setType(const string &type) {
    Runway::type = type;
}

const int &Runway::getLength() const {
    return length;
}

void Runway::setLength(const int &length) {
    Runway::length = length;
}

void Runway::add_Taxipoint(string taxipoint) {
    taxipoints.push_back(taxipoint);
}

vector<string> Runway::get_Taxipoint() {
    return taxipoints;
}

void Runway::add_Crossing(string crossing) {
    taxipoints.push_back(crossing);
}

vector<string> Runway::get_Crossing() {
    return crossings;
}