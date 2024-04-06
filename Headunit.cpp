#include "Headunit.hpp"

void HeadUnit::sendSerialData(int typeByte, byte *dataBytes, int dataSize) {
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
}
