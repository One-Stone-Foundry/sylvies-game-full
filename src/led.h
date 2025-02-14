#ifndef __LED_H
#define __LED_H

#include "Particle.h"

class LED {
public:
  static const int leds[11];

  void setup();

  class scroll {
  public:
    void run(int start, int end, int duration);
    void step(int start, int end, int duration);
    void pause();
    void reset();
    int currentLed;
  };

  class bounce {
  public:
    void run(int start, int end, int duration);
    void step(int start, int end, int duration);
    void pause();
    void reset();
    int currentLed;
    bool direction = true;
  };

  class blink {
  public:
    void run(int led, int duration, int count);
    void step(int led, int duration);
    void pause();
    void reset();
  };

  class led {
  public:
    void turnOn(int led);
    void turnOff(int led);
    void setAll(bool state);
  };
};

#endif /* __LED_H */
