#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

// Define o LED usando Device Tree
#define led_verde DT_ALIAS(led0)
#define led_azul DT_ALIAS(led1)

#define STACK_SIZE 1024
#define PRIORITY 5
//atualizado

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
https://github.com/isaak-nunes/Baremetal/pull/4/conflict?name=src%252Fmain.c&ancestor_oid=e6a5f3f1d691a496fe4dbd728716955051b4ee42&base_oid=f5d0410a76635c2d7b9c17cbdc953b4d272a0ba6&head_oid=7c64e3b3cfd3e26b0d3a4ade4be03d0ac749dd2b
    // Configura o pino como saída
    ret = gpio_pin_configure_dt(&led_verde, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        printk("Error %d: failed to configure LED pin\n", ret);
        return;
    }

    // Configura o pino do LED azul como saída
    ret = gpio_pin_configure_dt(&led_azul, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        printk("Error %d: failed to configure Blue LED pin\n", ret);
        return;
    }


    printk("LED verde blinking on %s pin %d\n", led_verde.port->name, led_verde.pin);

    printk("LED azul blinking on %s pin %d\n", led_azul.port->name, led_azul.pin);

k_thread_create(&data_azul, stack_azul, K_THREAD_STACK_SIZEOF(stack_azul),
                    thread_led_azul, NULL, NULL, NULL,
                    PRIORITY, 0, K_NO_WAIT);
k_thread_create(&data_verde, stack_verde, K_THREAD_STACK_SIZEOF(stack_verde),
                    thread_led_verde, NULL, NULL, NULL,
                    PRIORITY, 0, K_NO_WAIT);

}