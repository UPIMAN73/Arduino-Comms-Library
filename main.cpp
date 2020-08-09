#include "UART/uart.h"
#include <stdio.h>
#include <time.h>

using namespace std;


int main()
{
    //string str = "Hello World!";
    
    struct BCONFIG bcfg;
    bcfg.BUAD = 9600;
    bcfg.UBRR = CLOX_SPEED / (bcfg.BUAD * 16) - 1;
    bcfg.UBRRHI = 0;

    struct UCSRA ucsra;
    ucsra.FRAME = 0;

    struct UCSRB ucsrb;
    ucsrb.TXEN = 1;
    ucsrb.RXEN = 0;

    struct UPIN upin;
    struct PLAYOUT playout;
    playout.pin = 0;

    upin.serial = true;
    upin.playout = &playout;

    

    struct UARTCONFIG ucf;
    
    ucf.bconfig = &bcfg;
    ucf.ucsra = &ucsra;
    ucf.ucsrb = &ucsrb;
    ucf.pcfg = &upin;

    printf("%d\n%d\n", ucf.ucsra->FRAME, ucf.ucsrb->TXEN);
    UART uart = UART(&ucf, CLOX_SPEED, true);
    uart.init();

    // cleanup
    bcfg = {0, 0, 0};
    ucsra.FRAME = 0;
    ucsrb.TXEN = 0;
    ucsrb.RXEN = 0;
    upin.serial = false;
    upin.playout = nullptr;
    delete upin.playout;
}