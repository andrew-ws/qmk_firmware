#ifndef SOFT_SERIAL_H
#define SOFT_SERIAL_H

#include <stdbool.h>

/* TODO:  some defines for interrupt setup */
#define SERIAL_PIN_DDR DDRD
#define SERIAL_PIN_PORT PORTD
#define LED_PIN_PORT PORTB
#define SERIAL_PIN_INPUT PIND
#define SERIAL_PIN_MASK _BV(PD0)
#define LED_PIN_MASK _BV(PB0)
#define SERIAL_PIN_INTERRUPT INT0_vect

// Soft Serial Transaction Descriptor
typedef struct _SSTD_t  {
    uint8_t *status;
    uint8_t initiator2target_buffer_size;
    uint8_t *initiator2target_buffer;
    uint8_t target2initiator_buffer_size;
    uint8_t *target2initiator_buffer;
} SSTD_t;
#define TID_LIMIT( table ) (sizeof(table) / sizeof(SSTD_t))

// initiator is transaction start side
void soft_serial_initiator_init(SSTD_t *sstd_table, int sstd_table_size);
// target is interrupt accept side
void soft_serial_target_init(SSTD_t *sstd_table, int sstd_table_size);

// initiator resullt
#define TRANSACTION_END 0
#define TRANSACTION_NO_RESPONSE 0x1
#define TRANSACTION_DATA_ERROR  0x2
#define TRANSACTION_TYPE_ERROR  0x4
#ifndef SERIAL_USE_MULTI_TRANSACTION
int  soft_serial_transaction(void);
#else
int  soft_serial_transaction(int sstd_index);
#endif

// target status
// *SSTD_t.status has
//   initiator:
//       TRANSACTION_END
//    or TRANSACTION_NO_RESPONSE
//    or TRANSACTION_DATA_ERROR
//   target:
//       TRANSACTION_DATA_ERROR
//    or TRANSACTION_ACCEPTED
#define TRANSACTION_ACCEPTED 0x8
#ifdef SERIAL_USE_MULTI_TRANSACTION
int  soft_serial_get_and_clean_status(int sstd_index);
#endif

#endif /* SOFT_SERIAL_H */
