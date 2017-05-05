# SimpleLed

My first library for Arduino which provide simple toggle LED state and blinking LED without delay and freezing board.

### Instalation

You can download library ZIP file directly from [here](https://github.com/LukaszSobczak/simple-led/raw/master/library/SimpleLed.zip). To install my *SimpleLed* library open IDE Arduino, and select menu *Sketch*->*Include Library*->*Add .ZIP Library...*. Then in new window you can find downloaded file and open it. 

> After instalation new library I recommend to restart IDE Arduino for enable syntax highlights.

### Usage

Use of my library is extremely easy. First you have to add ``#include`` directive like this:
```c++
#include <SimpleLed.h>
```

After that you can declare new variable of ``SimpleLed`` type with LED port number in constructor:
```c++
const int ledPin = 13;
SimpleLed led(ledPin);
```

Next you can toggle LED state and blinking LED and whatever thanks to the following interface:
```c++
reset();
turnOn();
turnOff();
toggle();
isTurnOn();
blink(int millis, int intervalMillis, int nTimes);
blink(int millis, int timeOn, int timeOff, int nTimes);
```

The first 5 function is trivial but details ``blink`` function has been discussed in the example [here](examples/Blinking/Blinking.ino).
