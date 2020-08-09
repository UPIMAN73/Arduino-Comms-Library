#ifndef GENERAL_H
#define GENERAL_H

//#include <Arduino.h>

#define CLOX_SPEED 400000000L
#define BSIZE 8

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

// Can be different for arduino
//typedef unsigned int uint32_t;
//typedef unsigned long uint32_t;

typedef char * string;

unsigned int strnlen(const char * str);
void dellay(unsigned long ms);
bool * ctoBinary(char c);
bool * revBinary(bool * bin);

#endif