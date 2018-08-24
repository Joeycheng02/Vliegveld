//
// Created by matth on 15/03/2018.
//

#ifndef VLIEGVELD_RUNWAY_H
#define VLIEGVELD_RUNWAY_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Runway {
private:
    string name;
    string airport;
    string type;
    int length;
    bool vacant;
    vector<string> taxipoints;
    vector<string> crossings_string;
    vector<Runway*> crossings;
    Runway* _initCheck;

public:

    Runway();

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
*/
    const string &getName() const;

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
\n REQUIRE(Runway::name != name, "The variable already has this value");
\n ENSURE(getName() == name, "The variable is not set correctly");
*/
    void setName(const string &name);

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
*/
    const string &getAirport() const;

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
\n REQUIRE(Runway::airport != airport, "The variable already has this value");
\n ENSURE(getAirport() == airport, "The variable is not set correctly");
*/
    void setAirport(const string &airport);

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
*/
    bool isVacant() const;

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
\n REQUIRE(Runway::isVacant() or !Runway::isVacant(), "The variable is not properly initialized");
\n ENSURE(isVacant() == vacant, "The variable is not set correctly");
*/
    void setVacant(bool vacant);

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
*/
    const string &getType() const;

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
\n REQUIRE(Runway::type != type, "The variable already has this value");
\n REQUIRE(type == "grass" or type == "asphalt", "This is not a valuable value");
\n ENSURE(getType() == type, "The variable is not set correctly");
*/
    void setType(const string &type);

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
*/
    const int &getLength() const;

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
\n REQUIRE(Runway::length >= 0, "The variable is not properly initialized");
\n ENSURE(getLength() == length, "The variable is not set correctly");
\n ENSURE(getLength() >= 0, "The variable can't be a negative number");
*/
    void setLength(const int &length);

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
\n ENSURE(getTaxipoint()[getTaxipoint().size() - 1]== taxipoint, "The variable is not set correctly");
*/
    void addTaxipoint(string crossing);

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
*/
    vector<string> getTaxipoint();

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
\n ENSURE(getCrossing()[getCrossing.size() - 1]== crossing, "The variable is not set correctly");
*/
    void addCrossing(Runway* crossing);

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
*/
    vector<Runway*> getCrossing();

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
*/
    const vector<string> &getCrossings_string() const;

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
\n ENSURE(getCrossings_string()[getCrossings_string().size() - 1]== crossings_string, "The variable is not set correctly");
*/    
    void addCrossings_string(string &crossings_string);

/**
\n REQUIRE(properlyInitialized(), "This Runway object is not properly initialized");
*/
    const bool properlyInitialized() const;
    
};


#endif //VLIEGVELD_RUNWAY_H
