#include <stdio.h>          //biblioteca padrãino da linguagem C
#include "pico/stdlib.h"    //subconjunto central de bibliotecas do SDK Pico
#include "pico/time.h"      //biblioteca para gerenciamento de tempo
#include "hardware/irq.h"   //biblioteca para gerenciamento de interrupções
#include "hardware/pwm.h"   //biblioteca para controlar o hardware de PWM

#define Robot_PIN 22        //pino do LED conectado a GPIO como PWM
#define frequencia_PWM 50   //definição da frequência em 50Hz
#define periodo_PWM 20000   //definição do período de 200ms

void set_robot_move(uint gpio, uint16_t pulse_width_us) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    uint16_t level = (pulse_width_us * 39062) / periodo_PWM;
    pwm_set_gpio_level(gpio, level);
}

int main() 
{
    stdio_init_all();
    
    gpio_set_function(Robot_PIN, GPIO_FUNC_PWM);        // Habilita o pino para PWM
    uint slice_num = pwm_gpio_to_slice_num(Robot_PIN); // Obtemos o "slice" do GPIO

    pwm_set_clkdiv(slice_num, 64.0f); // Divisor de clock float para garantir a frequência de 50Hz
    pwm_set_wrap(slice_num, 39062);   // Define o número de contagens necessárias para gerar um ciclo de 20ms.
    pwm_set_enabled(slice_num, true); // Habilita o PWM no pino

    while (true) 
    {
        printf("Posicionando o servo a 0 graus\n");
        set_robot_move(Robot_PIN, 500); // 0 graus
        sleep_ms(5000);

        printf("Posicionando o servo a 90 graus\n");
        set_robot_move(Robot_PIN, 1500); // 90 graus
        sleep_ms(5000);

        printf("Posicionando o servo a 180 graus\n");
        set_robot_move(Robot_PIN, 2400); // 180 graus
        sleep_ms(5000);

        for(uint16_t soft = 2400; soft >= 500; soft -= 5) //movimento suave de baixo para cima 
        {
            set_robot_move(Robot_PIN, soft);
            sleep_ms(10);
        }
        for(uint16_t soft = 500; soft <= 2400; soft += 5) //movimento suave de cima para baixo
        {
            set_robot_move(Robot_PIN, soft);
            sleep_ms(10);
        }
    }
}