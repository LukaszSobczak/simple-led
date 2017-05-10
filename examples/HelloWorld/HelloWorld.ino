#include <SimpleLed.h>

const int ledPin = 13;
// declaration object SimpleLed with pin number in constructor
SimpleLed led(ledPin);

void setup()
{
  // open serial port for debug communication
  Serial.begin(9600);
  while(!Serial);
  
  printHelp();
}

void loop()
{
  // check if bytes are available for reading from serial and process them
  if(Serial.available())
  {
    // serial communication with user
    menu();
  }
}

void menu()
{
    String input = Serial.readString();
    if(input == "on")
    {
      // turn on led
      led.on();
      Serial.println("OK");
    }
    // set time between toggle led state (in ms)
    else if(input == "off")
    {
      // if led is on, turn off
      if(led.isOn())
        led.off();
      Serial.println("OK");
    }
    // set how long to wait switch off led (in ms)
    else if(input == "toggle")
    {
      // toggle led state
      led.toggle();
      Serial.println("OK");
    }
    else
    {
      Serial.println("Invalid command!");
      printHelp();
    }
}

// print help with commands for changing blink parameters
void printHelp()
{
  Serial.println("Enter one of the following commands for change blink parameters");
  Serial.println("on - reset counter of the repetitions");
  Serial.println("off - set how many times to toggle led state");
  Serial.println("toggle - set time between toggle led state (in ms)");
  Serial.println();
}

