//
// Created by knoetson on 01.05.18.
//

#ifndef VLIEGVELD_PARSER_H
#define VLIEGVELD_PARSER_H

#include <iostream>
#include <string>
#include "Runway.h"
#include "Airport.h"
#include "Airplane.h"
#include "tinyxml.h"
#include "Simulation.h"
#include <fstream>
#include <vector>

class parser {
public:
/**
\n REQUIRE(airplanes.empty(), "Airplanes must be empty");
\n REQUIRE(airports.empty(), "Airports must be empty");
\n REQUIRE(runways.empty(), "Runways must be empty");
\n ENSURE(!airplanes.empty(), "Airplanes can't be empty");
\n ENSURE(!airports.empty(), "Airports can't be empty");
\n ENSURE(!runways.empty(), "Runways can't be empty");
*/
    static int parsing(vector<Airport> &airports, vector<Airplane> &airplanes, vector<Runway> &runways, const char* path);

/**
\n REQUIRE(!runways.empty(), "There are no runways available");
\n REQUIRE(!airports.empty(), "There are no airports available");
\n ENSURE(!airports[k].getRunways().empty(), "Airport has no runway");
*/
    static void addRunway(vector <Airport> &airports, vector <Runway> &runways);

    static void full_parsing(vector<Airport> &airports, vector<Airplane> &airplanes, vector<Runway> &runways, const char* path);

};


#endif //VLIEGVELD_PARSER_H
