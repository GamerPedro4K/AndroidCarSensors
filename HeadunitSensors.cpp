#include "HeadunitSensors.hpp"

void HeadunitSensors::sendSensors(int* Sensors) {
  convertSensors(Sensors);

  byte FrontSensors[] = {Sensors[4], Sensors[5], Sensors[6], Sensors[7]};
  sendSerialData(FRONT_RADAR_INFO, FrontSensors, sizeof(FrontSensors) / sizeof(FrontSensors[0]));

  byte RearSensors[] = {Sensors[0], Sensors[1], Sensors[2], Sensors[3]};
  sendSerialData(REAR_RADAR_INFO, RearSensors, sizeof(RearSensors) / sizeof(RearSensors[0]));
}

void HeadunitSensors::convertSensorValue(int& sensorValue, const int* sensorArray, int arraySize) {
    // Convert the sensor value
    if (sensorValue >= 0 && sensorValue <= arraySize - 2) {
        sensorValue = sensorArray[sensorValue];
    } else {
        sensorValue = sensorArray[arraySize - 1];
    }
}

void HeadunitSensors::convertSensors(int* Sensors) {
    // Convert rear sensors
    // Sensor A
    convertSensorValue(Sensors[0], RearDA, RearDASize);
    // Sensor B
    convertSensorValue(Sensors[1], RearCB, RearCBSize);
    // Sensor C
    convertSensorValue(Sensors[2], RearCB, RearCBSize);
    // Sensor D
    convertSensorValue(Sensors[3], RearDA, RearDASize);

    // Convert front sensors
    // Sensor E
    convertSensorValue(Sensors[4], FrontEH, FrontEHSize);
    // Sensor F
    convertSensorValue(Sensors[5], FrontGF, FrontGFSize);
    // Sensor G
    convertSensorValue(Sensors[6], FrontGF, FrontGFSize);
    // Sensor H
    convertSensorValue(Sensors[7], FrontEH, FrontEHSize);
}


void HeadunitSensors::printSensors(int* Sensors) {
    Serial.println();
    for (int i = 0; i < 8; i++) {
        Serial.print(String("\nSensor ") + String(char('A' + i)) + String(": ") + String(Sensors[i], HEX));
    }
}

//FRONT SENSORS H - (RIGHT) E - (LEFT)
const int HeadunitSensors::FrontEH[FrontEHSize] = {
    0x00, // 0
    0x00, // 1
    0x00, // 2
    0x00, // 3
    0x06, // 4
    0x0C, // 5
    0x18, // 6
    0x1D, // 7
    0x24, // 8
    0x2A, // 9
    0x36, // 10
    0x3C  // 255
};

//FRONT SENSORS G - (CENTER RIGHT) F - (CENTER LEFT)
const int HeadunitSensors::FrontGF[FrontGFSize] = {
    0x00, // 0
    0x00, // 1
    0x00, // 2
    0x00, // 3
    0x0C, // 4
    0x18, // 5
    0x24, // 6
    0x30, // 7
    0x3C, // 8
    0x48, // 9
    0x60, // 10
    0x78 // 255
};

 //REAR SENSORS D - (RIGHT) A - (LEFT)
const int HeadunitSensors::RearDA[RearDASize] = {
    0x00, // 0
    0x00, // 1
    0x00, // 2
    0x00, // 3
    0x06, // 4
    0x06, // 5
    0x0C, // 6
    0x0C, // 7
    0x18, // 8
    0x18, // 9
    0x1E, // 10
    0x1E, // 11
    0x24, // 12
    0x2A, // 13
    0x36, // 14
    0x36, // 15
    0x3C, // 16
    0x3C, // 17
    0x3C, // 18
    0x3C, // 19
    0x3C, // 20
    0x3C, // 21
    0x3C, // 22
    0x3C, // 23
    0x3C, // 24
    0x3C, // 25
    0x3C, // 255
};

//REAR SENSORS C - (CENTER RIGHT) B - (CENTER LEFT)
const int HeadunitSensors::RearCB[RearCBSize] = {
    0x00, // 0
    0x00, // 1
    0x00, // 2
    0x00, // 3
    0x11, // 4
    0x21, // 5
    0x32, // 6
    0x42, // 7
    0x42, // 8
    0x53, // 9
    0x53, // 10
    0x63, // 11
    0x63, // 12
    0x74, // 13
    0x84, // 14
    0x95, // 15
    0xA5, // 16
    0xA5, // 17
    0xA5, // 18
    0xA5, // 19
    0xA5, // 20
    0xA5, // 21
    0xA5, // 22
    0xA5, // 23
    0xA5, // 24
    0xA5, // 25
    0xA5  // 255
};