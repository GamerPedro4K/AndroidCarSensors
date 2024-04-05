#include "Sensors.hpp"

Sensors mySensors;

void setup() {
    Serial.begin(9600);
    mySensors = Sensors(2, 1700, 1950, 160, 240, 70, 140, true);
}

void loop() {
    // Get sensor data
    int* sensorData = mySensors.getSensorData();

    
}
