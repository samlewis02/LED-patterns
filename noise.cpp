#include "FastLED.h"
#include "common.h"
#include "noise.h"
#include "DebugMacros.h"

void noises() {
  DPRINTLN_L("noise:");
  x = random16();
  y = random16();
  z = random16();

  static uint8_t ihue = 0;
  fillnoise8();
  for (int i = 0; i < kMatrixWidth; i++) {
    for (int j = 0; j < kMatrixHeight; j++) {
      // We use the value at the (i,j) coordinate in the noise
      // array for our brightness, and the flipped value from (j,i)
      // for our pixel's hue.
      leds[XY(i, j)] = CHSV(noise[j][i], 255, noise[i][j]);

      // You can also explore other ways to constrain the hue used, like below
      // leds[XY(i,j)] = CHSV(ihue + (noise[j][i]>>2),255,noise[i][j]);
    }
  }
  ihue += 1;

  LEDS.show();
  // delay(10);
}

// Fill the x/y array of 8-bit noise values using the inoise8 function.
void fillnoise8() {
  for (int i = 0; i < MAX_DIMENSION; i++) {
    int ioffset = scale * i;
    for (int j = 0; j < MAX_DIMENSION; j++) {
      int joffset = scale * j;
      noise[i][j] = inoise8(x + ioffset, y + joffset, z);
    }
  }
  z += speed;
}

uint16_t XY( uint8_t x, uint8_t y)
{
  uint16_t i;
  i = (y * kMatrixWidth) + x;
  return i;
}
