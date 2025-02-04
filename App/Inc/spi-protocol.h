#ifndef INC_SPI_PROTOCOL_H_
#define INC_SPI_PROTOCOL_H_

// Standardní knihovny
#include <stdint.h>
#include <stdbool.h>
// App knihovny
#include "spi-driver.h"

typedef enum {
    SPI_CMD_UNKNOWN           = 0x00,
    SPI_CMD_STOP              = 0x01,
    SPI_CMD_GET_STATE         = 0x02,
    SPI_CMD_MEMORY_ERASE      = 0x03,
    SPI_CMD_MEMORY_READ       = 0x04,
    SPI_CMD_MEASUREMENT_START = 0x05,
    SPI_CMD_SET_RISING_LEVEL  = 0x06,
    SPI_CMD_SET_FALLING_LEVEL = 0x07
} spi_protocol_t;

typedef enum {
    SPI_DEV_STATE_READY       = 0x00,
    SPI_DEV_STATE_READ        = 0x01,
    SPI_DEV_STATE_ERASE       = 0x02,
    SPI_DEV_STATE_MEASUREMENT = 0x03
} spi_state_t;


void spi_cmd_stop(void);
uint8_t spi_cmd_get_state(void);
void spi_cmd_memory_erase(void);
void spi_cmd_memory_read(uint16_t address, uint16_t size);
void spi_cmd_measurement_start(void);
void spi_set_rising_level(uint16_t level);
void spi_set_falling_level(uint16_t level);

#endif/* INC_SPI_PROTOCOL_H_ */
