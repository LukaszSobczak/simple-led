/*
  SimpleLed.cpp - Library for simple toggle LED state and blinking LED without delay. 
  Created by Lukasz Sobczak, May 5, 2017.
  https://github.com/LukaszSobczak/simple-led
  Released into the public domain.
*/
#include "SimpleLed.h"

SimpleLed::SimpleLed(byte ledPin) : ledPin(ledPin)
{
  pinMode(ledPin, OUTPUT);
  reset();
}

void SimpleLed::reset()
{
  initBlink = true;
  startMillis = 0;
  blinkedTimes = 0;
  turnOff();
}

void SimpleLed::turnOn()
{
  ledState = HIGH;
  digitalWrite(ledPin, ledState);
}

void SimpleLed::turnOff()
{
  ledState = LOW;
  digitalWrite(ledPin, ledState);
}

void SimpleLed::toggle()
{
  if(isTurnOn())
    turnOff();
  else
    turnOn();
}

bool SimpleLed::isTurnOn()
{
  return ledState == HIGH;
}

void SimpleLed::blink(int millis, int intervalMillis, int nTimes)
{
  blink(millis, intervalMillis, intervalMillis, nTimes);
}

void SimpleLed::blink(int millis, int timeOnMillis, int timeOffMillis, int nTimes)
{  
  if(blinkedTimes >= 2*nTimes && nTimes >= 0)
    return;
  
  if(initBlink)
  {
    startMillis = millis;
    initBlink = false;
  }
  
  if(millis - startMillis >= (isTurnOn() ? timeOnMillis : timeOffMillis))
  {
    startMillis = millis;
    ++blinkedTimes;
    toggle();
  }
}

