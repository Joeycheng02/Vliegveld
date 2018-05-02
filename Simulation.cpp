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
