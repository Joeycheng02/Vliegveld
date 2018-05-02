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
#include <vector>


class Simulation {
private:
    vector <Airport> airports;
    vector <Airplane> airplanes;
    vector <Runway> runways;
public:
    vector<Airport> &getAirports();

    vector<Airplane> &getAirplanes();

    vector<Runway> &getRunways();
};


#endif //VLIEGVELD_SIMULATION_H
