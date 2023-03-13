#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#define LED_PIN 16
#define LDR_PIN 27

int main() {
    // Initialize LED and LDR pins
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    adc_init();
    adc_gpio_init(LDR_PIN);
    adc_select_input(1);

    while (1) {
        // Read LDR value
        uint16_t ldr_value = adc_read();

        // Turn on LED if LDR value is below a certain threshold
        if (ldr_value < 1000) {
            gpio_put(LED_PIN, 1);
        } else {
            gpio_put(LED_PIN, 0);
        }

        // Delay for a short time before reading again
        sleep_ms(100);
    }
    return 0;
}