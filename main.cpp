#include "General/general.h"
#include <stdio.h>

using namespace std;


int main()
{
    char * str = "Hello World!";
    bool * binOps;
    int i;


    while (*str != '\0')
    {
        printf("%c\t", *str);
        binOps = revBinary(ctoBinary(*str));
        for (i = 0; i < 8; i++)
        {
            printf("%d", binOps[i]);
        }
        puts("");
        *str++;
    }

    puts("Start");
    delay(1000);
    puts("Finished");

}