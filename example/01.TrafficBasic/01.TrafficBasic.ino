#include <TridentTD_TrafficLight.h>

TridentTD_TrafficLight traffic1( 14,15,18);  // กำหนด traffic1 ด้วยขา Green, Yellow, Red

void setup(){
	traffic1.begin();   // เริ่มต้นการใช้งาน traffic1
}

void loop(){
	traffic1.Green();   // ไฟเขียวติดนอกนั้นดับหมด
	delay(9000);
	traffic1.Yellow();  // ไฟเหลืองติดนอกนั้นดับหมด
	delay(1000);
	traffic1.Red();     // ไฟแดงติดนอกนั้นดับหมด
	delay(3000);
	traffic1.turnoff(); // ไฟดับหมด
}

