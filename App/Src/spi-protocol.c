#include "spi-protocol.h"

/**
 * Zahájení měření.
 */
inline void spi_cmd_measurement_start(void)
{
    spi_buffer_tx[0] = SPI_CMD_MEASUREMENT_START;
    spi_trx(1);
}

/**
 * Zastavení měření.
 */
inline void spi_cmd_stop(void)
{
    spi_buffer_tx[0] = SPI_CMD_STOP;
    spi_trx(1);
}

/**
 * Čtení ze SRAM.
 * @param address - počáteční adresa
 * @param size - počet addres, které mají být přečteny
 */
inline void spi_cmd_memory_read(uint16_t address, uint16_t size)
{
    spi_buffer_tx[0] = SPI_CMD_MEMORY_READ;
    spi_buffer_tx[1] = (address & 0xFF00) >> 8;
    spi_buffer_tx[2] = address & 0xFF;
    spi_trx(1 + 2 + size * 2); // 1B cmd 2B addr, size * data 2B.
}

/**
 * Smaže obsah SRAM zapsanám 0 do
 * celého adresního rozsahu paměti.
 */
inline void spi_cmd_memory_erase(void)
{
    spi_buffer_tx[0] = SPI_CMD_MEMORY_ERASE;
    spi_trx(1);
}

/**
 * Vyčte stav zařízení.
 * @retval hodnota odpovídající stavu zařízení definovaného v spi_state_t.
 */
inline uint8_t spi_cmd_get_state(void)
{
    spi_buffer_tx[0] = SPI_CMD_GET_STATE;
    spi_trx(2);
    return spi_buffer_rx[1];
}

/**
 * Nastaví komparační úroveň pro náběžnou hranu.
 * @param level prahová úroveň.
 */
inline void spi_set_rising_level(uint16_t level)
{
    spi_buffer_tx[0] = SPI_CMD_SET_RISING_LEVEL;
    spi_buffer_tx[1] = (level >> 8) & 0xFF;
    spi_buffer_tx[2] = level & 0xFF;
    spi_trx(3);
}

/**
 * Nastaví komparační úroveň pro náběžnou sestupnou hranu.
 * @param level prahová úroveň.
 */
inline void spi_set_falling_level(uint16_t level)
{
    spi_buffer_tx[0] = SPI_CMD_SET_FALLING_LEVEL;
    spi_buffer_tx[1] = (level >> 8) & 0xFF;
    spi_buffer_tx[2] = level & 0xFF;
    spi_trx(3);
}
