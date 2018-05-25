//*****************************************************************************
// increase brightness moving out from middle
//*****************************************************************************
#include "FastLED.h"
#include "common.h"
#include "pyramid.h"
#include "DebugMacros.h"

void pyramid () {
  DPRINTLN_L("pyramid:");
  int k = random(255);
  for (int i = 0, j = 119; i < 120; i++, j--) {
    leds[i + 120] = CHSV( k, 255, 255 - 2 * i);
    leds[j] = CHSV( k, 255, 255 - 2 * i);
    FastLED.show();
    fadeall();
  }
}
