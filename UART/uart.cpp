#include "uart.h"

UART::UART(struct UARTCONFIG * uc, const unsigned long cs, bool parity_bit)
{
    // UART
    ucf = uc;
    cpu_speed = cs;
    parity_val = parity_bit;
    ubrr = uc->bconfig->BUAD;
}

void UART::init()
{
    serial_com = ucf->pcfg->serial;
    write_en = ucf->ucsrb->TXEN;
    read_en = ucf->ucsrb->RXEN;
    frame_val = ucf->ucsra->FRAME;
}

int UART::write(const char * str, unsigned int size)
{
    int status = -1;
    if (size > 0 && strnlen(str) > 0)
    {
        if (serial_com)
        {
            bool * binc;

            while (*str != '\0' && size != 0)
            {
                //digitalWrite(ucf->pcfg->playout->txpin, frame_val);
                dellay(ubrr/BSIZE);

                binc = ctoBinary(*str); // Character to binary conversion

                // Sending character
                for (int i = 0; i < BSIZE; i++)
                {
                    //digitalWrite(ucf->pcfg->playout->txpin, binc[i]);
                    dellay(ubrr/BSIZE); 
                }

                //digitalWrite(ucf->pcfg->playout->txpin, parity_val);  // Parity Bit

                // end bit
                dellay(ubrr/BSIZE);
                //digitalWrite(ucf->pcfg->playout->txpin, frame_val);
                
                // goto next value
                *str++;
                size--;
            }
        }
        
        status = 1;
    }
    return status;
}