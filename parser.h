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
    static int parsing(vector<Airport> &airports, vector<Airplane> &airplanes, vector<Runway> &runways, const char* path);

    static void addRunway(vector <Airport> &airports, vector <Runway> &runways);

    static void full_parsing(vector<Airport> &airports, vector<Airplane> &airplanes, vector<Runway> &runways, const char* path);

};


#endif //VLIEGVELD_PARSER_H
