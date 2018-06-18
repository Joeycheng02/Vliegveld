//
// Created by nightnarumi on 18/06/18.
//

#include "Time.h"
#include "DesignByContract.h"

Time::Time() {
    Time::time = unsigned (720);
}

unsigned int Time::getTime() {
    unsigned int hours = time % 60;
    unsigned int minutes = time - hours;
    return hours * 10000 + minutes * 100;
}

void Time::addTime(unsigned int minute) {
    REQUIRE(Time::time >= 0, "The variable is not properly initialized");
    REQUIRE(minute >= 0, "The given variable is not properly initialized");
    Time::time += minute;
    Time::time = Time::time % 1440;
    ENSURE(Time::time < 1440, "The variable exceeds the allowed time");
    ENSURE(Time::getTime() >= 0, "The variable can't be a negative number");
}