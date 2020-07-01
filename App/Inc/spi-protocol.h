#ifndef INC_SPI_PROTOCOL_H_
#define INC_SPI_PROTOCOL_H_

// Standardní knihovny
#include <stdint.h>
#include <stdbool.h>
// App knihovny
#include "spi-driver.h"

typedef enum {
    SPI_CMD_UNKNOWN           = 0x00,
    SPI_CMD_MEASUREMENT_START = 0x01,
    SPI_CMD_MEASUREMENT_STOP  = 0x02,
    SPI_CMD_MEMORY_CLEAR      = 0x03,
    SPI_CMD_MEMORY_READ       = 0x04,
    SPI_CMD_GET_STATE         = 0x05
} spi_protocol_t;

void spi_cmd_start_measure(void);
void spi_cmd_stop_measure(void);
void spi_cmd_memory_read(uint16_t address, uint16_t size);
void spi_cmd_memory_clear(void);
uint8_t spi_cmd_get_state(void);

#endif/* INC_SPI_PROTOCOL_H_ */
