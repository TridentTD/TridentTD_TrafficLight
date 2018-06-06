#include "TridentTD_TrafficLight.h"

TridentTD_TrafficLight::TridentTD_TrafficLight(uint8_t green, uint8_t yellow, uint8_t red)
: _green(green), _yellow(yellow), _red(red) { }

void TridentTD_TrafficLight::begin() {
  pinMode( _green,   OUTPUT);
  pinMode( _yellow,  OUTPUT);
  pinMode( _red,     OUTPUT);
  turnoff();
}

void TridentTD_TrafficLight::Red(){
  digitalWrite( _green,  HIGH);
  digitalWrite( _yellow, HIGH);
  digitalWrite( _red,    LOW);
//  digitalWrite( _green,  LOW);
//  digitalWrite( _yellow, LOW);
//  digitalWrite( _red,    HIGH);
}

void TridentTD_TrafficLight::Yellow(){
  digitalWrite( _green,  HIGH);
  digitalWrite( _yellow, LOW);
  digitalWrite( _red,    HIGH);
//  digitalWrite( _green,  LOW);
//  digitalWrite( _yellow, HIGH);
//  digitalWrite( _red,    LOW);
}

void TridentTD_TrafficLight::Green(){
  digitalWrite( _green,  LOW);
  digitalWrite( _yellow, HIGH);
  digitalWrite( _red,    HIGH);
//  digitalWrite( _green,  HIGH);
//  digitalWrite( _yellow, LOW);
//  digitalWrite( _red,    LOW);
}

void TridentTD_TrafficLight::turnoff(){
  digitalWrite( _green,  HIGH);
  digitalWrite( _yellow, HIGH);
  digitalWrite( _red,    HIGH);
//  digitalWrite( _green,  LOW);
//  digitalWrite( _yellow, LOW);
//  digitalWrite( _red,    LOW);
}

