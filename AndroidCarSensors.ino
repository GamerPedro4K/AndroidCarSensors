#include "Sensors.hpp"
#include "Headunit.hpp"
#include "HeadunitSensors.hpp"

HeadunitSensors headUnit;

Sensors mySensors;

void setup() {
    Serial.begin(38400);
    mySensors = Sensors(true);

}




void loop() {
    // Get sensor data
    int* sensorData = mySensors.getSensorData();
    headUnit.sendSensors(sensorData);

    
}
