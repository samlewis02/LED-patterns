//*****************************************************************************
// middle outwards on then middle outwards off
//*****************************************************************************
#include "FastLED.h"
#include "common.h"
#include "middle_out.h"
#include "DebugMacros.h"

void  middle_out()
{
  DPRINTLN_L("middle_out:");
  int hue = random(255);
  midout(hue);
  midout(0);
}

void midout(int col) {
  for (byte i = 119, j = 120; j < 240; j++, i--)
  {
    leds[i] = CHSV(col, 255, 255);
    leds[j] = CHSV(col, 255, 255);
    FastLED.show();
    delay(50);
  }
}
