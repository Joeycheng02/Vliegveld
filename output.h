//
// Created by nightnarumi on 02/05/18.
//

#ifndef VLIEGVELD_OUTPUT_H
#define VLIEGVELD_OUTPUT_H


#include "Airport.h"
#include "Airplane.h"

class output {
public:
/**
\n REQUIRE(airplanes.size() != 0, "There are no airplanes available");
\n REQUIRE(airports.size() != 0, "There are no airports available");
*/
    static int outputfile (vector <Airport> &airports, vector <Airplane> &airplanes);

    static int landing(Airplane &airplane, Airport &airport, Runway &runway, int check);

    static int ascending(Airplane &airplane, Airport &airport, Runway &runway, int check);

    static bool compare_file(string file1, string file2);
};

#endif //VLIEGVELD_OUTPUT_H
