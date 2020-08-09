#include "general.h"

unsigned int strnlen(const char * str)
{
    unsigned int res;
    while (*str++ != '\0')
        res++;
    return res;
}

// delay based on number of seconds
void dellay(unsigned long ms)
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