![68747470733a2f2f736f667465782e62722f77702d636f6e74656e742f75706c6f6164732f323032342f30392f456d6261726361546563685f6c6f676f5f417a756c2d31303330783432382e706e67](https://github.com/user-attachments/assets/17efcf4f-14e6-4541-8d15-b8ddc99f7807)
## Controle de Servo Motor com PWM no RP2040

video desmonstrativo da atividade: https://www.dropbox.com/scl/fi/7uydv4zyqakc8ocosejwb/Atividade-de-PWM.mp4?rlkey=ceiu1f83vhbhlm47w2xb0eso6&st=9kw1rsr5&dl=0

Com o emprego do módulo PWM (do inglês, Pulse Width Modulation), presente no microcontrolador RP2040, este projeto visa simular o controle do ângulo de um servomotor utilizando a ferramenta Pico SDK. A simulação será realizada no simulador de eletrônica online Wokwi.

**Implementação**

1) Configuração da Frequência PWM
- Definir a GPIO 22 como saída PWM.
- Ajustar a frequência para aproximadamente 50Hz (período de 20ms).

2) Posição de 180 graus
- Definir o ciclo ativo do PWM para 2.400µs (duty cycle de 0,12%).
- Ajustar a flange do servomotor para 180 graus.
- Aguardar 5 segundos nesta posição.

3) Posição de 90 graus
- Definir o ciclo ativo do PWM para 1.470µs (duty cycle de 0,0735%).
- Ajustar a flange do servomotor para 90 graus.
- Aguardar 5 segundos nesta posição.

4) Posição de 0 graus
- Definir o ciclo ativo do PWM para 500µs (duty cycle de 0,025%).
- Ajustar a flange do servomotor para 0 graus.
- Aguardar 5 segundos nesta posição.

5) Movimento Suave entre 0 e 180 graus
- rotina para movimentar o servomotor periodicamente entre 0 e 180 graus.
- Movimentação suave, com incremento de ciclo ativo de ±5µs.
- Introduzir um atraso de 10ms a cada incremento.

6) Experimento com a Ferramenta BitDogLab
- Utilizar a Ferramenta Educacional BitDogLab.
- Testar o código utilizando um LED RGB conectado à GPIO 12.
- Observar e descrever o comportamento da iluminação do LED.
