#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include "FastLED.h"
#include "common.h"
#include "config.h"
#include "handler.h"
#include "comets.h"
#include "cylon.h"
#include "middle_out.h"
#include "onoffshifter.h"
#include "twinkle.h"
#include "pyramid.h"
#include "redwhiteblue.h"
#include "shifting_rbw.h"
#include "shifting_rgb.h"
#include "weighted_shifter.h"
#include "noise.h"
#include "DebugMacros.h"

CRGB leds[NUM_LEDS];
// set up the feeds
// pattern selector
AdafruitIO_Feed *mypattern = io.feed("pattern");
// twinkle colour
AdafruitIO_Feed *mytwcolor = io.feed("twcolor");
// brightness for solid color
AdafruitIO_Feed *mybrightness = io.feed("brightness");
int select = TWINK;
int old_select;
byte peak_blue = 0x80;
byte peak_red = 0x80;
byte peak_green = 0x80;
int setbright = 128; // half bright to start
ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;
// Static IP = 192.168.1.140
IPAddress ip(192,168,1,140);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

void setup() {
  LEDS.setBrightness(255);
  LEDS.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
  LEDS.showColor(CRGB::Black); // all off

  // start the serial connection
  Serial.begin(115200);

  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
  WiFi.begin(ssid, password);
  DPRINTLN("WiFi failed, retrying.");
  }
  WiFi.config(ip, gateway, subnet);
  DPRINTLN_L("WiFi connected");
  DPRINT_L("IP address: ");
  DPRINTLN_L(WiFi.localIP());
  MDNS.begin(host);

  httpUpdater.setup(&httpServer);
  httpServer.begin();

  MDNS.addService("http", "tcp", 80);
  Serial.printf("HTTPUpdateServer ready! Open http://%s.local/update in your browser\n", host);

  // connect to io.adafruit.com
  DPRINT("Connecting to Adafruit IO");
  io.connect();
  mypattern->onMessage(handleMessage);
  mytwcolor->onMessage(handleTwcolor);
  mybrightness->onMessage(handleBrightness);
  int w = 0;
  // wait for a connection
  while (io.status() < AIO_CONNECTED) {
    // light leds while waiting
    leds[w++] = CRGB::Red;
    FastLED.show();
    DPRINT(".");
    delay(500);
  }
  // we are connected
  DPRINTLN();
  DPRINTLN(io.statusText());
  fill_solid(&(leds[0]), w, CRGB::Green); //all that were red to green
  FastLED.show();
  delay(1000); // hold that for a second
  fill_solid(&(leds[0]), NUM_LEDS, CRGB::Black); //all off

  InitPixelStates();
}

void loop() {
  io.run();
  httpServer.handleClient();
  DPRINT("Brightness = ");DPRINTLN(setbright);
  DPRINT("peak_red = 0x");DPRINTLN(peak_red,HEX);
  DPRINT("peak_green = 0x");DPRINTLN(peak_green, HEX);
  DPRINT("peak_blue = 0x");DPRINTLN(peak_blue, HEX);
  DPRINT("Select = "); DPRINTLN(select);
  switch (select){
    case COMETS:
    DPRINTLN("Comets selected");
    comets();
    break;
    case CYLON:
    DPRINTLN("Cylon selected");
    cylon();
    break;
    case MIDOUT:
    DPRINTLN("Middle out selected");
    middle_out();
    break;
    case ONOFF:
    DPRINTLN("On off shifter selected");
    onoffshifter();
    break;
    case TWINK:
    DPRINTLN("Twinkle selected");
    twinkle();
    break;
    case PYMID:
    DPRINTLN("Pyramid selected");
    pyramid();
    break;
    case RWB:
    DPRINTLN("Red white blue selected");
    redwhiteblue();
    break;
    case SHRBW:
    DPRINTLN("Shifting rainbow selected");
    shifting_rainbow();
    break;
    case SHRGB:
    DPRINTLN("Shifting RGB selected");
    shifting_rgb();
    break;
    case WGHTSH:
    DPRINTLN("Weighted shifter selected");
    weighted_shifter();
    break;
    case NOISE:
    DPRINTLN("Noise selected");
    noises();
    break;
    case 99: // all off
    DPRINTLN("all off");
    LEDS.showColor(CHSV(0, 0, setbright)); // all off until setbright
    break;

    default:
    DPRINTLN("Twinkle selected");
    twinkle();
  }
  if (select != old_select) {
    FastLED.clear();
   for (int led = 0; led < NUM_LEDS; led++) {
     leds[led] = CRGB::Black;
   }
    delay(1000);
    old_select = select;
  }
  //delay(2000);
}
