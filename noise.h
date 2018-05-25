#ifndef _NSE_H
#define _NSE_H
// Params for width and height
const uint8_t kMatrixWidth = 24;
const uint8_t kMatrixHeight = 10;
const int MAX_DIMENSION = 24;
const uint16_t scale = 4011;
const uint16_t speed = 20;
static int x;
static int y;
static int z;
// This is the array that we keep our computed noise values in
static uint8_t noise[MAX_DIMENSION][MAX_DIMENSION];
void noises();
uint16_t XY( uint8_t, uint8_t);
void fillnoise8();
#endif
