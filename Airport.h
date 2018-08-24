//
// Created by matth on 15/03/2018.
//

#ifndef VLIEGVELD_AIRPORT_H
#define VLIEGVELD_AIRPORT_H

#include <iostream>
#include <string>
#include "Runway.h"
#include <vector>

using namespace std;

class Airport {

private:
    string name;
    string iata;
    string callsign;
    int numberOfGates;
    vector <bool> gates;
    vector <Runway*> runways;
    bool heightCheck3000;
    bool heightCheck5000;
    Airport* _initCheck;
public:

    Airport();

    vector<bool> &getGates();

    vector<Runway*> &getRunways();

/**
\n REQUIRE(properlyInitialized(), "This Airport object is not properly initialized");
\n ENSURE(getRunways()[getRunways().size() - 1].isVacant() == runway.isVacant(), "The variable is not set correctly");
*/
    void addRunways(Runway* runway);

/**
\n REQUIRE(properlyInitialized(), "This Airport object is not properly initialized");
*/
    unsigned int getNumberOfRunways() const;

/**
\n REQUIRE(properlyInitialized(), "This Airport object is not properly initialized");
*/
    int getNumberOfGates() const;

/**
\n REQUIRE(properlyInitialized(), "This Airport object is not properly initialized");
\n REQUIRE(Airport::numberOfGates >= 0, "The variable is not properly initialized");
\n ENSURE(getNumberOfGates() == numberOfGates, "The variable is not set correctly");
\n ENSURE(getNumberOfGates() >= 0, "The variable can't be a negative number");
*/
    void setNumberOfGates(int numberOfGates);

/**
\n REQUIRE(properlyInitialized(), "This Airport object is not properly initialized");
*/
    const string &getName() const;

/**
\n REQUIRE(properlyInitialized(), "This Airport object is not properly initialized");
\n REQUIRE(Airport::name != name, "The variable already has this value");
\n ENSURE(getName() == name, "The variable is not set correctly");
*/
    void setName(const string &name);

/**
\n REQUIRE(properlyInitialized(), "This Airport object is not properly initialized");
*/
    const string &getIata() const;

/**
\n REQUIRE(properlyInitialized(), "This Airport object is not properly initialized");
\n REQUIRE(Airport::iata != iata, "The variable already has this value");
\n ENSURE(getIata() == iata, "The variable is not set correctly");
 */
    void setIata(const string &iata);

/**
\n REQUIRE(properlyInitialized(), "This Airport object is not properly initialized");
*/
    const string &getCallsign() const;

/**
\n REQUIRE(properlyInitialized(), "This Airport object is not properly initialized");
\n REQUIRE(Airport::callsign != callsign, "The variable already has this value");
\n ENSURE(getCallsign() == callsign, "The variable is not set correctly");
*/
    void setCallsign(const string &callsign);

/**
\n REQUIRE(properlyInitialized(), "This Airport object is not properly initialized");
*/
    bool isHeightCheck3000() const;

/**
\n REQUIRE(properlyInitialized(), "This Airport object is not properly initialized");
\n REQUIRE(Airport::heightCheck3000 or !Airport::heightCheck3000, "The variable is not properly initialized");
\n ENSURE(isHeightCheck3000() == heightCheck3000, "The variable is not set correctly");
*/
    void setHeightCheck3000(bool heightCheck3000);

/**
\n REQUIRE(properlyInitialized(), "This Airport object is not properly initialized");
*/
    bool isHeightCheck5000() const;

/**
\n REQUIRE(properlyInitialized(), "This Airport object is not properly initialized");
\n REQUIRE(Airport::heightCheck5000 or !Airport::heightCheck5000, "The variable is not properly initialized");
\n ENSURE(isHeightCheck3000() == heightCheck3000, "The variable is not set correctly");
*/
    void setHeightCheck5000(bool heightCheck5000);

/**
\n REQUIRE(properlyInitialized(), "This Airport object is not properly initialized");
\n REQUIRE(height >= 0, "The variable can't be a negative number");
\n ENSURE(isHeightCheck5000(), "The variable is not set correctly");
\n ENSURE(!isHeightCheck5000(), "The variable is not set correctly");
\n ENSURE(isHeightCheck3000(), "The variable is not set correctly");
\n ENSURE(!isHeightCheck3000(), "The variable is not set correctly");
\n ENSURE(height != 10000 and height != 5000 and height != 3000, "The function did not correctly end");
*/
    bool permissionToDescend (int height);

/**
\n REQUIRE(properlyInitialized(), "This Airport object is not properly initialized");
\n REQUIRE(number >= -1, "The value can't be less than -1");
*/
    bool permissionToAscend (int number);

    const bool properlyInitialized() const;

};


#endif //VLIEGVELD_AIRPORT_H