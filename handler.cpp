#include "AdafruitIO_WiFi.h"
#include "handler.h"
#include "DebugMacros.h"

void handleMessage(AdafruitIO_Data *data) {
  DPRINTLN("Pattern Received:");
  // convert the data to integer
  select = data->toInt();
  DPRINTLN(select);
}

void handleTwcolor(AdafruitIO_Data *data) {
  DPRINTLN("Color Received:");
  // convert the data to integer
  peak_red = data->toRed();
  peak_green = data->toGreen();
  peak_blue = data->toBlue();
  DPRINT("Twinkle red: 0x");
  DPRINTLN(peak_red, HEX);
  DPRINT("Twinkle green: 0x");
  DPRINTLN(peak_green, HEX);
  DPRINT("Twinkle blue: 0x");
  DPRINTLN(peak_blue, HEX);
}

void handleBrightness(AdafruitIO_Data *data) {
  DPRINTLN("Brightness Received:");
  // convert the data to integer
  setbright = data->toInt();
  DPRINT("Brightness: ");
  DPRINTLN(setbright);
}
