//
// Created by nightnarumi on 02/05/18.
//

#ifndef VLIEGVELD_OUTPUT_H
#define VLIEGVELD_OUTPUT_H


#include "Airport.h"
#include "Airplane.h"

class output {
public:
    //REQUIRE airports and airplanes cant be empty.
    int outputfile (vector <Airport> &airports, vector <Airplane> &airplanes);
};


#endif //VLIEGVELD_OUTPUT_H
