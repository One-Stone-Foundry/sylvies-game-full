#include "./game.h"
#include "./led.h"
#include "Particle.h"

void GAME::celebrate() {
  static int count = 3;
  static int duration = 250;

  static LED::led led;

  led.setAll(false);

  for (int i = 0; i < count; i++) {
    led.setAll(true);
    delay(duration);
    led.setAll(false);
    delay(duration);
  }
}