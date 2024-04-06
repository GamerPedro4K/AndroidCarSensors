#include "Sensors.hpp"

Sensors::Sensors(
    int pulsePin, 
    int frameStartMin, 
    int frameStartMax, 
    int oneMin, 
    int oneMax, 
    int zeroMin, 
    int zeroMax, 
    bool DEBUG) : 
    pulsePin(pulsePin), 
    frameStartMin(frameStartMin), 
    frameStartMax(frameStartMax), 
    oneMin(oneMin), 
    oneMax(oneMax), 
    zeroMin(zeroMin), 
    zeroMax(zeroMax), 
    DEBUG(DEBUG){
    pinMode(pulsePin, INPUT);
}

Sensors::Sensors(bool DEBUG) : DEBUG(DEBUG){
    pinMode(pulsePin, INPUT);
}

int* Sensors::getSensorData() {
    String packet = readPacket();
    if (packet == ""){
      Sensores[0] = -1;
      delay(300);
      return Sensores;
    }

    int y = 0;
    for (int x = 0; x < 8; x++) {
        String distanceStringByte;
        for (; y < 8 * (x + 1); y++) {
            distanceStringByte += String(packet[y]);
        }
        Sensores[x] = strtol(distanceStringByte.c_str(), NULL, 2);
    }

    orderSensors();

    if (DEBUG) {
        Serial.print("\nPacket: " + packet);
        printSensors();
    }

    return Sensores;
}

void Sensors::printSensors() {
    for (int x = 0; x < 8; x++) {
        Serial.print("\nSensor ");
        Serial.print(char('A' + x));
        Serial.print(": ");
        Serial.print(Sensores[x]);
    }
    Serial.print("\n");
}

void Sensors::orderSensors() {
    //Sensor A[0]: 255 A
    //Sensor B[1]: 255 D x
    //Sensor C[2]: 255 C 
    //Sensor D[3]: 255 B x
    //Sensor E[4]: 255 E
    //Sensor F[5]: 255 H y
    //Sensor G[6]: 255 G
    //Sensor H[7]: 255 F y

    //exchange B WITH D
    int saveB = Sensores[1];
    Sensores[1] = Sensores[3];
    Sensores[3] = saveB;

    //exchange F WITH H
    int saveF= Sensores[5];
    Sensores[5] = Sensores[7];
    Sensores[7] = saveF;
}

String Sensors::readPacket() {
    unsigned long pulseWidth;
    int attempts = 0;
    const int maxAttempts = 65;

    // Wait for the start of frame
    do {
        pulseWidth = pulseIn(pulsePin, HIGH);
        if (attempts >= maxAttempts) {
            if (1/* DEBUG */) {
                Serial.println("Max attempts reached. Unable to detect start of frame.");
            }
            return "";
        }
        attempts++;
    } while (!(pulseWidth >= frameStartMin && pulseWidth <= frameStartMax));

    if (DEBUG) {
        Serial.print("\n\nStart of frame detected: ");
        Serial.println(pulseWidth);
    }

    String packet = "";

    // Read the packet
    while (true) {
        pulseWidth = pulseIn(pulsePin, HIGH);

        if (pulseWidth >= frameStartMin && pulseWidth <= frameStartMax) {
            // End of packet
            if (DEBUG) {
                Serial.println("End of packet detected.");
            }
            break;
        }

        if (pulseWidth >= oneMin && pulseWidth <= oneMax) {
            packet += '1';
        } else if (pulseWidth >= zeroMin && pulseWidth <= zeroMax) {
            packet += '0';
        }
    }

    if (DEBUG) {
        Serial.print("Received packet: ");
        Serial.println(packet);
    }

    return packet.substring(1);
}


