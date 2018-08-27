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
\n REQUIRE(airplanes.empty(), "Airplanes must be empty.");
\n REQUIRE(airports.empty(), "Airports must be empty.");
\n REQUIRE(runways.empty(), "Runways must be empty.");
\n REQUIRE(doc.LoadFile(path), doc.ErrorDesc());
\n REQUIRE((root != NULL), "Failed to load file: No root element.");
\n REQUIRE((elemName == "AIRPORT" or elemName == "RUNWAY" or elemName == "AIRPLANE"), "Dit staat niet in de parser en wordt dus genegeerd.");
\n REQUIRE(elem2->FirstChild() != NULL, "This variable of Airport can't be empty.");
\n REQUIRE((elem2Name == "name" or elem2Name == "iata" or elem2Name == "callsign" or
                        elem2Name == "gates"), "Dit is geen variabele van Airport.");
\n REQUIRE(elem2->FirstChild() != NULL, "This variable of Runway can't be empty.");
\n REQUIRE((elem2Name == "name" or elem2Name == "airport" or elem2Name == "type" or elem2Name == "length"
                        or elem2Name == "TAXIROUTE"), "Dit is geen variabele van Runway.");
\n REQUIRE(elem3->FirstChild() != NULL, "This variable of Taxiroute can't be empty.");
\n REQUIRE((elem3Name == "taxipoint" or elem3Name == "crossing"), "Dit is geen variabele van Runway.");
\n REQUIRE(elem2->FirstChild() != NULL, "This variable of Airplane can't be empty.");
\n REQUIRE(elem2Name == "model" or elem2Name == "number" or elem2Name == "callsign" or elem2Name == "type" or elem2Name == "engine" or elem2Name == "size" or
                    elem2Name == "status" or elem2Name == "capacity" or elem2Name == "fuel", "Dit is geen variabele van Airplane.");
\n ENSURE(!airplanes.empty(), "Airplanes can't be empty.");
\n ENSURE(!airports.empty(), "Airports can't be empty.");
\n ENSURE(!runways.empty(), "Runways can't be empty.");
*/
    static int parsing(vector<Airport*> &airports, vector<Airplane*> &airplanes, vector<Runway*> &runways, const char* path);

/**
\n REQUIRE(!runways.empty(), "There are no runways available.");
\n REQUIRE(!airports.empty(), "There are no airports available.");
\n ENSURE(!airports[k].getRunways().empty(), "Airport has no runway.");
*/
    static void addRunway(vector <Airport*> &airports, vector <Runway*> &runways);

    static void full_parsing(Simulation &simulation, const char* path);

};


#endif //VLIEGVELD_PARSER_H
