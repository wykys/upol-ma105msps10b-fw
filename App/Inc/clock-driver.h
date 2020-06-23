#ifndef INC_CLOCK_DRIVER_H_
#define INC_CLOCK_DRIVER_H_

#include <stdint.h>
#include <stdbool.h>
#include "stm32h7xx_hal.h"

#include "main.h"

void oscilator_on(void);
void oscilator_off(void);

#endif/* INC_CLOCK_DRIVER_H_ */
