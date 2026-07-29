#include <stdint.h>
#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "hal/gpio_ll.h"
#include "soc/gpio_periph.h"
#include "soc/gpio_struct.h"
#include "soc/io_mux_reg.h"

/* Conversion des millisecondes en ticks FreeRTOS */
#define DELAY(ms) vTaskDelay((ms) / portTICK_PERIOD_MS)

#define LED_PIN 32
#define WAIT 250

void app_main(void) {

  /* Configure le multiplexeur matériel pour assigner la broche à la fonction GPIO standard */
  gpio_ll_iomux_func_sel(GPIO_PIN_MUX_REG[LED_PIN], PIN_FUNC_GPIO);

  /* Active le buffer de sortie (Output) pour la broche LED_PIN */
  gpio_ll_output_enable(&GPIO, LED_PIN);
  /* Désactive le buffer d'entrée (Input) pour la broche LED_PIN */
  gpio_ll_input_disable(&GPIO, LED_PIN);

  while(1) {
    /* Met la broche LED_PIN à l'état logique HAUT (3.3V) */
    gpio_ll_set_level(&GPIO, LED_PIN, 1);
    DELAY(WAIT);
    /* Met la broche LED_PIN à l'état logique BAS (0V) */
    gpio_ll_set_level(&GPIO, LED_PIN, 0);
    DELAY(WAIT);
  }
}
