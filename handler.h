#ifndef _HAND_H_H
#define _HAND_H
extern int select;
extern byte peak_red;
extern byte peak_green;
extern byte peak_blue;
extern int setbright;
void handleMessage(AdafruitIO_Data *);
void handleTwcolor(AdafruitIO_Data *);
void handleBrightness(AdafruitIO_Data *);
#endif
