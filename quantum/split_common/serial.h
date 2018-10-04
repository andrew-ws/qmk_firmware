#ifndef MY_SERIAL_H
#define MY_SERIAL_H

#include "config.h"
#include <stdbool.h>

/* TODO:  some defines for interrupt setup */
#define SERIAL_PIN_DDR DDRD
#define SERIAL_PIN_PORT PORTD
#define LED_PIN_PORT PORTB
#define SERIAL_PIN_INPUT PIND
#define SERIAL_PIN_MASK _BV(PD0)
#define LED_PIN_MASK _BV(PB0)
#define SERIAL_PIN_INTERRUPT INT0_vect

#define SERIAL_SLAVE_BUFFER_LENGTH MATRIX_ROWS/2
#define SERIAL_MASTER_BUFFER_LENGTH 1

// Address location defines 
#define SERIAL_BACKLIT_START   0x00

// Buffers for master - slave communication
extern volatile uint8_t serial_slave_buffer[SERIAL_SLAVE_BUFFER_LENGTH];
extern volatile uint8_t serial_master_buffer[SERIAL_MASTER_BUFFER_LENGTH];

void serial_master_init(void);
void serial_slave_init(void);
int serial_update_buffers(void);
bool serial_slave_data_corrupt(void);

#endif
