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
    bool heightCheck3000;
public:
    bool isHeightCheck3000() const;

    void setHeightCheck3000(bool heightCheck3000);

    bool isHeightCheck5000() const;

    void setHeightCheck5000(bool heightCheck5000);

private:
    bool heightCheck5000;
public:
    Airport();

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

    bool permissionToDescend (int height);

    bool permissionToAscend (int number);
};


#endif //VLIEGVELD_AIRPORT_H
