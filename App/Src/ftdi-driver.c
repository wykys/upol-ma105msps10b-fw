#include "ftdi-driver.h"

typedef struct {
    UART_HandleTypeDef *huart_p;
    uint8_t             buffer_rx;
    void (*callback_rx)(uint8_t);
}
ftdi_config_t;

volatile ftdi_config_t ftdi_config;

/**
 * Inicializace ovladače FTDI.
 * @param huart_p ukazatel na HAL UART strukturu.
 * @param callback_rx - ukazatel na funkci která bude zavolána při příjmu dat.
 */
void ftdi_init(UART_HandleTypeDef *huart_p, void (*callback_rx)(uint8_t))
{
    ftdi_config.huart_p = huart_p;
    ftdi_config.callback_rx = callback_rx;
    ftdi_rx_byte_it();
}

/**
 * Odešle jeden bajt.
 * @param data co budou přenesena.
 */
inline void ftdi_tx_byte(uint8_t data)
{
    HAL_UART_Transmit(ftdi_config.huart_p, &data, 1, HAL_UART_TIMEOUT_VALUE);
}

/**
 * Odešle řetězec.
 * @param str ukazatel na začátek řetězce.
 */
inline void ftdi_tx_str(char *str)
{
    uint32_t size;
    for (size = 0; str[size]; size++)
        ;
    HAL_UART_Transmit(ftdi_config.huart_p, (uint8_t *) str, size, HAL_UART_TIMEOUT_VALUE);
}

/**
 * Přijde jeden byte.
 * @retval přijatý byte.
 */
inline uint8_t ftdi_rx_byte(void)
{
    HAL_UART_Receive(ftdi_config.huart_p, (uint8_t *) &ftdi_config.buffer_rx, 1, HAL_UART_TIMEOUT_VALUE);
    return ftdi_config.buffer_rx;
}

/**
 * Zahájí příjem s přerušením.
 */
inline void ftdi_rx_byte_it(void)
{
    HAL_UART_Receive_IT(ftdi_config.huart_p, (uint8_t *) &ftdi_config.buffer_rx, 1);
}

/**
 * Pokud nastala chyba v komunikaci,
 * opět zahájím příjem.
 */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart_p)
{
    ftdi_rx_byte_it();
}

/**
 * Pokud jsme přijal data,
 * přijímám dál.
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    ftdi_config.callback_rx(ftdi_config.buffer_rx);
    ftdi_rx_byte_it();
}
