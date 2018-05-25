//*****************************************************************************
// Red, white and blue
//*****************************************************************************
#include "FastLED.h"
#include "common.h"
#include "redwhiteblue.h"
#include "DebugMacros.h"

void redwhiteblue()
{
  DPRINTLN_L("redwhiteblue:");

  fill_color( CRGB::Red, CRGB::Gray, CRGB::Blue);
  fill_color( CRGB::Blue, CRGB::Red, CRGB::Gray);
  fill_color( CRGB::Gray, CRGB::Blue, CRGB::Red);
}

void fill_color(CRGB col1, CRGB col2, CRGB col3){
  for (byte i = 0; i < NUM_LEDS;) {
    fill_solid(&(leds[i]), rwb_size, col1); // rwb_size white
    fill_solid(&(leds[i + rwb_size]), rwb_size, col2); // rwb_size blue
    fill_solid(&(leds[i + (rwb_size * 2)]), rwb_size, col3); // rwb_size red
    i += (rwb_size * 3);
  }
  FastLED.show();
  delay(250);
}
