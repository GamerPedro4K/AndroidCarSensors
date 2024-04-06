#ifndef DISTANCE_CONVERTER_HPP
#define DISTANCE_CONVERTER_HPP
#include "Headunit.hpp"

class HeadunitSensors : public HeadUnit{
  public:
    
    void sendSensors(int* Sensors);
    void printSensors(int* Sensors);
      
  private:
    void convertSensors(int* Sensors);
    void convertSensorValue(int& sensorValue, const int* sensorArray, int arraySize);

    //FRONT SENSORS H - (RIGHT) E - (LEFT)
    static const int FrontEHSize = 12;
    static const int FrontEH[FrontEHSize];

  //FRONT SENSORS G - (CENTER RIGHT) F - (CENTER LEFT)
  static const int FrontGFSize = 12;
  static const int FrontGF[FrontGFSize];

  //REAR SENSORS D - (RIGHT) A - (LEFT)
  static const int RearDASize = 27;
  static const int RearDA[RearDASize];

  //REAR SENSORS C - (CENTER RIGHT) B - (CENTER LEFT)
  static const int RearCBSize = 27;
  static const int RearCB[RearCBSize];
     
};

#endif // DISTANCE_CONVERTER_HPP


/* 
?FRONT

8  - H 0.3m~1.0 m
10 - G 0.3m~1.0 m
10 - F 0.3m~1.0 m
8  - E 0.3m~1.0 m

!FRONT H,E
Bars Hex
8 - 0x00
7 - 0x06
6 - 0x0C
5 - 0x18
4 - 0x1D
3 - 0x24
2 - 0x2A
1 - 0x36
0 - 0x3C

!FRONT G,F
Bars Hex
10 - 0x00
9  - 0x0C
8  - 0x18
7  - 0x24
6  - 0x30
5  - 0x3C
4  - 0x48
3  - 0x54
2  - 0x60
1  - 0x6C
0  - 0x78


?REAR
8  - D 0.3m~2.5 m
10 - C 0.3m~2.5 m
10 - B 0.3m~2.5 m
8  - A 0.3m~2.5 m

!REAR C, B
Bars Hex
10 - 0x00
9  - 0x11
8  - 0x21
7  - 0x32
6  - 0x42
5  - 0x53
4  - 0x63
3  - 0x74
2  - 0x84
1  - 0x95
0  - 0xA5

!REAR D,A
Bars Hex
8 - 0x00
7 - 0x06
6 - 0x0C
5 - 0x18
4 - 0x1E
3 - 0x24
2 - 0x2A
1 - 0x36
0 - 0x3C
 */