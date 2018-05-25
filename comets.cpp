#include "Arduino.h"
#include "FastLED.h"
#include "common.h"
#include "comets.h"
#include "DebugMacros.h"

void comets() {
  DPRINTLN_L("comets:");
   for (int hue = 0; hue < 255; hue=hue+15) {
    for (int c = 0; c < 24; c++) {
      int v = 255 - 16 * c;
      if (c > 15) v = 0;
      leds[0] = CHSV(hue, 255, v);
      FastLED.show();
      delay(10);
      memmove(&leds[1], &leds[0], (NUM_LEDS - 1)*sizeof(CRGB));
    }
  }
}
