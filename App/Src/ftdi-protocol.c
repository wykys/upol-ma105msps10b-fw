#include "ftdi-protocol.h"

/**
 * Příkaz pro odpověď na korektní vstup,
 * pokud nejsou poslána data.
 */
inline void ftdi_cmd_ok(void)
{
    ftdi_cmd("OK");
}

/**
 * Příkaz pro odpověď na nekorektní vstup.
 */
inline void ftdi_cmd_error(void)
{
    ftdi_cmd("ERROR");
}

/**
 * Začátek bloku dat.
 */
inline void ftdi_cmd_data_begin(void)
{
    ftdi_cmd("DATA BEGIN");
}

/**
 * Konec bloku dat.
 */
inline void ftdi_cmd_data_end(void)
{
    ftdi_cmd("DATA END");
}

/**
 * Převede data na řetězec, který jeodelán,
 * ve formátu příkazu.
 * @param data která budou odeslána.
 */
void ftdi_cmd_data(uint32_t data)
{
    char str[11];
    sprintf(str, "%u"FTDI_EOL, (unsigned int) data);
    ftdi_tx_str(str);
}

/**
 * Odešle stav zařízení.
 * @param state satav je definován v spi_state_t.
 */
inline void ftdi_cmd_get_state(uint8_t state)
{
    switch (state)
    {
        case SPI_DEV_STATE_READ:
            ftdi_cmd("READ");
            break;

        case SPI_DEV_STATE_ERASE:
            ftdi_cmd("ERASE");
            break;

        case SPI_DEV_STATE_MEASUREMENT:
            ftdi_cmd("MEASUREMENT");
            break;

        default:
            ftdi_cmd("READY");
            break;
    }
}
