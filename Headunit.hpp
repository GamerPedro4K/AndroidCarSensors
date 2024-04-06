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
    protected:
        void sendSerialData(int typeByte, byte *dataBytes, int dataSize);
 
};

#endif