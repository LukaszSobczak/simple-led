# SimpleLed

My first library for Arduino which provide simple toggle LED state and blinking LED without delay and freezing board.

### Instalation

You can download library ZIP file directly from [here](https://github.com/LukaszSobczak/simple-led/raw/master/library/SimpleLed.zip). To install my *SimpleLed* library open IDE Arduino, and select menu *Sketch*->*Include Library*->*Add .ZIP Library...*. Then in new dialog you can find downloaded file and open it. 

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
on();
off();
toggle();
isOn();
reset();
update(int millis);
blink(int intervalMillis, int nTimes);
blink(int timeOn, int timeOff, int nTimes);
```

The first 4 function is trivial (example [here](examples/HelloWorld/HelloWorld.ino)) but details ``blink``, ``update`` and ``reset`` functions have been discussed in the example [here](examples/Blinking/Blinking.ino).
