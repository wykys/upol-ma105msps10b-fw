#ifndef INC_APP_SUPERLOOP_H_
#define INC_APP_SUPERLOOP_H_

// Standardní knihovny
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
// HAL knihovny
#include "stm32h7xx_hal.h"
// App knihovny
#include "clock-driver.h"
#include "led-driver.h"
#include "spi-driver.h"
#include "spi-protocol.h"
#include "ftdi-driver.h"
#include "ftdi-protocol.h"

void app_superloop(void);
void uart_command_decoder(uint8_t data);

#endif/* INC_APP_SUPERLOOP_H_ */
