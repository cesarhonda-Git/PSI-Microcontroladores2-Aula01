#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define tempo 500

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
    gpio_pin_toggle_dt(&azul);
    gpio_pin_toggle_dt(&verde);

    while (1) {

        k_msleep(tempo);
        gpio_pin_toggle_dt(&azul);
        gpio_pin_toggle_dt(&verde);
        k_msleep(10);
        gpio_pin_toggle_dt(&azul);
        gpio_pin_toggle_dt(&verde);
        k_msleep(tempo);
        gpio_pin_toggle_dt(&verde);
        k_msleep(10);
        gpio_pin_toggle_dt(&verde);
    }
}