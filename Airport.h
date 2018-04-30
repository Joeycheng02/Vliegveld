//
// Created by matth on 15/03/2018.
//

#ifndef VLIEGVELD_AIRPORT_H
#define VLIEGVELD_AIRPORT_H

#include <iostream>
#include <string>
#include "Runway.h"
#include "Gate.h"
#include <vector>

using namespace std;

class Airport {
public:
    vector<Gate> &getGates();

    vector<Runway> &getRunways();

private:
    string name;
    string iata;
    string callsign;
    int numberOfGates;
    vector <Gate> gates;
    vector <Runway> runways;
public:
    void addRunways(Runway runway);

    int getNumberOfRunways() const;

    int getNumberOfGates() const;

    void setNumberOfGates(int numberOfGates);

    const string &getName() const;

    void setName(const string &name);

    const string &getIata() const;

    void setIata(const string &iata);

    const string &getCallsign() const;

    void setCallsign(const string &callsign);
};


#endif //VLIEGVELD_AIRPORT_H
