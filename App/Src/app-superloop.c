#include "app-superloop.h"

typedef enum {
    CMD_UNKNOW,
    CMD_START,
    CMD_CLEAR
} cmd_t;

volatile cmd_t cmd;
volatile bool flag_new_command;

/**
 * Zpracovává přijímaná data z UARTu a dekóduje příkazy.
 */
inline void uart_command_decoder(uint8_t data)
{
    static uint8_t buffer[42];
    static uint8_t i = 0;

    if (data == '\n' || data == '\r')
    {
        flag_new_command = true;
        buffer[i]        = 0;
        i = 0;
        if (!strcmp((const char *) buffer, "MEASUREMENT START"))
        {
            cmd = CMD_START;
        }
        else if (!strcmp((const char *) buffer, "MEMORY CLEAR"))
        {
            cmd = CMD_CLEAR;
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
}

/**
 * Hlavní aplikační nekoneční smyčka.
 */
void app_superloop(void)
{
    flag_new_command = false;

    while (true)
    {
        led2_on();
        while (!flag_new_command)
            ;
        flag_new_command = false;
        led2_off();

        switch (cmd)
        {
            case CMD_START:
                ftdi_cmd_ok();
                led3_on();
                spi_cmd_start_measure();
                while (!spi_cmd_get_state())
                    ;
                spi_cmd_memory_read(0, 1024);
                spi_cmd_stop();
                led3_off();

                led4_on();
                ftdi_cmd_data_begin();
                for (uint16_t i = 0; i < 1024; i++)
                {
                    uint8_t data_h = spi_buffer_rx[3 + i * 2];
                    uint8_t data_l = spi_buffer_rx[4 + i * 2];
                    uint16_t data  = (((uint16_t) data_h) << 8) | data_l;
                    ftdi_cmd_data(data);
                }
                ftdi_cmd_data_end();
                led4_off();
                break;

            case CMD_CLEAR:
                ftdi_cmd_ok();
                spi_cmd_memory_clear();
                break;

            default:
                ftdi_cmd_error();
                break;
        }
    }
} /* app_superloop */
