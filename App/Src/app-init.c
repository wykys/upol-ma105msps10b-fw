#include "app-init.h"

/**
 * Funkce kretá inicializuje aplikaci.
 * Měla by být zavolána ve funkci main,
 * jako první uživatleká funkce po
 * inicializaci HAL knihoven.
 */
void app_init(void)
{
    oscilator_on();
    spi_init(&hspi4);
    ftdi_init(&huart1, uart_command_decoder);

    HAL_Delay(1000);


    led1_on();

    for (uint32_t i = 0; i < SPI_BUFFER_SIZE; i++)
    {
        spi_buffer_tx[i] = 0;
        spi_buffer_rx[i] = 0;
    }

    spi_set_rising_level(600);
    spi_set_falling_level(600);

    app_superloop();
}
