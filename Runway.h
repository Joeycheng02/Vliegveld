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
    unsigned int length;
    bool vacant;
    vector<string> taxipoints;
    vector<string> crossings;

public:

    Runway();

    const string &getName() const;

/**
\n REQUIRE(Runway::name != name, "The variable already has this value");
\n ENSURE(getName() == name, "The variable is not set correctly");
*/
    void setName(const string &name);

    const string &getAirport() const;

/**
\n REQUIRE(Runway::airport != airport, "The variable already has this value");
\n ENSURE(getAirport() == airport, "The variable is not set correctly");
*/
    void setAirport(const string &airport);

    bool isVacant() const;

/**
\n REQUIRE(Runway::isVacant() or !Runway::isVacant(), "The variable is not properly initialized");
\n ENSURE(isVacant() == vacant, "The variable is not set correctly");
*/
    void setVacant(bool vacant);

    const string &getType() const;

/**
\n REQUIRE(Runway::type != type, "The variable already has this value");
\n ENSURE(getType() == type, "The variable is not set correctly");
*/
    void setType(const string &type);

    const unsigned int &getLength() const;

/**
\n REQUIRE(Runway::length >= 0, "The variable is not properly initialized");
\n ENSURE(getLength() == length, "The variable is not set correctly");
\n ENSURE(getLength() >= 0, "The variable can't be a negative number");
*/
    void setLength(const unsigned int &length);

/**
\n ENSURE(get_Taxipoint()[get_Taxipoint().size() - 1]== taxipoint, "The variable is not set correctly");
*/
    void add_Taxipoint(string crossing);

    vector<string> get_Taxipoint();

/**
\n ENSURE(get_Taxipoint()[get_Taxipoint().size() - 1]== crossing, "The variable is not set correctly");
*/
    void add_Crossing(string taxipoint);

    vector<string> get_Crossing();
};


#endif //VLIEGVELD_RUNWAY_H
