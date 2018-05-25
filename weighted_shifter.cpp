
//*****************************************************************************
// block of weighted random colour shifting back and forth
//*****************************************************************************
#include "FastLED.h"
#include "common.h"
#include "weighted_shifter.h"
#include "DebugMacros.h"

void weighted_shifter()
{
  DPRINTLN_L("weighted_shifter:");
  fill_solid(&(leds[0]), NUM_LEDS, CRGB(0, 0, 0)); //all off
  FastLED.show();
  int hue = random(255);
  int step_value = 255 / (BLOCK_SIZE / 2);
  //fill_with pattern
  for (int iLed = 0; iLed < BLOCK_SIZE / 2; iLed++)
    leds[iLed] = CHSV(hue, 255, step_value * iLed);
  for (int iLed = BLOCK_SIZE / 2; iLed < BLOCK_SIZE; iLed++)
    leds[iLed] = CHSV(hue, 255, step_value * (BLOCK_SIZE - iLed));

  FastLED.show();

  shiftx2(10, BLOCK_SIZE);

  reverseshiftx2(10, BLOCK_SIZE);

  fill_solid(&(leds[0]), NUM_LEDS, CRGB(0, 0, 0)); //all off
  FastLED.show();
}

void shiftx2(int wait, int blocksize) {
  for (int iLed = 0; iLed < (NUM_LEDS - blocksize); iLed++) {
    delay(wait);
    memmove(&leds[1], &leds[0], (NUM_LEDS - 1)*sizeof(CRGB));
    leds[0] = CRGB(0, 0, 0);
    FastLED.show();
  }
}

void reverseshiftx2(int wait, int blocksize) {
  for (int iLed = 0; iLed < (NUM_LEDS - blocksize); iLed++) {
    delay(wait);
    CRGB tmp = leds[0];
    memmove(&leds[0], &leds[1], (NUM_LEDS - 1)*sizeof(CRGB));
    leds[NUM_LEDS - 1] = tmp;
    FastLED.show();
  }
}
