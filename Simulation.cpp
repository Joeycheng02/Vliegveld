//
// Created by nightnarumi on 22/03/18.
//

#include "Simulation.h"
#include "DesignByContract.h"
using namespace std;

vector<Airport> &Simulation::getAirports() {
    return airports;
}

vector<Airplane> &Simulation::getAirplanes() {
    return airplanes;
}

vector<Runway> &Simulation::getRunways() {
    return runways;
}

void Simulation::start() {
    for (int i = 0; i < int(airplanes.size()); ++i) {
        if (airplanes[i].getStatus() == "Approaching") {
            airplanes[i].descending(airports[0]);
            airplanes[i].ascending(airports[0]);
        }
        if (airplanes[i].getStatus() == "Standing at gate") {
            for (int j = 0; j < int(airports.size()); ++j) {
                if (airplanes[i].getAirport() == airports[j].getName()) {
                    airplanes[i].ascending(airports[j]);
                    break;
                }
            }
        }
    }
}
