#ifndef INC_LED_DRIVER_H_
#define INC_LED_DRIVER_H_

// HAL knihovny
#include "stm32h7xx_hal.h"
// Core knihovny
#include "main.h"

void led1_on(void);
void led2_on(void);
void led3_on(void);
void led4_on(void);

void led1_off(void);
void led2_off(void);
void led3_off(void);
void led4_off(void);

void led1_toggle(void);
void led2_toggle(void);
void led3_toggle(void);
void led4_toggle(void);

#endif/* INC_LED_DRIVER_H_ */
