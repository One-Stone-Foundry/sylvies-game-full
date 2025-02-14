/*
 * Particle Game
 * Author: Sylvie Rupe
 * Date: 2025-02-13
 */

#include "./game.h"
#include "./led.h"
#include "Particle.h"

SYSTEM_MODE(AUTOMATIC);

SerialLogHandler logHandler;

const int startButton = D10;
const int clickButton = D7;

int blinkerDuration = 100;
int bouncerDuration = 100;

int setBlinkerDuration(String command);
int setBouncerDuration(String command);
int celebrate(String command);

LED led;
LED::bounce bouncer;
LED::blink blinker;

GAME game;

void setup() {
  pinMode(startButton, INPUT_PULLDOWN);
  led.setup();

  Particle.function("blinkerDuration", setBlinkerDuration);
  Particle.function("bouncerDuration", setBouncerDuration);
  Particle.function("celebrate", celebrate);
}

void loop() {
  // if (digitalRead(startButton) == HIGH) {
  //   // scroller.pause();
  //   blinker.step(bouncer.currentLed, blinkerDuration);
  //   delay(1);
  // } else {
  //   bouncer.step(0, 10, bouncerDuration);
  //   delay(1);
  // }

  // TODO: why does clickButton not work, but startButton does? did I kill
  // another dupont cable?
  // if (digitalRead(clickButton) == HIGH) {
  //   game.celebrate();
  //   delay(1);
  // } else {
  //   delay(1);
  // }
}

int setBlinkerDuration(String command) {
  blinkerDuration = command.toInt();
  return blinkerDuration;
}

int setBouncerDuration(String command) {
  bouncerDuration = command.toInt();
  return bouncerDuration;
}

int celebrate(String command) {
  game.celebrate();
  return 1;
}