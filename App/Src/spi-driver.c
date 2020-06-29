#include "spi-driver.h"

volatile uint8_t __attribute__((__section__(".RAM_D1"))) spi_buffer_tx[SPI_BUFFER_SIZE]; // Vysílací buffer.
volatile uint8_t __attribute__((__section__(".RAM_D1"))) spi_buffer_rx[SPI_BUFFER_SIZE]; // Přijímací buffer.

// Struktura pro stavové proměnné SPI driveru.
typedef struct {
    SPI_HandleTypeDef *hspi_p;
} spi_config_t;

// Stavové proměnné SPI driveru.
static volatile spi_config_t spi_config;

/**
 * Inicializace SPI ovladače.
 * @param hspi_p - ukazatel na HAL SPI strukturu.
 */
void spi_init(SPI_HandleTypeDef *hspi_p)
{
    spi_config.hspi_p = hspi_p;
}

/**
 * Obousměrná SPI komunikace s využitím  SPI bufferů.
 * @param size - velikost přenášených dat v byjtech.
 */
inline void spi_trx(uint32_t size)
{
    HAL_SPI_TransmitReceive_DMA(spi_config.hspi_p, (uint8_t *) spi_buffer_tx, (uint8_t *) spi_buffer_rx, size);
}

/**
 * Informace o připravensti SPI.
 * @retval true - pokud je SPI připraveno.
 */
inline bool spi_is_ready(void)
{
    return (bool) (spi_config.hspi_p->State == HAL_SPI_STATE_READY);
}
