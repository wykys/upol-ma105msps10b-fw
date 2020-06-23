#include "app-init.h"

void app_init(void)
{
    oscilator_on();

    while(true)
    {
        led1_toggle();
        HAL_Delay(100);
    }
}