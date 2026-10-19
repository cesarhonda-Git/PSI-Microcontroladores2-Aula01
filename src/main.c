#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define tempo 500

// Define o LED usando Device Tree
#define verde DT_ALIAS(led0)
#define azul DT_ALIAS(led1)

// Verifica se o LED está definido no Device Tree

static const struct gpio_dt_spec green = GPIO_DT_SPEC_GET(verde, gpios);
static const struct gpio_dt_spec blue = GPIO_DT_SPEC_GET(azul, gpios);

#define STACK_SIZE 1024
#define PRIORITY 5

void minha_thread(void)
{
    while (1) {
        gpio_pin_toggle_dt(&blue);
        k_msleep(1000);
    }
}

void gustavo(void)
{
    while (1) {
        gpio_pin_toggle_dt(&green);
        k_msleep(350);
    }
}

// Criar a thread
K_THREAD_DEFINE(minha_thread_id, 512, minha_thread, NULL, NULL, NULL, 7, 0, 0);
K_THREAD_DEFINE(rehder, 512, gustavo, NULL, NULL, NULL, 6, 0, 0);

int main(void)
{
        int g, b;

   g = gpio_pin_configure_dt(&green, GPIO_OUTPUT_ACTIVE);
    b = gpio_pin_configure_dt(&blue, GPIO_OUTPUT_ACTIVE);
    
    while (1) {
        k_msleep(2000);
    }
}