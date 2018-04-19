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
