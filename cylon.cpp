#include "FastLED.h"
#include "common.h"
#include "cylon.h"
#include "DebugMacros.h"

static uint8_t hue = 0;

void cylon() {
  DPRINTLN_L("comets:");
  int i;

  // First slide the led in one direction
  for (i = 0; i < NUM_LEDS; i++) {
    slide(i);
  }
  // Now go in the other direction.
  for (i = (NUM_LEDS) - 1; i >= 0; i--) {
    slide(i);
  }
}

void slide(int i) {
  // Set the i'th led to hue
  leds[i] = CHSV(hue++, 255, 255);
  // Show the leds
  FastLED.show();
  // now that we've shown the leds, reset the i'th led to black
  // leds[i] = CRGB::Black;
  fadeall();
  // Wait a little bit before we loop around and do it again
  delay(10);

}

void fadeall() {
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i].nscale8(250);
  }
}
