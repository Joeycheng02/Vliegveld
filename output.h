//
// Created by nightnarumi on 02/05/18.
//

#ifndef VLIEGVELD_OUTPUT_H
#define VLIEGVELD_OUTPUT_H


#include "Airport.h"
#include "Airplane.h"
#include "Time.h"

class output {
public:
/**
\n REQUIRE(airplanes.size() != 0, "There are no airplanes available");
\n REQUIRE(airports.size() != 0, "There are no airports available");
*/
    static int outputfile (vector <Airport*> &airports, vector <Airplane*> &airplanes);

/**
\n REQUIRE(!compare_file("output.txt", "empty.txt"), "The output.txt can't be empty before requesting a landing");
\n ENSURE(!compare_file("output.txt", "empty.txt"), "The output.txt can't be empty after landing");
 */
    static int landing(Airplane &airplane, Airport &airport, Runway &runway, int check, Time &time);

/**
\n REQUIRE(!compare_file("output.txt", "empty.txt"), "The output.txt can't be empty before requesting to ascend");
\n ENSURE(!compare_file("output.txt", "empty.txt"), "The output.txt can't be empty after ascending");
 */
    static int ascending(Airplane &airplane, Airport &airport, Runway &runway, int check, Time &time);

    static int taxien(Airplane &airplane, Airport &airport, Runway &runway, int check, Time &time, const string &taxipoint, int gatenumber);

    static bool compare_file(string file1, string file2);
};

#endif //VLIEGVELD_OUTPUT_H
