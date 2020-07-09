#ifndef INC_FTDI_PROTOCOL_H_
#define INC_FTDI_PROTOCOL_H_

// Standardní knihovny
#include <stdint.h>
#include <stdio.h>
// App knihovny
#include "ftdi-driver.h"
#include "spi-protocol.h"

#define FTDI_EOL "\r\n"                         // Ukončení řádku.
#define ftdi_cmd(CMD) ftdi_tx_str(CMD FTDI_EOL) // Odeslání příkazu s korektním ukončením řádku.

void ftdi_cmd_ok(void);
void ftdi_cmd_error(void);
void ftdi_cmd_data_begin(void);
void ftdi_cmd_data_end(void);
void ftdi_cmd_data(uint32_t data);
void ftdi_cmd_get_state(uint8_t state);

#endif/* INC_FTDI_PROTOCOL_H_ */
