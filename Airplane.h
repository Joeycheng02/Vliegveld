//
// Created by matth on 15/03/2018.
//

#ifndef VLIEGVELD_AIRPLANE_H
#define VLIEGVELD_AIRPLANE_H

#include <iostream>
#include <string>
#include "Airport.h"

using namespace std;

class Airplane {
private:
    string number;
    string callsign;
    string model;
    string status;
    string airport;
    int passengers;
    int gateNumber;
    int height;
    
public:
    const string &getAirport() const;

    void setAirport(const string &airport);
    
public:
    Airplane();
    
    int getHeight() const;

    int getPassengers() const;

    void setPassengers(int passengers);

    void setHeight(int height);

    int getGateNumber() const;

    void setGateNumber(int gateNumber);

    const string &getNumber() const;

    void setNumber(const string &number);

    const string &getCallsign() const;

    void setCallsign(const string &callsign);

    const string &getModel() const;

    void setModel(const string &model);

    const string &getStatus() const;

    void setStatus(const string &status);
};


#endif //VLIEGVELD_AIRPLANE_H
