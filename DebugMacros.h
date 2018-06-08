// Variadic macros used to print information in de-bugging mode
// from LarryD, Arduino forum

#pragma once
// un-comment this line to print the debugging statements
//#define DEBUG
//#define DEBUG_LIGHT

#ifdef DEBUG
  #define DPRINT(...)    Serial.print(__VA_ARGS__)
  #define DPRINTLN(...)  Serial.println(__VA_ARGS__)
#else
  // define blank line
  #define DPRINT(...)
  #define DPRINTLN(...)
#endif
#ifdef DEBUG_LIGHT
  #define DPRINT_L(...)    Serial.print(__VA_ARGS__)
  #define DPRINTLN_L(...)  Serial.println(__VA_ARGS__)
#else
  // define blank line
  #define DPRINT_L(...)
  #define DPRINTLN_L(...)
#endif
