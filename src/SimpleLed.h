/*
  SimpleLed.h - Library for simple toggle LED state and blinking LED without delay. 
  Created by Lukasz Sobczak, May 5, 2017.
  https://github.com/LukaszSobczak/simple-led
  Released into the public domain.
*/
#ifndef _SIMPLE_LED_H_
#define _SIMPLE_LED_H_
#include <Arduino.h>

class SimpleLed
{
public:
  SimpleLed(byte ledPin);
  void reset();
  void turnOn();
  void turnOff();
  void toggle();
  bool isTurnOn();
  void blink(int millis, int intervalMillis, int nTimes);
  void blink(int millis, int timeOnMillis, int timeOffMillis, int nTimes);

private:
  byte ledPin;
  byte ledState;
  bool initBlink;
  int startMillis;
  int blinkedTimes;
};

#endif // _SIMPLE_LED_H_
