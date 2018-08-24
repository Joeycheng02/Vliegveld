//
// Created by nightnarumi on 22/03/18.
//

#ifndef VLIEGVELD_SIMULATION_H
#define VLIEGVELD_SIMULATION_H
#include <iostream>
#include "Runway.h"
#include "Airport.h"
#include "Airplane.h"
#include "tinyxml.h"
#include "Time.h"
#include <vector>


class Simulation {
private:
    vector <Airport*> airports;
    vector <Airplane*> airplanes;
    vector <Runway*> runways;
    Time* time;
    Simulation* _initCheck;
public:
    Simulation();

/**
\n REQUIRE(properlyInitialized(), "This Simulation object is not properly initialized");
*/
    vector<Airport*> &getAirports();

/**
\n REQUIRE(properlyInitialized(), "This Simulation object is not properly initialized");
*/
    vector<Airplane*> &getAirplanes();

/**
\n REQUIRE(properlyInitialized(), "This Simulation object is not properly initialized");
*/
    vector<Runway*> &getRunways();

/**
\n REQUIRE(properlyInitialized(), "This Simulation object is not properly initialized");
*/
    void start();

    const bool properlyInitialized() const;
};


#endif //VLIEGVELD_SIMULATION_H
