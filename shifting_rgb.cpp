//*****************************************************************************
// shifting r,g,b
//*****************************************************************************
#include "FastLED.h"
#include "common.h"
#include "shifting_rgb.h"
#include "DebugMacros.h"

void shifting_rgb()
{
  DPRINTLN_L("shifting_rgb:");
  int dt = 300;
  for (byte i = 0; i < NUM_LEDS-1;)
  {
    leds[i] = CRGB::Red; // red
    leds[i + 2] = CRGB::Black; // off
    i += 3;
  }
  FastLED.show();
  delay(dt);
  for (byte i = 0; i < NUM_LEDS-1;)
  {
    leds[i] = CRGB::Black; // off
    leds[i + 1] = CRGB::Green; // green
    i += 3;
  }
  FastLED.show();
  delay(dt);
  for (byte i = 0; i < NUM_LEDS-1;)
  {
    leds[i + 1] = CRGB::Black; // off
    leds[i + 2] = CRGB::Blue; // blue
    i += 3;
  }
  FastLED.show();
  delay(dt);
}
