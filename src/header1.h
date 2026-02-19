#ifndef header1_H
#define header1_H
#define DELAY 100
#define ON 0x01
#define OFF 0x00
#define NUM LEDS 0x03

#define RED_LED 0x400000
#define BLUE_LED 0x200000
#define GREEN_LED 0x800000
#define iof_en (*((volatile uint32_t*)0x10012038))
#define PIN_0 0x10000
#define PIN_1 0x20000

// input

#define PIN_3 0x00080000
#define PIN_4 0x100000
#define PIN_5 0x00200000
#define PIN_6 0x00400000
#define PIN_8 0x00000001
#define PIN_9 0x00000002
#define PIN_18 0x00001000
#define PIN_19 0x00002000

#define TST PIN_8
#define ACK PIN_9 
#define FLA PIN_18
#define OLA PIN_19 /// OVERFLOW LEVEL ALARM

#define GREEN_LED PIN_3
#define YELLOW_LED PIN_5
#define RED_LED PIN_6

void setupGPIO();
int setLED(int color,int state);
void delay(int milliseconds);
int checkBot(int pin);
#endif