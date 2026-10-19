//versão 4.2


#include <zephyr/kernel.h>             // Funções básicas do Zephyr (ex: k_msleep, k_thread, etc.)
#include <zephyr/device.h>             // API para obter e utilizar dispositivos do sistema
#include <zephyr/drivers/gpio.h>       // API para controle de pinos de entrada/saída (GPIO)

#include <math.h>                      //livraria de operações matematicas padrão
#include <pwm_z42.h>                   //biblioteca do pulse width module


void setup(void) { //pois quanto menor o main, melhor!
    //sensorUltrassonicoInit();

    //iniciação do clock da porta (eu acho)

    pwm_tpm_Init(TPM0, TPM_PLLFLL, 100, TPM_CLK, PS_128, EDGE_PWM);
    pwm_tpm_Init(TPM2, TPM_PLLFLL, 1000, TPM_CLK, PS_128, EDGE_PWM);

        pwm_tpm_Ch_Init(TPM2, 0, TPM_PWM_H, GPIOB, 18); //led vermelho
        pwm_tpm_Ch_Init(TPM2, 1, TPM_PWM_H, GPIOB, 19); //led verde
        pwm_tpm_Ch_Init(TPM0, 1, TPM_PWM_H, GPIOD, 1);

}

int main (void)
{
    int p=20;
    setup();

    while (1) {

        pwm_tpm_CnV(TPM2, 1, 2000);
        pwm_tpm_CnV(TPM2, 0, 1000);
        pwm_tpm_CnV(TPM0, 1, 0);

        k_msleep(p);
        pwm_tpm_CnV(TPM2, 1, 2000);
        pwm_tpm_CnV(TPM2, 0, 0);
        pwm_tpm_CnV(TPM0, 1, 2000);

        k_msleep(p);
        pwm_tpm_CnV(TPM2, 1, 0);
        pwm_tpm_CnV(TPM2, 0, 2000);
        pwm_tpm_CnV(TPM0, 1, 2000);

        k_msleep(p);
   }
}