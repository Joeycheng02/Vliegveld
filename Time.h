//
// Created by nightnarumi on 18/06/18.
//

#ifndef VLIEGVELD_TIME_H
#define VLIEGVELD_TIME_H

#include <string>
#include <sstream>
using namespace std;

class Time {
private:
    int t;
    Time* _initCheck;
public:
    Time();

/**
\n REQUIRE(properlyInitialized(), "This Time object is not properly initialized");
\n REQUIRE(Simulation::time >= 0, "The variable is not properly initialized");
\n REQUIRE(minute >= 0, "The given variable is not properly initialized");
\n ENSURE(Simulation::time < 1440, "The variable exceeds the allowed time");
\n ENSURE(Simulation::getTime() >= 0, "The variable can't be a negative number");
*/
    void addTime(int time);

/**
\n REQUIRE(properlyInitialized(), "This Time object is not properly initialized");
*/
    string printTime();

/**
\n REQUIRE(properlyInitialized(), "This Time object is not properly initialized");
*/
    const bool properlyInitialized() const;

};


#endif //VLIEGVELD_TIME_H
