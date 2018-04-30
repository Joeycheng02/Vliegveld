//
// Created by nightnarumi on 22/03/18.
//

#ifndef VLIEGVELD_SIMULATION_H
#define VLIEGVELD_SIMULATION_H
#include <iostream>
#include <string>
#include "Runway.h"
#include "Airport.h"
#include "Airplane.h"
#include "tinyxml.h"
#include <fstream>
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

public:

    //REQUIRE airports and airplanes cant be empty.
    int outputfile (vector <Airport> &airports, vector <Airplane> &airplanes);

    //REQUIRE airplane must have the status "Approaching"
    int descending(Airplane &airplane, Airport &airport);
    //ENSURE airplane must stand at a gate of the given airport

    //REQUIRE airplane
    int ascending (Airplane &airplane, Airport &airport);
    //ENSURE the runway and gate are vacant

    //REQUIRE airplane is in the air and not approaching
    int approaching (Airplane &airplane);
    //ENSURE airplane is approaching

    void addRunway(vector <Airport> &airports, vector <Runway> &runways);
    
    int parser(vector<Airport> &airports, vector<Airplane> &airplanes, vector<Runway> &runways, const char* path);
};


#endif //VLIEGVELD_SIMULATION_H
