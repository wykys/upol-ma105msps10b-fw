#include "spi-protocol.h"

/**
 * Zahájení měření.
 */
void spi_cmd_start_measure(void)
{
    spi_buffer_tx[0] = SPI_CMD_MEASUREMENT_START;
    spi_trx(1);
}

/**
 * Zastavení měření.
 */
void spi_cmd_stop(void)
{
    spi_buffer_tx[0] = SPI_CMD_STOP;
    spi_trx(1);
}

/**
 * Čtení ze SRAM.
 * @param address - počáteční adresa
 * @param size - počet addres, které mají být přečteny
 */
void spi_cmd_memory_read(uint16_t address, uint16_t size)
{
    // TODO: dodělat kontrolu adresního rozsahu!
    spi_buffer_tx[0] = SPI_CMD_MEMORY_READ;
    spi_buffer_tx[1] = (address & 0xFF00) >> 8;
    spi_buffer_tx[2] = address & 0xFF;
    spi_trx(1 + 2 + size * 2); // 1B cmd 2B addr, size * data 2B.
}

/**
 * Zmače obsah SRAM zapsanám 0 do
 * celého adresního rozsahu paměti.
 */
void spi_cmd_memory_clear(void)
{
    spi_buffer_tx[0] = SPI_CMD_MEMORY_CLEAR;
    spi_trx(1);
}

/**
 * Vyčte stav zařízení.
 * @retval 0x00 - zaneprázdněno
 *         0x01 - připraveno
 */
uint8_t spi_cmd_get_state(void)
{
    spi_buffer_tx[0] = SPI_CMD_GET_STATE;
    spi_trx(2);
    return spi_buffer_rx[1];
}
