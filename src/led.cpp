#include "led.h"
#include "Particle.h"

const int LED::leds[11] = {A0, A1, A2, A5, S4, S3, SCK, MOSI, MISO, D5, D4};

void LED::setup() {
  for (int i = 0; i < (sizeof(leds) / sizeof(leds[0])); i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
}

void LED::led::turnOn(int led) { digitalWrite(leds[led], HIGH); }

void LED::led::turnOff(int led) { digitalWrite(leds[led], LOW); }

void LED::led::setAll(bool state) {
  for (int i = 0; i < (sizeof(leds) / sizeof(leds[0])); i++) {
    digitalWrite(leds[i], state ? HIGH : LOW);
  }
}

void LED::blink::step(int led, int duration) {
  static unsigned long previousMillis = 0;
  static int blinkCount = 0;
  static bool ledState = false;

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= duration * 2) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(leds[led], ledState ? HIGH : LOW);
    if (!ledState) {
      blinkCount++;
    }
  }
}

void LED::blink::pause() {
  LED::led led;
  led.setAll(false);
}

void LED::blink::reset() {
  LED::led led;
  led.setAll(false);
}

void LED::blink::run(int led, int duration, int count) {
  for (int i = 0; i < count; i++) {
    digitalWrite(leds[led], HIGH);
    delay(duration);
    digitalWrite(leds[led], LOW);
    delay(duration);
  }
}

void LED::scroll::step(int start, int end, int duration) {
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();
  static bool ledState = false;

  if (currentMillis - previousMillis >= duration) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(leds[start + currentLed], ledState ? HIGH : LOW);
    if (!ledState) {
      currentLed++;
      if (currentLed > end) {
        currentLed = start;
      }
    }
  }
}

void LED::scroll::pause() {
  LED::led led;
  led.setAll(false);
}

void LED::scroll::reset() {
  LED::led led;
  led.setAll(false);
  currentLed = 0;
}

void LED::scroll::run(int start, int end, int duration) {
  for (int i = start; i <= end; i++) {
    digitalWrite(leds[i], HIGH);
    delay(duration);
    digitalWrite(leds[i], LOW);
    delay(duration);
  }
}

void LED::bounce::step(int start, int end, int duration) {
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();
  static int direction = 1; // 1 for forward, -1 for backward

  if (currentMillis - previousMillis >= duration) {
    previousMillis = currentMillis;
    digitalWrite(leds[currentLed], LOW);
    currentLed += direction;
    if (currentLed > end) {
      currentLed = end - 1;
      direction = -1;
    } else if (currentLed < start) {
      currentLed = start + 1;
      direction = 1;
    }
    digitalWrite(leds[currentLed], HIGH);
  }
}

void LED::bounce::pause() {
  LED::led led;
  led.setAll(false);
}

void LED::bounce::reset() {
  LED::led led;
  led.setAll(false);
  currentLed = 0;
  direction = 1;
}

void LED::bounce::run(int start, int end, int duration) {
  LED::scroll scroller;

  scroller.run(start, end, duration);
  scroller.run(end, start, duration);
}