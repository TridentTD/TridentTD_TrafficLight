TridentTD_TrafficLight Library
===

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
ไลบรารี่สำหรับ ควบคุม ไฟจราจร เขียว เหลือง แดง 

<p align="center">
  <img src="trafficlights.jpg" alt="image"/>
</p>  

### วิธีการใช้งาน  

1. เรียกใช้ไลบรารี่  
```c  
     #include <TridentTD_TrafficLight.h>
``` 
2. ประกาศตัวแปร traffic พร้อมกำหนดขา pin  
```c  
     TridentTD_TrafficLight  traffic1( 14,15,18);  // ขา Green, Yellow, Red
```
3. เริ่มต้นใช้งาน traffic  
```c  
     traffic1.begin();
```
4. หากจะเรียก ไฟไหนทำงาน ไฟอื่นดับหมด ให้เรียก  
```c
     traffic1.Green();    // ไฟเขียวทำงาน   ไฟอื่นดับหมด
     traffic1.Yellow();   // ไฟเหลืองทำงาน  ไฟอื่นดับหมด
     traffic1.Red();      // ไฟแดงทำงาน    ไฟอื่นดับหมด
```
5. หากจะปิดไฟหมดทุกดวง
```c
     traffic1.turnoff();
```

-----
**TridentTD**  
6 มิถุนายน 2561 (ปีแห่งฤดูฝนตกชุก)  
