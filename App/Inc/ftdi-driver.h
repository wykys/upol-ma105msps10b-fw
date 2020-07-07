#ifndef INC_FTDI_DRIVER_H_
#define INC_FTDI_DRIVER_H_

// Standardní knihovny
#include <stdint.h>
// HAL knihovny
#include "stm32h7xx_hal.h"

void ftdi_init(UART_HandleTypeDef *huart_p, void (*callback_rx)(uint8_t));
void ftdi_tx_byte(uint8_t data);
void ftdi_tx_str(char *str);
uint8_t ftdi_rx_byte(void);
void ftdi_rx_byte_it(void);

#endif/* INC_FTDI_DRIVER_H_ */
