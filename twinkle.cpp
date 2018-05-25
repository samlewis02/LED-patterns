#include "FastLED.h"
#include "common.h"
#include "twinkle.h"
#include "DebugMacros.h"

void twinkle()
{
  DPRINTLN_L("twinkle:");
  // Base background color
  base_color = CRGB(0, 0, 0);
  // Peak color to twinkle up to
  peak_color = CRGB(peak_red, peak_green, peak_blue);
  // Currently set to brighten up a bit faster than it dims down,
  // but this can be adjusted.
  // Amount to increment the color by each loop as it gets brighter:
  delta_color_up =  CRGB(peak_red / 4, peak_green / 4, peak_blue / 4);

  TwinkleMapPixels();
  FastLED.show();
  // FastLED.delay(20);
}

void InitPixelStates()
{
  memset( PixelState, SteadyDim, sizeof(PixelState)); // initialize all the pixels to SteadyDim.
}

void TwinkleMapPixels()
{
  for ( uint16_t i = 0; i < NUM_LEDS; i++) {
    if ( PixelState[i] == SteadyDim) {
      // this pixels is currently: SteadyDim
      // so we randomly consider making it start getting brighter
      if ( random8() < CHANCE_OF_TWINKLE) {
        PixelState[i] = GettingBrighter;
      }

    } else if ( PixelState[i] == GettingBrighter ) {
      // this pixels is currently: GettingBrighter
      // so if it's at peak color, switch it to getting dimmer again
      if ( leds[i] >= peak_color ) {
        leds[i] = peak_color;
        PixelState[i] = GettingDimmerAgain;
      } else {
        // otherwise, just keep brightening it:
        leds[i] += delta_color_up;
      }

    } else { // getting dimmer again
      // this pixels is currently: GettingDimmerAgain
      // so if it's back to base color, switch it to steady dim
      if ( leds[i] <= base_color ) {
        leds[i] = base_color; // reset to exact base color, in case we overshot
        PixelState[i] = SteadyDim;
      } else {
        // otherwise, just keep dimming it down:
        //leds[i] -= delta_color_down;
        // Dim a color by 12.5% (32/256ths)
        // eventually fading to full black
        leds[i].fadeToBlackBy( 32 );
      }
    }
  }
}
