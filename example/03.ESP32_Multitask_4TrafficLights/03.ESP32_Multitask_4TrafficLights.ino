/************************************************************
 * 
 * ตัวอย่าง นี้ จะเป็นการทำงานของ ไฟจราจร 4 ชุด
 * และมีปุ่มฉุกเฉิน 4 ปุ่ม ไว้กดเพื่อให้ ไฟจราจรชุดไหน เข้าโหมดฉุกเฉิน ไฟเขียวปล่อยรถยาวก่อนเข้าโหมดปกติ
 * 
 * สำหรับ ESP32 โดยเป็นการเขียนแบบ TridentTD-Style MultiTasking
 * ให้ download ไลบรารี่ TridentTD_EasyFreeRTOS32 ได้ที่
 * https://github.com/TridentTD/TridentTD_EasyFreeRTOS32
 * 
 *************************************************************/

#include <TridentTD_EasyFreeRTOS32.h>

EasyFreeRTOS32 TrafficLights_task, Emergency_task;			//ประกาสตัวแปร task ต่างๆ
void TrafficLights_func(void*), Emergency_func(void*);	//ประกาศฟังกชั่นสำหรบ task ต่างๆ

//---- ตัวแปร share ระหว่าง task -----
bool   xNormal=true;     //  true : ไฟจราจรปกติ, false: ไฟจราจรโหมดฉุกเฉิน
int8_t xTrafficStatus;   //  0: ปิดหมด, 1: จราจร1ไฟเขียว, 2: จราจร2ไฟเขียว, ....
//---------------------------------

void setup() {  // setup() หลัก พิมพ์เล็ก
  Serial.begin(115200); Serial.println();
  
  xNormal = true; xTrafficStatus = 1;           // กำหนดสถานะไฟจราจร โหมดปกติ และ ให้ traffic1 ไฟเขียว
  TrafficLights_task.start(TrafficLights_func); // เริ่ม TrafficLights_task ทำงาน
  Emergency_task.start(Emergency_func);         // เริ่ม Emergency_task ทำงาน
}

void loop() { } // loop() หลัก พิมพ์เล็ก  - ไม่ต้องใช้ แต่ให้มีไว้

