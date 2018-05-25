#ifndef _COMN_H
#define _COMN_H
const int DATA_PIN = D4;
const int NUM_LEDS = 240;
extern CRGB leds[];
enum {
  COMETS,
  CYLON,
  MIDOUT,
  ONOFF,
  TWINK,
  PYMID,
  RWB,
  SHRBW,
  SHRGB,
  WGHTSH,
  NOISE
};
// HTTP update definitions
static const char* host = "esp8266-webupdate";
#endif
