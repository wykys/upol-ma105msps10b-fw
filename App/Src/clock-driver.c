#include "clock-driver.h"

/**
 * Povolení výstupu oscilátoru,
 * který je zdrojem hodin pro ADC a FPGA.
 */
inline void oscilator_on(void)
{
    HAL_GPIO_WritePin(OSC_OE_GPIO_Port, OSC_OE_Pin, GPIO_PIN_SET);
}

/**
 * Deaktivování výstupu oscilátoru.
 */
inline void oscilator_off(void)
{
    HAL_GPIO_WritePin(OSC_OE_GPIO_Port, OSC_OE_Pin, GPIO_PIN_RESET);
}