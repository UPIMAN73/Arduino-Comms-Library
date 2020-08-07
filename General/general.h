//#include <Arduino.h>

#define CLOX_SPEED 400000000L
#define BSIZE 8

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

// Can be different for arduino
//typedef unsigned int uint32_t;
//typedef unsigned long uint32_t;


unsigned int strlen(const char * str)
{
    unsigned int res;
    while (*str++ != '\0')
        res++;
    return res;
}

// delay based on number of seconds
void delay(unsigned long ms)
{
    unsigned long executions = CLOX_SPEED * ms / 1000;
    while (executions > 0)
    executions--;
}


// Convert char to binary
bool * ctoBinary(char c)
{
    char s = c;
    bool * binary = new bool[BSIZE];
    for (int i = 0; i < BSIZE; i++)
    {
        binary[i] = s & 1;
        s = s >> 1;
    }
    s = 0;
    return binary;
}

// Reverse Binary Definition Table
bool * revBinary(bool * bin)
{
    bool * rev = new bool[BSIZE];
    for (int i = BSIZE - 1; i >= 0; i--)
    {
        rev[BSIZE - (i + 1)] = bin[i];
    }
    return rev;
}