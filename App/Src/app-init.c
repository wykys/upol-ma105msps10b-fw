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

    HAL_Delay(1000);


    led1_on();

    for (uint32_t i = 0; i < SPI_BUFFER_SIZE; i++)
    {
        spi_buffer_tx[i] = 0;
        spi_buffer_rx[i] = 0;
    }

    while (true)
    {
        led2_toggle();
        spi_cmd_get_state();
        spi_cmd_start_measure();
        while (!spi_cmd_get_state());
        spi_cmd_memory_read(0, 10);
    }
} /* app_init */
