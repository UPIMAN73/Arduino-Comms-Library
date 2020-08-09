#ifndef PACKET__H__
#define PACKET__H__
#include "general.h"

// Start and Stop frame values
struct
{
    bool frame;     // for boolean values
    char cframe;    // for single character values
    string sframe;  // for string values
    uint8_t uframe; // for unsigned values from (0-255)
} StartValue;

struct
{
    bool frame;     // for boolean values
    char cframe;    // for single character values
    string sframe;  // for string values
    uint8_t uframe; // for unsigned values from (0-255)
} StopValue;

/*
 * Packet Class 
 * 
 * @desc 
 * Is a generic class that can be redefined and or managed
 * by the developer/user. 
 * The main point for using this class is its debug ability.
 * You can easily see the messages, contents, and formulation 
 * to then use a root cause analysis and find the problem.
 * It can also be used for general packet usage.
 * You have to use OOP or polymorphism in order for the debug
 * setup to work properly.
 * 
 */

class Packet
{
    private:
        struct StartValue * start;  // start value (ie. header)
        struct StopValue * stop;    // stop value  (ie. footer)
        string body;                // Body value or what the message is
        uint16_t size;              // Size of Packet in total (start, body, stop)

    public:
    Packet();   // simple packet description
    ~Packet();  // destruct the packet

    
    virtual bool * toBinary() = 0;              // convert packet details to binary for binary operations
    virtual string packetBreakout() = 0;        // Packet Breakout Text for Debugging
    virtual struct StartValue * getStart() = 0; // Get Start Packet Value type
    virtual struct StopValue * getStop() = 0;   // Get Stop Packet Value type
};

#endif