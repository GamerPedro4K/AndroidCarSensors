#ifndef DISTANCE_CONVERTER_HPP
#define DISTANCE_CONVERTER_HPP
#include "Headunit.hpp"

class HeadunitSensors : private HeadUnit{
  public:
    HeadunitSensors();
    int convertDistanceToHex(float distance);
      
  private:

    //FRONT SENSORS H - (RIGHT) E - (LEFT)
    const int FrontEH[9] = {
      0x00, // 0 - 3
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
  const int FrontGF[11] = {
    0x00, // 0-3
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
  const int RearDA[24] = {
    0x00, // 0 - 3
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
  const int RearCB[24] = {
    0x00, // 0 - 3
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