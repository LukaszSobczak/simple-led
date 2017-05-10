// include header file with SimpleLed library
#include <SimpleLed.h>

const int ledPin = 13;
int iteration = 0, timeOn = 0, timeOff = 0;
// declaration object SimpleLed with pin number in constructor
SimpleLed led(ledPin);

void setup()
{
  // open serial port for debug communication
  Serial.begin(9600);
  while(!Serial);
  // set init values of blinking led
  timeOn = timeOff = 250;
  iteration = 10;
  // set values to led
  led.blink(timeOn, timeOff, iteration);
  // print help with commands for changing blink parameters
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

  // here is all, you have to pass the actual time (millis()) and
  // this function will take care for blink led at the right time
  // unless you delay program before execution this line
  // (then blinking led will delay)
  // if your main loop takes longer than blinking interval
  // you can execute update more than once in loop
  led.update(millis());
}

void menu()
{
    String input = Serial.readString();
    // reset counter of the repetitions and turn off led
    if(input == "reset")
    {
      led.reset();
    }
    // set how many times to toggle led state
    else if(input == "iteration")
    {
      Serial.println("How many times you want blink led? (-1 for infinity)");
      while(!Serial.available());
      iteration = Serial.readString().toInt();
      led.blink(timeOn, timeOff, iteration);
      Serial.println("OK");
    }
    // set time between toggle led state (in ms)
    else if(input == "interval")
    {
      Serial.println("How long to wait between blink led?");
      while(!Serial.available());
      timeOn = timeOff = Serial.readString().toInt();
      led.blink(timeOn, timeOff, iteration);
      Serial.println("OK");
    }
    // set how long to wait switch off led (in ms)
    else if(input == "timeOn")
    {
      Serial.println("How long to wait switch off led?");
      while(!Serial.available());
      timeOn  = Serial.readString().toInt();
      led.blink(timeOn, timeOff, iteration);
      Serial.println("OK");
    }
    // set how long to wait switch on led (in ms)
    else if(input == "timeOff")
    {
      Serial.println("How long to wait switch on led?");
      while(!Serial.available());
      timeOff  = Serial.readString().toInt();
      led.blink(timeOn, timeOff, iteration);
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
  Serial.println("reset - reset counter of the repetitions");
  Serial.println("iteration - set how many times to toggle led state");
  Serial.println("interval - set time between toggle led state (in ms)");
  Serial.println("timeOn - set how long to wait switch off led (in ms)");
  Serial.println("timeOff - set how long to wait switch on led (in ms)");
  Serial.println();
}
