#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

// Define o LED usando Device Tree
#define led_verde DT_ALIAS(led0)
#define led_azul DT_ALIAS(led1)

// Verifica se o LED está definido no Device Tree

static const struct gpio_dt_spec verde = GPIO_DT_SPEC_GET(led_verde, gpios);
static const struct gpio_dt_spec azul = GPIO_DT_SPEC_GET(led_azul, gpios);

int main(void)
{
    int g,b;
    g = gpio_pin_configure_dt(&verde, GPIO_OUTPUT_ACTIVE);
    b = gpio_pin_configure_dt(&azul, GPIO_OUTPUT_ACTIVE);
    gpio_pin_toggle_dt(&azul);
    gpio_pin_toggle_dt(&verde);

    while (1) {

        k_msleep(350);
        gpio_pin_toggle_dt(&azul);

        k_msleep(650);
        gpio_pin_toggle_dt(&verde);

    }
}