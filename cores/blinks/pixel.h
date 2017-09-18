/*
 * ir_comms.h
 *
 * All the functions for communication and waking on the 6 IR LEDs on the tile edges.
 *
 */ 

#ifndef RGB_PIXELS_H_
#define RGB_PIXELS_H_

#include <avr/io.h>

// True today, but could imagine a blinks with 1 pixel or one with with 18 pixels...

#define PIXEL_COUNT FACE_COUNT

// Setup pins, interrupts. Call once at power up.

void pixel_init(void);

// Enable pixels after a call to pixel_init or pixel_disable
// Pixels will return to the color they had before being disabled.

void pixel_enable(void);

// Turn of all pixels and the timer that drives them.
// You'd want to do this before going to sleep.

void pixel_disable(void);
        
/** Display interface ***/

// Set a single pixel's RGB value
// p is the pixel number. 0 < p < PIXEL_COUNT
// r,g,b are brightness values. 0=off, 255=full brightness

// Note that there will likely be fewer than 256 actual visible values, but the mapping will be linear and smooth

// TODO: Balance, normalize, power optimize, and gamma correct these functions
// Need some exponential compression at the top here
// Maybe look up tables to make all calculations be one step at the cost of memory?

void pixel_setRGB( uint8_t p, uint8_t r, uint8_t g, uint8_t b );

void pixel_SetAllRGB( uint8_t r, uint8_t g, uint8_t b  );
    
#endif /* RGB_PIXELS_H_ */