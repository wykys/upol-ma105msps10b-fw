#include "led-driver.h"

/**
 * Rozsvítí LED1.
 */
inline void led1_on(void)
{
    HAL_GPIO_WritePin(DEBUG_LED1_GPIO_Port, DEBUG_LED1_Pin, GPIO_PIN_SET);
}

/**
 * Rozsvítí LED2.
 */
inline void led2_on(void)
{
    HAL_GPIO_WritePin(DEBUG_LED2_GPIO_Port, DEBUG_LED2_Pin, GPIO_PIN_SET);
}

/**
 * Rozsvítí LED3.
 */
inline void led3_on(void)
{
    HAL_GPIO_WritePin(DEBUG_LED3_GPIO_Port, DEBUG_LED3_Pin, GPIO_PIN_SET);
}

/**
 * Rozsvítí LED4.
 */
inline void led4_on(void)
{
    HAL_GPIO_WritePin(DEBUG_LED4_GPIO_Port, DEBUG_LED4_Pin, GPIO_PIN_SET);
}

/**
 * Zhasne LED1.
 */
inline void led1_off(void)
{
    HAL_GPIO_WritePin(DEBUG_LED1_GPIO_Port, DEBUG_LED1_Pin, GPIO_PIN_RESET);
}

/**
 * Zhasne LED2.
 */
inline void led2_off(void)
{
    HAL_GPIO_WritePin(DEBUG_LED2_GPIO_Port, DEBUG_LED2_Pin, GPIO_PIN_RESET);
}

/**
 * Zhasne LED3.
 */
inline void led3_off(void)
{
    HAL_GPIO_WritePin(DEBUG_LED3_GPIO_Port, DEBUG_LED3_Pin, GPIO_PIN_RESET);
}

/**
 * Zhasne LED4.
 */
inline void led4_off(void)
{
    HAL_GPIO_WritePin(DEBUG_LED4_GPIO_Port, DEBUG_LED4_Pin, GPIO_PIN_RESET);
}

/**
 * Obrátí stav LED1.
 */
inline void led1_toggle(void)
{
    HAL_GPIO_TogglePin(DEBUG_LED1_GPIO_Port, DEBUG_LED1_Pin);
}

/**
 * Obrátí stav LED2.
 */
inline void led2_toggle(void)
{
    HAL_GPIO_TogglePin(DEBUG_LED2_GPIO_Port, DEBUG_LED2_Pin);
}

/**
 * Obrátí stav LED3.
 */
inline void led3_toggle(void)
{
    HAL_GPIO_TogglePin(DEBUG_LED3_GPIO_Port, DEBUG_LED3_Pin);
}

/**
 * Obrátí stav LED3.
 */
inline void led4_toggle(void)
{
    HAL_GPIO_TogglePin(DEBUG_LED4_GPIO_Port, DEBUG_LED4_Pin);
}
