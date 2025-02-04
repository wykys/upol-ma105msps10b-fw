#ifndef INC_APP_INIT_H_
#define INC_APP_INIT_H_

// Standardní knihovny
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
// HAL knihovny
#include "stm32h7xx_hal.h"
// Core knihovny
#include "main.h"
#include "spi.h"
#include "usart.h"
// App knihovny
#include "clock-driver.h"
#include "led-driver.h"
#include "spi-driver.h"
#include "spi-protocol.h"
#include "ftdi-driver.h"
#include "app-superloop.h"

void app_init(void);

#endif/* INC_APP_INIT_H_ */
