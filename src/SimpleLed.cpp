/*
  SimpleLed.cpp - Library for simple toggle LED state and blinking LED without delay. 
  Created by Lukasz Sobczak, May 5, 2017.
  https://github.com/LukaszSobczak/simple-led
  Released into the public domain.
*/
#include "SimpleLed.h"

SimpleLed::SimpleLed(const byte ledPin) : ledPin(ledPin)
{
  pinMode(ledPin, OUTPUT);
  reset();
}

void SimpleLed::reset()
{
  initBlink = true;
  startMillis = 0;
  blinkedTimes = 0;
  off();
}

void SimpleLed::on()
{
  ledState = HIGH;
  digitalWrite(ledPin, ledState);
}

void SimpleLed::off()
{
  ledState = LOW;
  digitalWrite(ledPin, ledState);
}

void SimpleLed::toggle()
{
  if(isOn())
    off();
  else
    on();
}

bool SimpleLed::isOn()
{
  return ledState == HIGH;
}

void SimpleLed::update(int millis)
{
  if(isEndBlinking())
    return;
  
  if(initBlink)
  {
    startMillis = millis;
    initBlink = false;
  }

  if(timeOn <= 0)
    off();    
  else if(millis - startMillis >= (isOn() ? timeOn : timeOff))
  {
    startMillis = millis;
    ++blinkedTimes;
    toggle();
  }
}

void SimpleLed::blink(int intervalMillis, int iteration)
{
  blink(intervalMillis, intervalMillis, iteration);
}

void SimpleLed::blink(int timeOnMillis, int timeOffMillis, int iteration)
{
  timeOn = timeOnMillis;
  timeOff = timeOffMillis;
  this->iteration = iteration;
  reset();
}

bool SimpleLed::isEndBlinking()
{
  return (blinkedTimes >= 2*iteration && iteration >= 0) || 
         (timeOn <= 0 && timeOff <= 0);
}

