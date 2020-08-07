#include "uart.h"

UART::UART(struct UARTCONFIG * uc, const unsigned long cs)
{
    //
    ucf = uc;
    cpu_speed = cs;
}

void UART::init()
{
    serial_com = ucf->pcfg->serial;
    write_en = ucf->ucsrb->TXEN;
    read_en = ucf->ucsrb->RXEN;
    frame_val = ucf->ucsrb->FRAME;
}

int UART::write(const char * str, unsigned int size)
{
    int status = -1;
    if (size > 0 && strlen(str) > 0)
    {
        //
        while (*str++ != '\0' && size != 0)
        {
            if (serial_com)
            {
                //digitalWrite(ucf->pcfg->playout->txpin, frame_val);
                delay(ubrr/8);
                //digitalWrite(ucf->pcfg->playout->txpin, );

            }
        }
    }
    return status;
}