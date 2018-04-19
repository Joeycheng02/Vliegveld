//
// Created by matth on 15/03/2018.
//

#include "Airplane.h"

const string &Airplane::getNumber() const {
    return number;
}

void Airplane::setNumber(const string &number) {
    Airplane::number = number;
}

const string &Airplane::getCallsign() const {
    return callsign;
}

void Airplane::setCallsign(const string &callsign) {
    Airplane::callsign = callsign;
}

const string &Airplane::getModel() const {
    return model;
}

void Airplane::setModel(const string &model) {
    Airplane::model = model;
}

const string &Airplane::getStatus() const {
    return status;
}

void Airplane::setStatus(const string &status) {
    Airplane::status = status;
}

int Airplane::getHeight() const {
    return height;
}

void Airplane::setHeight(int height) {
    Airplane::height = height;
}

const string &Airplane::getAirport() const {
    return airport;
}

void Airplane::setAirport(const string &airport) {
    Airplane::airport = airport;
}

int Airplane::getGateNumber() const {
    return gateNumber;
}

void Airplane::setGateNumber(int gateNumber) {
    Airplane::gateNumber = gateNumber;
}

int Airplane::getPassengers() const {
    return passengers;
}

void Airplane::setPassengers(int passengers) {
    Airplane::passengers = passengers;
}

Airplane::Airplane() {
    gateNumber = -1;

}
