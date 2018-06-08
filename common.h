#ifndef _COMN_H
#define _COMN_H
const int DATA_PIN = D4;
const int NUM_LEDS = 240;
extern CRGB leds[];
enum {
  COMETS = 1, // we want to omit 0
  CYLON, // = 2
  MIDOUT,
  ONOFF,
  TWINK,
  PYMID,
  RWB,
  SHRBW,
  SHRGB,
  WGHTSH,
  NOISE // = 11
};

// HTTP update definitions
static const char* host = "wemos-leds";
#endif
