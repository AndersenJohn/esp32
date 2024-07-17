#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/adc.h"

#define X_PIN ADC1_CHANNEL_32  // X 軸連接到 ADC1 的第 32 通道
#define Y_PIN ADC1_CHANNEL_35  // Y 軸連接到 ADC1 的第 35 通道

void setup_adc() {
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(X_PIN, ADC_ATTEN_DB_11);
    adc1_config_channel_atten(Y_PIN, ADC_ATTEN_DB_11);
}

void read_joystick_values() {
    int x_val = adc1_get_raw(X_PIN);
    int y_val = adc1_get_raw(Y_PIN);

    printf("X axis value: %d\n", x_val);
    printf("Y axis value: %d\n", y_val);
}

void app_main() {
    setup_adc();

    while (1) {
        read_joystick_values();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
