#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

class Sensors {
public:
    Sensors(int pulsePin = 2, int frameStartMin = 1750, int frameStartMax = 1900,
            int oneMin = 180, int oneMax = 220, int zeroMin = 85, int zeroMax = 125,
            bool DEBUG = false);

    Sensors(bool DEBUG);

    int* getSensorData();
    void printSensors();

private:
    int pulsePin;
    int frameStartMin = 1750;
    int frameStartMax = 1900;
    int oneMin = 180;
    int oneMax = 220;
    int zeroMin = 85;
    int zeroMax = 125;
    bool DEBUG = true;
    int Sensores[8];

    String readPacket();

    void orderSensors();
};

#endif // SENSORS_H
