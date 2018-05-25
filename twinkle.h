
#ifndef _TWINK_H
#define _TWINK_H
const byte CHANCE_OF_TWINKLE = 1;
static uint8_t PixelState[NUM_LEDS];
static CRGB base_color;
static CRGB peak_color;
static CRGB delta_color_up;
enum {
  GettingBrighter,
  GettingDimmerAgain,
  SteadyDim
};
extern byte peak_red, peak_green, peak_blue;
void twinkle();
void InitPixelStates();
void TwinkleMapPixels();
#endif
