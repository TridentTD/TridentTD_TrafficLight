#include <TridentTD_TrafficLight.h>

void TrafficLights_func(void*){
  #define GREEN_INTERVAL        9000    // ms   ระยะเวลา ขณะไฟเขียวทำงาน
  #define YELLOW_INTERVAL       1000    // ms   ระยะเวลา ขณะเปลี่ยนเป็นไฟเหลือง
  #define EMERGENCY_INTERVAL    12000   // ms   ระยะเวลา ที่ ปล่อยไฟเขียวทำงานฉุกเฉิน
  
  TridentTD_TrafficLight traffic1( 14,15,18); // กำหนดขา pin ของ green, yellow, red ของไฟจราจรชุดแรก
  TridentTD_TrafficLight traffic2( 19,21,22);
  TridentTD_TrafficLight traffic3( 25,26,27);
  TridentTD_TrafficLight traffic4( 32,33,16);

  VOID SETUP(){  traffic1.begin(); traffic2.begin(); traffic3.begin(); traffic4.begin();  }
  
  VOID LOOP(){
    switch(xTrafficStatus) {
      case 1:
        traffic1.Green();   traffic2.Red();     traffic3.Red();     traffic4.Red();   // traffic1 ไฟเขียว นอกนั้นแดง
        DELAY( xNormal? GREEN_INTERVAL : EMERGENCY_INTERVAL );
        traffic1.Yellow();  traffic2.Yellow();  traffic3.Red();     traffic4.Red();   // ไฟเหลือง
        DELAY(YELLOW_INTERVAL);
        xTrafficStatus = 2; xNormal = true;
        break;
      case 2:
        traffic1.Red();     traffic2.Green();   traffic3.Red();     traffic4.Red();   // traffic2 ไฟเขียว นอกนั้นแดง
        DELAY( xNormal? GREEN_INTERVAL : EMERGENCY_INTERVAL );
        traffic1.Red();     traffic2.Yellow();  traffic3.Yellow();  traffic4.Red();   // ไฟเหลือง
        DELAY(YELLOW_INTERVAL);
        xTrafficStatus = 3; xNormal = true;
        break;
      case 3:
        traffic1.Red();     traffic2.Red();     traffic3.Green();   traffic4.Red();   // traffic3 ไฟเขียว นอกนั้นแดง
        DELAY( xNormal? GREEN_INTERVAL : EMERGENCY_INTERVAL );
        traffic1.Red();     traffic2.Red();     traffic3.Yellow();  traffic4.Yellow();// ไฟเหลือง
        DELAY(YELLOW_INTERVAL);
        xTrafficStatus = 4; xNormal = true;
        break;
      case 4:
        traffic1.Red();     traffic2.Red();     traffic3.Red();     traffic4.Green(); // traffic4 ไฟเขียว นอกนั้นแดง
        DELAY( xNormal? GREEN_INTERVAL : EMERGENCY_INTERVAL );
        traffic1.Yellow();  traffic2.Red();     traffic3.Red();     traffic4.Yellow();// ไฟเหลือง
        DELAY(YELLOW_INTERVAL);
        xTrafficStatus = 1; xNormal = true;
        break;
      case 0:
        traffic1.turnoff(); traffic2.turnoff(); traffic3.turnoff(); traffic4.turnoff();
        break;
    } // end switch
  } // end LOOP()
} // end Task function

