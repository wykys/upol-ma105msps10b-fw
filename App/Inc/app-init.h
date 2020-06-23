#ifndef INC_APP_INIT_H_
#define INC_APP_INIT_H_

#include <stdint.h>
#include <stdbool.h>
#include "stm32h7xx_hal.h"

#include "main.h"

#include "clock-driver.h"
#include "led-driver.h"

void app_init(void);

#endif/* INC_APP_INIT_H_ */
