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
  SimpleLed(const byte ledPin);
  void reset();
  void on();
  void off();
  void toggle();
  bool isOn();
  void update(int millis);
  void blink(int intervalMillis, int iteration);
  void blink(int timeOnMillis, int timeOffMillis, int iteration);

private:
  const byte ledPin;
  byte ledState;
  bool initBlink;
  int startMillis;
  int blinkedTimes;
  int iteration;
  int timeOn, timeOff;

  bool isEndBlinking();
};

#endif // _SIMPLE_LED_H_

