#ifndef INC_SPI_DRIVER_H_
#define INC_SPI_DRIVER_H_

// Standardní knihovny
#include <stdint.h>
// HAL knihovny
#include "stm32h7xx_hal.h"
// Core knihovny
#include "main.h"

#define SPI_BUFFER_SIZE 256 // velikost SPI bufferů

extern volatile uint8_t spi_buffer_tx[SPI_BUFFER_SIZE]; // Vysílací buffer.
extern volatile uint8_t spi_buffer_rx[SPI_BUFFER_SIZE]; // Přijímací buffer.

void spi_init(SPI_HandleTypeDef *hspi_p);
void spi_trx(uint32_t size);

#endif/* INC_SPI_DRIVER_H_ */
