#ifndef __TRIDENTTD_TRAFFICLIGHT_H__
#define __TRIDENTTD_TRAFFICLIGHT_H__

#include <Arduino.h>

class TridentTD_TrafficLight {
public:
  TridentTD_TrafficLight(uint8_t green, uint8_t yellow, uint8_t red);
  void begin();
  void Red();
  void Yellow();
  void Green();
  void turnoff();
private:
  uint8_t _green, _red, _yellow;
  uint8_t _GState, _RState, _YState; 
};

#endif //__TRIDENTTD_TRAFFICLIGHT_H__

