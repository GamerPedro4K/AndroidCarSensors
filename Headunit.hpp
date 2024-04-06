#ifndef HEADUNIT_H
#define HEADUNIT_H

#include <Arduino.h>

#define BACKLIGHT_INFO 0x14
#define VEHICLE_SPEED_INFO 0x16
#define STEERING_WHEEL_KEY 0x20
#define AIR_CONDITIONING_INFO 0x21
#define REAR_RADAR_INFO 0x22
#define FRONT_RADAR_INFO 0x23
#define BASE_INFO 0x24
#define PARKING_STATUS_INFO 0x25
#define VEHICLE_TIME_INFO 0x26
#define ENV_TEMP 0x27
#define STEERING_WHEEL_ANGLE 0x29
#define STEERING_WHEEL_CMD 0x2F
#define PROTOCOL_VERSION_INFO 0x30
#define LEFT_RADAR 0x32
#define RIGHT_RADAR 0x33
#define VEHICLE_STAUS 0x40
#define HU_ENABLE 0x41
#define DRIVING_DATA 0x50
#define PROMPT_INFO 0x60
#define CONV_CONSUME 0x62
#define SERVICE_INFO 0x63
#define TPMS_INFO 0x65

class HeadUnit {
    public:
        void sendSerialData(int typeByte, byte *dataBytes, int dataSize);
    /* private:
        void sendSerialData(int typeByte, byte *dataBytes, int dataSize); */
};

#endif


/* void setup() {
  Serial.begin(38400);
}

void loop() {
  if (Serial.available() > 0) {
    char incomingByte = Serial.read();

    if (incomingByte == 0x2E) {
      Serial.println("");
      if (incomingByte < 0x10) {
        Serial.print("0");
      }
      Serial.print((unsigned char)incomingByte, HEX);
      Serial.print(" ");
    } 
    else {
      if (incomingByte < 0x10) {
        Serial.print("0");
      }
      Serial.print((unsigned char)incomingByte, HEX);
      Serial.print(" ");
    }
  }
}
 */

/* #define BACKLIGHT_INFO 0x14
#define VEHICLE_SPEED_INFO 0x16
#define STEERING_WHEEL_KEY 0x20
#define AIR_CONDITIONING_INFO 0x21
#define REAR_RADAR_INFO 0x22
#define FRONT_RADAR_INFO 0x23
#define BASE_INFO 0x24
#define PARKING_STATUS_INFO 0x25
#define VEHICLE_TIME_INFO 0x26
#define ENV_TEMP 0x27
#define STEERING_WHEEL_ANGLE 0x29
#define STEERING_WHEEL_CMD 0x2F
#define PROTOCOL_VERSION_INFO 0x30
#define LEFT_RADAR 0x32
#define RIGHT_RADAR 0x33
#define VEHICLE_STAUS 0x40
#define HU_ENABLE 0x41
#define DRIVING_DATA 0x50
#define PROMPT_INFO 0x60
#define CONV_CONSUME 0x62
#define SERVICE_INFO 0x63
#define TPMS_INFO 0x65


void setup() {
  Serial.begin(38400);
}

void loop() {
  byte dataBytes[] = {0x08, 0x10, 0x18, 0x20};
  sendSerialData(FRONT_RADAR_INFO, dataBytes, sizeof(dataBytes) / sizeof(dataBytes[0]));
  delay(1000);

  byte dataBytesA[] = {0x20, 0x18, 0x10, 0x08};
  sendSerialData(REAR_RADAR_INFO, dataBytesA, sizeof(dataBytesA) / sizeof(dataBytesA[0]));
  delay(1000);
  

  byte dataBytesX[] = {0x01, 0x18};
  sendSerialData(STEERING_WHEEL_ANGLE, dataBytesX, sizeof(dataBytesX) / sizeof(dataBytesX[0]));
  delay(1000);

  byte dataBytesY[] = {0x02, 0x88};
  sendSerialData(STEERING_WHEEL_ANGLE, dataBytesY, sizeof(dataBytesY) / sizeof(dataBytesY[0]));
  delay(1000);

  byte dataBytesYy[] = {0xff, 0xff};
  sendSerialData(BASE_INFO, dataBytesYy, sizeof(dataBytesYy) / sizeof(dataBytesYy[0]));
  delay(1000);

  byte dataBytesYyy[] = {0xFF,0xFF};
  sendSerialData(PARKING_STATUS_INFO, dataBytesYyy, sizeof(dataBytesYyy) / sizeof(dataBytesYyy[0]));
  delay(1000);

  byte dataBytesD[] = {0x0F, 0xff}; // Data bytes representing the temperature of 20º
  sendSerialData(ENV_TEMP, dataBytesD, sizeof(dataBytesD) / sizeof(dataBytesD[0]));
delay(1000);

 byte dataBytesdD[] = {0xff, 0xff,0xff,0xff,0xff,0xff,0xff,0xff}; // Data bytes representing the temperature of 20º
  sendSerialData(PROMPT_INFO, dataBytesdD, sizeof(dataBytesdD) / sizeof(dataBytesdD[0]));


byte dataBytesdDfx[] = {0x01, 0x05,0x5f,0xff}; // Data bytes representing the temperature of 20º
  sendSerialData(TPMS_INFO, dataBytesdDfx, sizeof(dataBytesdDfx) / sizeof(dataBytesdDfx[0]));
}


void sendSerialData(int typeByte, byte *dataBytes, int dataSize) {
  byte startByte = 0x2E; // Start byte
  byte lengthByte = dataSize; // Length byte
  
  // Calculate checksum
  int checksum = typeByte + lengthByte;
  for (int i = 0; i < dataSize; i++) {
    checksum += dataBytes[i];
  }
  checksum = (checksum & 0xFF) ^ 0xFF; // Perform the final XOR operation
  
  // Send data packet via serial
  Serial.write(startByte);
  Serial.write(typeByte);
  Serial.write(lengthByte);
  for (int i = 0; i < dataSize; i++) {
    Serial.write(dataBytes[i]);
  }
  Serial.write(checksum);
} */