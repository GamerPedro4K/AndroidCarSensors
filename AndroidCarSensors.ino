#include "Sensors.hpp"
#include "HeadunitSensors.hpp"

HeadunitSensors headUnit;
Sensors mySensors;

void setup() {
    Serial.begin(38400);
    mySensors = Sensors();
}

void loop() {
    //Get Sensor Data
    int* sensorData = mySensors.getSensorData();
    if(sensorData[0] != -1)
      headUnit.sendSensors(sensorData);
}
