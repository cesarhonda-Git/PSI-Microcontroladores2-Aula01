#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define SLEEP_TIME_MS 500

// Define o LED usando Device Tree
#define verde DT_ALIAS(led0)
#define azul DT_ALIAS(led1)

// Verifica se o LED está definido no Device Tree

static const struct gpio_dt_spec verde = GPIO_DT_SPEC_GET(verde, gpios);
static const struct gpio_dt_spec azul = GPIO_DT_SPEC_GET(azul, gpios);


int main(void)
{
    int g,b;
    g = gpio_pin_configure_dt(&verde, GPIO_OUTPUT_ACTIVE);
    b = gpio_pin_configure_dt(&azul, GPIO_OUTPUT_ACTIVE);

    while (1) {
        gpio_pin_toggle_dt(&azul);
        k_msleep(SLEEP_TIME_MS);
        
        gpio_pin_toggle_dt(&azul);
        gpio_pin_toggle_dt(&verde);
        k_msleep(SLEEP_TIME_MS);
    }
}