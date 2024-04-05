#include "Sensors.hpp"

Sensors mySensors;

void setup() {
    Serial.begin(9600);
    mySensors = Sensors();
}

void loop() {
    // Get sensor data
    int* sensorData = mySensors.getSensorData();

    
}
