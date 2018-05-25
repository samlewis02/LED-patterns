//*****************************************************************************
// 20 on 20 off shifting
//*****************************************************************************
#include "FastLED.h"
#include "common.h"
#include "onoffshifter.h"
#include "DebugMacros.h"

void onoffshifter()
{
  DPRINTLN_L("onoffshifter:");
  onoffinit();
  shift(20);
  fill_solid(&(leds[0]), NUM_LEDS, CRGB(0, 0, 0)); //all off
  FastLED.show();
}

void shift(int wait) {
  for (int iLed = 0; iLed < NUM_LEDS; iLed++) {
    delay(wait);
    CRGB tmp = leds[NUM_LEDS - 1];
    memmove(&leds[1], &leds[0], (NUM_LEDS - 1)*sizeof(CRGB));
    leds[0] = tmp;
    FastLED.show();
  }
}

void onoffinit() {
  // generate initial pattern
  // 1. Fill all positions
  fill_solid(&(leds[0]), NUM_LEDS, CRGB(random(255), random(255), random(255)));
  // 2. Switch off every 20 leds
  for (byte i = 0; i < NUM_LEDS;)
  {
    for (byte j = 0; j < 20; j++)
      leds[j + 20 + i] = CRGB(0, 0, 0);
    i += 40;
  }
}
