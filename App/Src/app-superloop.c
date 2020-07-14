#include "app-superloop.h"

typedef enum {
    CMD_UNKNOW,
    CMD_MEASUREMENT_START,
    CMD_MEASUREMENT_STOP,
    CMD_MEMORY_ERASE,
    CMD_MEMORY_READ,
    CMD_GET_STATE,
    CMD_SET_RISING_LEVEL,
    CMD_SET_FALLING_LEVEL
} cmd_t;

volatile cmd_t cmd;
volatile uint32_t tmp;
volatile bool flag_new_command;

/**
 * Dekóduje číslo v desítkové soustavě s řetězce.
 * @param str ukazatel na začátek řetezce.
 * @retval true - pokud je dekódování úspěšné, jinak false.
 */
inline bool decode_number(uint8_t *str)
{
    if (sscanf((const char *) str, "%u", (unsigned int *) &tmp) == 1)
    {
        return true;
    }
    return false;
}

/**
 * Zpracovává přijímaná data z UARTu a dekóduje příkazy.
 */
inline void uart_command_decoder(uint8_t data)
{
    static uint8_t buffer[42];
    static uint8_t i = 0;

    led2_toggle();
    if (data == '\n' || data == '\r')
    {
        flag_new_command = true;
        buffer[i]        = '\0';
        i = 0;
        if (!strcmp((const char *) buffer, "MEASUREMENT START"))
        {
            cmd = CMD_MEASUREMENT_START;
        }
        else if (!strcmp((const char *) buffer, "MEASUREMENT STOP"))
        {
            cmd = CMD_MEASUREMENT_STOP;
        }
        else if (!strcmp((const char *) buffer, "MEMORY ERASE"))
        {
            cmd = CMD_MEMORY_ERASE;
        }
        else if (!strcmp((const char *) buffer, "MEMORY READ"))
        {
            cmd = CMD_MEMORY_READ;
        }
        else if (!strcmp((const char *) buffer, "GET STATE"))
        {
            cmd = CMD_GET_STATE;
        }
        else if (!strncmp((const char *) buffer, "SET RISING LEVEL ", 17))
        {
            if (decode_number(&buffer[17]))
            {
                cmd = CMD_SET_RISING_LEVEL;
            }
            else
            {
                cmd = CMD_UNKNOW;
            }
        }
        else if (!strncmp((const char *) buffer, "SET FALLING LEVEL ", 18))
        {
            if (decode_number(&buffer[18]))
            {
                cmd = CMD_SET_FALLING_LEVEL;
            }
            else
            {
                cmd = CMD_UNKNOW;
            }
        }
        else
        {
            cmd = CMD_UNKNOW;
        }
    }
    else
    {
        buffer[i++] = data;
        if (i >= sizeof(buffer))
        {
            i = 0;
        }
    }
} /* uart_command_decoder */

/**
 * Hlavní aplikační nekoneční smyčka.
 */
void app_superloop(void)
{
    flag_new_command = false;

    while (true)
    {
        led3_on();
        while (!flag_new_command)
            ;
        flag_new_command = false;
        led3_off();

        led4_on();
        switch (cmd)
        {
            case CMD_GET_STATE:
                ftdi_cmd_ok();
                ftdi_cmd_get_state(spi_cmd_get_state());
                break;

            case CMD_MEASUREMENT_START:
                ftdi_cmd_ok();
                spi_cmd_measurement_start();
                break;

            case CMD_MEASUREMENT_STOP:
                ftdi_cmd_ok();
                spi_cmd_stop();
                break;

            case CMD_MEMORY_ERASE:
                ftdi_cmd_ok();
                spi_cmd_memory_erase();
                break;

            case CMD_MEMORY_READ:
                ftdi_cmd_ok();
                spi_cmd_memory_read(0, 1024);
                ftdi_cmd_data_begin();
                for (uint16_t i = 0; i < 1024; i++)
                {
                    uint8_t data_h = spi_buffer_rx[3 + i * 2];
                    uint8_t data_l = spi_buffer_rx[4 + i * 2];
                    uint16_t data  = (((uint16_t) data_h) << 8) | data_l;
                    ftdi_cmd_data(data);
                }
                ftdi_cmd_data_end();
                break;

            case CMD_SET_RISING_LEVEL:
                ftdi_cmd_ok();
                spi_set_rising_level(tmp & 0xFFFF);
                break;

            case CMD_SET_FALLING_LEVEL:
                ftdi_cmd_ok();
                spi_set_falling_level(tmp & 0xFFFF);
                break;

            default:
                ftdi_cmd_error();
                break;
        }
        led4_off();
    }
} /* app_superloop */
