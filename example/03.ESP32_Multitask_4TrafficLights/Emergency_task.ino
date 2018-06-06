
void Emergency_func(void*){
  #define EMERGENCY1    2     // กำหนดปุ่ม ที่จะให้ traffic1 ไฟเขียว ทำงานฉุกเฉิน
  #define EMERGENCY2    4     // กำหนดปุ่ม ที่จะให้ traffic2 ไฟเขียว ทำงานฉุกเฉิน
  #define EMERGENCY3    5     // กำหนดปุ่ม ที่จะให้ traffic3 ไฟเขียว ทำงานฉุกเฉิน
  #define EMERGENCY4    13    // กำหนดปุ่ม ที่จะให้ traffic4 ไฟเขียว ทำงานฉุกเฉิน
  #define PRESSED       LOW   // สถานะกดปุ่ม เป็น LOW หรือ HIGH
  
  VOID SETUP(){     // SETUP ใน task ใช้ตัวพิมพ์ใหญ่
    pinMode( EMERGENCY1, INPUT_PULLUP);  pinMode( EMERGENCY2, INPUT_PULLUP);
    pinMode( EMERGENCY3, INPUT_PULLUP);  pinMode( EMERGENCY4, INPUT_PULLUP);
  }
  VOID LOOP(){      // LOOP ใน task ใช้ตัวพิมพ์ใหญ่
    if( xNormal) {
      if( digitalRead( EMERGENCY1 ) == PRESSED ) {
        TrafficLights_task.stop();
        xNormal = false; xTrafficStatus = 1;         // กำหนดโหมดฉุกเฉิน traffic1 เขียวทำงาน
        TrafficLights_task.start(TrafficLights_func); 
      }
      else if( digitalRead( EMERGENCY2 ) == PRESSED ) {
        TrafficLights_task.stop();
        xNormal = false; xTrafficStatus = 2;          // กำหนดโหมดฉุกเฉิน traffic2 เขียวทำงาน
        TrafficLights_task.start(TrafficLights_func);
      }
      else if( digitalRead( EMERGENCY3 ) == PRESSED ) {
        TrafficLights_task.stop();
        xNormal = false; xTrafficStatus = 3;          // กำหนดโหมดฉุกเฉิน traffic3 เขียวทำงาน
        TrafficLights_task.start(TrafficLights_func);
      }
      else if( digitalRead( EMERGENCY4 ) == PRESSED ) {
        TrafficLights_task.stop();
        xNormal = false; xTrafficStatus = 4;          // กำหนดโหมดฉุกเฉิน traffic4 เขียวทำงาน
        TrafficLights_task.start(TrafficLights_func);
      }
    }
    DELAY(80);      // DELAY(..) ใน task ใช้ตัวพิมพ์ใหญ่
  }
}

