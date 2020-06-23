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

    for (uint32_t i = 0; i < SPI_BUFFER_SIZE; i++)
    {
        spi_buffer_tx[i] = i+1;
    }

    while (true)
    {
        led1_toggle();
        spi_trx(33);
        HAL_Delay(1);
    }
}
