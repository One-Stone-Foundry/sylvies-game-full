#ifndef __GAME_H
#define __GAME_H

#include "./led.h"
#include "Particle.h"

class GAME {
public:
  void setup();

  class game {
  public:
    void turnOn(int led);
    void turnOff(int led);
    void setAll(bool state);
  };

  void celebrate();
};

#endif /* __GAME_H */
