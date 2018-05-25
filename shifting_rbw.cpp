//****************************************************************************
//shifting rainbow
//****************************************************************************
#include "FastLED.h"
#include "common.h"
#include "shifting_rbw.h"
#include "DebugMacros.h"

void shifting_rainbow()
{
  DPRINTLN_L("shifting_rainbow:");
  byte j = 0;
  for (byte i = 0; i < NUM_LEDS; i++) {
    leds[i] = Wheel((i + j++) & 255);
  }
  shift(20);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
CRGB Wheel(byte WheelPos) {
  if (WheelPos < 85) {
    return CRGB(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
  else if (WheelPos < 170) {
    WheelPos -= 85;
    return CRGB(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  else {
    WheelPos -= 170;
    return CRGB(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
