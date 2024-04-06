#include "Sensors.hpp"
#include "Headunit.hpp"

HeadUnit headUnit;

Sensors mySensors;

void setup() {
    Serial.begin(38400);
    mySensors = Sensors(true);
}




void loop() {
    // Get sensor data
    int* sensorData = mySensors.getSensorData();

    for (int i = 0x3C ; i <= 0xff; i) { // Assuming 'infanty' refers to 0xff
      byte dataByte[] = {i, i, i, i};
      headUnit.sendSerialData(FRONT_RADAR_INFO, dataByte, sizeof(dataByte) / sizeof(dataByte[0]));

      byte dataBytes[] = {i, i, i, i};
      headUnit.sendSerialData(REAR_RADAR_INFO, dataBytes, sizeof(dataBytes) / sizeof(dataBytes[0]));
      Serial.println("\n\nData sent");

 byte dataBytess[] = {i, i, i, i};
      headUnit.sendSerialData(0x32, dataBytess, sizeof(dataBytess) / sizeof(dataBytess[0]));
      Serial.println("\n\nData sent");

       byte dataByteas[] = {i, i, i, i};
      headUnit.sendSerialData(0x33, dataByteas, sizeof(dataByteas) / sizeof(dataBytes[0]));
      Serial.println("\n\nData sent");

      Serial.println(i,HEX);
      delay(2000); // Delay for 2 seconds
    }

   /*  byte dataBytes[] = {0x20, 0x00, 0x00, 0x1E};
  headUnit.sendSerialData(FRONT_RADAR_INFO, dataBytes, sizeof(dataBytes) / sizeof(dataBytes[0]));
  byte dataBytesA[] = {0x00, 0x00, 0x00, 0x00};
  headUnit.sendSerialData(REAR_RADAR_INFO, dataBytesA, sizeof(dataBytesA) / sizeof(dataBytesA[0]));


  delay(500000);

  byte dataBytesyy[] = {0x2E, 0x1F, 0x10, 0x00};
  headUnit.sendSerialData(FRONT_RADAR_INFO, dataBytesyy, sizeof(dataBytesyy) / sizeof(dataBytesyy[0]));
  byte dataBytesAx[] = {0x3D, 0x4C, 0x5B, 0x6A};
  headUnit.sendSerialData(REAR_RADAR_INFO, dataBytesAx, sizeof(dataBytesAx) / sizeof(dataBytesAx[0])); */
  

  /* byte dataBytesX[] = {0x01, 0x18};
  headUnit.sendSerialData(STEERING_WHEEL_ANGLE, dataBytesX, sizeof(dataBytesX) / sizeof(dataBytesX[0]));
  delay(1000);

  byte dataBytesY[] = {0x02, 0x88};
  headUnit.sendSerialData(STEERING_WHEEL_ANGLE, dataBytesY, sizeof(dataBytesY) / sizeof(dataBytesY[0]));
  delay(1000);

  byte dataBytesYy[] = {0xff, 0xff};
  headUnit.sendSerialData(BASE_INFO, dataBytesYy, sizeof(dataBytesYy) / sizeof(dataBytesYy[0]));
  delay(1000);

  byte dataBytesYyy[] = {0xFF,0xFF};
  headUnit.sendSerialData(PARKING_STATUS_INFO, dataBytesYyy, sizeof(dataBytesYyy) / sizeof(dataBytesYyy[0]));
  delay(1000);

  byte dataBytesD[] = {0x0F, 0xff}; // Data bytes representing the temperature of 20º
  headUnit.sendSerialData(ENV_TEMP, dataBytesD, sizeof(dataBytesD) / sizeof(dataBytesD[0]));
  delay(1000);

 byte dataBytesdD[] = {0xff, 0xff,0xff,0xff,0xff,0xff,0xff,0xff}; // Data bytes representing the temperature of 20º
  headUnit.sendSerialData(PROMPT_INFO, dataBytesdD, sizeof(dataBytesdD) / sizeof(dataBytesdD[0]));


  byte dataBytesdDfx[] = {0x01, 0x05,0x5f,0xff}; // Data bytes representing the temperature of 20º
  headUnit.sendSerialData(TPMS_INFO, dataBytesdDfx, sizeof(dataBytesdDfx) / sizeof(dataBytesdDfx[0])); */

    
}
