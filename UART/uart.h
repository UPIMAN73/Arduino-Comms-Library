#ifndef __UART_H__
#define __UART_H__
#include "General/general.h"


#define XTAL CLOX_SPEED
#define DBUAD 9600


// Buad Rate config
struct 
{
    uint16_t BUAD;          // Bit rate
    uint8_t UBRR;           // UART Buad Rate Register
    uint8_t UBRRHI : 4;     // UART Buad Rate Register High
} BCONFIG;

/*
 * Each of these register structures can easily be converted to a hexadecimal
 * as a way of operating the register. However, this shows an easier visual of
 * what is gonig on when we break down the registers.
 */


// UART Control and Status Register A
struct
{
    bool MPCM;  // Multi Processor Communication Mode
    bool U2X;   // Double the UART Transmission Speed
    bool FRAME; // Reserve Frame bit (depends on ATMEGA always 0)
    bool OR;    // Over Run
    bool FE;    // Framing Error
    bool UDRE;  // UART Data Register Empty
    bool TXC;   // UART Transmission Complete
    bool RXC;   // UART Recieving Complete
} UCSRA;

// UART Control and Status Register B
struct 
{
    bool TXB8;          // Transmit Data bit 8
    bool RXB8;          // Recieve Data bit 8
    bool CHR9;          // 9 bit Characters
    bool TXEN;          // Transmission Enabled
    bool RXEN;          // Recieve Enabled
    bool UDRIE;         // UART Data Register Empty Interrupt Enable
    bool TXCIE;         // UART Transmission Complete Interrupt Enable
    bool RXCIE;         // UART Recieving Complete Interrupt Enable
} UCSRB;


/*
 * Pin Config
 */

struct 
{
    // Pin Layout Will be defined
    unsigned char pin : 4;
} PLAYOUT;

//   TODO
struct 
{
    bool serial;    // Serial or Parallel
    struct PLAYOUT * playout;   // Pin Layout
} UPIN;

/*
 * UART Config
 */

struct
{
    struct BCONFIG * bconfig;
    struct UCSRA * ucsra;
    struct UCSRB * ucsrb;
    struct UPIN * pcfg;
    // TODO UART PINS
} UARTCONFIG;


/*
 * UART Class
 */

class UART
{
    private:
        struct UARTCONFIG * ucf;    // UART Config
        // TX/RX pins
        unsigned long cpu_speed;    // cpu speed needed to calculate the comm
        char buffered = 0;  // buffered value
        bool serial_com;    // Defines either serial (2 pin) or parallel (multiple pins)
        bool read_en;       // check to see if read is enabled
        bool write_en;      // check to see if write is enabled
        bool frame_val;     // Start Frame Value
        uint8_t ubrr;       // UBRR (frequency delimiter)
        uint8_t ubrrh : 4;  // UBRRHI (high frequency delimiter)
    

    public:
        UART(struct UARTCONFIG * uc, const unsigned long cs);
        void init();                                        // Initialize variables and check overall config
        char read();                                        // read 
        char available();                                   // see if there is an available 
        int write(const char * str, unsigned int size);    // write bytes to the serial output
};


// Methods
struct UARTCONFIG * init_UART(struct BCONFIG * bc, struct UCSRA * ua, struct UCSRB * ub);   // 


#endif