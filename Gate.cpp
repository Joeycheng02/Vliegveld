//
// Created by nightnarumi on 21/03/18.
//

#include "Gate.h"

const string &Gate::getAirport() const {
    return airport;
}

void Gate::setAirport(const string &airport) {
    Gate::airport = airport;
}

bool Gate::isVacant() const {
    return vacant;
}

void Gate::setVacant(bool vacant) {
    Gate::vacant = vacant;
}

int Gate::getName() const {
    return name;
}

void Gate::setName(int name) {
    Gate::name = name;
}

Gate::Gate() {
    vacant = true;
}
