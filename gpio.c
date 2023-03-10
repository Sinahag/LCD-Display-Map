/* GPIO Interface C Sample Code */
/* This code is intentionally left with room for improvement.
   Update this interface as needed. */
#include <stdio.h>
#include "gpio.h"

// #define LCD_RS  25               //Register select pin
// #define LCD_E   24               //Enable Pin
// #define LCD_D4  23               //Data pin 4
// #define LCD_D5  22               //Data pin 5
// #define LCD_D6  21               //Data pin 6
// #define LCD_D7  18               //Data pin 7

/*

GPIO MAPPING:
P9_25  --> RS
P9_24  --> E
P9_23  --> D4
P9_22  --> D5 
P9_21  --> D6
P9_18  --> D7

*/


/*
config-pin P9_25 gpio
config-pin P9_24 gpio
config-pin P9_23 gpio
config-pin P9_22 gpio
config-pin P9_21 gpio
config-pin P9_18 gpio
*/

#define D4_DIRECTION "/sys/class/gpio/gpio49/direction"
#define D4_VALUE "/sys/class/gpio/gpio49/value"

#define D5_DIRECTION "/sys/class/gpio/gpio2/direction"
#define D5_VALUE "/sys/class/gpio/gpio2/value"

#define D6_DIRECTION "/sys/class/gpio/gpio3/direction"
#define D6_VALUE "/sys/class/gpio/gpio3/value"

#define D7_DIRECTION "/sys/class/gpio/gpio4/direction"
#define D7_VALUE "/sys/class/gpio/gpio4/value"

#define RS_DIRECTION "/sys/class/gpio/gpio117/direction"
#define RS_VALUE "/sys/class/gpio/gpio117/value"

#define E_DIRECTION "/sys/class/gpio/gpio15/direction"
#define E_VALUE "/sys/class/gpio/gpio15/value"

static void writeToFile(const char* fileName, const char* value)
{
	FILE *pFile = fopen(fileName, "w");
	fprintf(pFile, "%s", value);
	fclose(pFile);
}

void GPIO_writeDirection(int gpio, char* dir)
{
    char* fileName;

    switch (gpio) {
        case D4_GPIO_NUMBER:
            fileName = D4_DIRECTION;
            break;
        case D5_GPIO_NUMBER:
            fileName = D5_DIRECTION;
            break;
        case D6_GPIO_NUMBER:
            fileName = D6_DIRECTION;
            break;
        case D7_GPIO_NUMBER:
            fileName = D7_DIRECTION;
            break;
        case RS_GPIO_NUMBER:
            fileName = RS_DIRECTION;
            break;
        case E_GPIO_NUMBER:
            fileName = E_DIRECTION;
            break;
    }
    writeToFile(fileName, dir);
}

void GPIO_writeValue(int gpio, char* val)
{
    char* fileName;

    switch (gpio) {
        case D4_GPIO_NUMBER:
            fileName = D4_VALUE;
            break;
        case D5_GPIO_NUMBER:
            fileName = D5_VALUE;
            break;
        case D6_GPIO_NUMBER:
            fileName = D6_VALUE;
            break;
        case D7_GPIO_NUMBER:
            fileName = D7_VALUE;
            break;
        case RS_GPIO_NUMBER:
            fileName = RS_VALUE;
            break;
        case E_GPIO_NUMBER:
            fileName = E_VALUE;
            break;
    }
    writeToFile(fileName, val);
}
