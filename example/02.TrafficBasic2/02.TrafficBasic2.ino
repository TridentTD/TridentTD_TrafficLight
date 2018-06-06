#include <TridentTD_TrafficLight.h>

TridentTD_TrafficLight traffic1( 14,15,18);  // กำหนด traffic1 ด้วยขา Green, Yellow, Red
TridentTD_TrafficLight traffic2( 19,21,22);

void setup(){
	traffic1.begin();   // เริ่มต้นการใช้งาน traffic1
	traffic2.begin();
}

void loop(){
	traffic1.Green();  traffic2.Red();
	delay(9000);
	traffic1.Yellow(); traffic2.Yellow();
	delay(1000);
	traffic1.Red();		 traffic2.Green();
	delay(9000);
	traffic1.Yellow(); traffic2.Yellow();
	delay(1000);
}
