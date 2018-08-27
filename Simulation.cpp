//
// Created by nightnarumi on 22/03/18.
//

#include "Simulation.h"
#include "DesignByContract.h"

using namespace std;

Simulation::Simulation() {
    time = &_time;
    _initCheck = this;
}

Simulation::~Simulation() {
    for (int i = 0; i < int(airplanes.size()-1); ++i) {
        delete(airplanes[i]);
    }
    for (int j = 0; j < int(airports.size()-1); ++j) {
        delete(airports[j]);
    }
    for (int k = 0; k < int(runways.size()-1); ++k) {
        delete(runways[k]);
    }
}

vector<Airport*> &Simulation::getAirports() {
    REQUIRE(properlyInitialized(), "This Simulation object is not properly initialized.");
    return airports;
}

vector<Airplane*> &Simulation::getAirplanes() {
    REQUIRE(properlyInitialized(), "This Simulation object is not properly initialized.");
    return airplanes;
}

vector<Runway*> &Simulation::getRunways() {
    REQUIRE(properlyInitialized(), "This Simulation object is not properly initialized.");
    return runways;
}

void Simulation::start() {
    REQUIRE(properlyInitialized(), "This Simulation object is not properly initialized.");
    for (int i = 0; i < int(airplanes.size()); ++i) {
        if (airplanes[i]->getStatus() == "approaching") {
            airplanes[i]->descending(airports[0], time);
            airplanes[i]->ascending(airports[0], time);
        }
        if (airplanes[i]->getStatus() == "standing at gate") {
            for (int j = 0; j < int(airports.size()); ++j) {
                if (airplanes[i]->getAirport() == airports[j]->getName()) {
                    airplanes[i]->ascending(airports[j], time);
                    break;
                }
            }
        }
    }
}

const bool Simulation::properlyInitialized() const {
    return _initCheck == this;
}
