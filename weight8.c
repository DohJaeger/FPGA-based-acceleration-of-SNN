#include "main.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"
#include "stm32f1xx_hal.h"

UART_HandleTypeDef huart1;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USB_DEVICE_Init(void);

void Sort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART1_UART_Init();
    MX_USB_DEVICE_Init();

    float weightInKg[8] = {0};

    while (1)
    {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET); // PC13 HIGH
        CDC_Transmit_FS((uint8_t*)"passkey sending\r\n", 17);

        for (int idx = 0; idx < 8; idx++)
        {
            HAL_Delay(100);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET); // PA8 HIGH

            // configuer sensor
            char sensor_command[] = "S09;MSV?;";
            HAL_UART_Transmit(&huart1, (uint8_t*)sensor_command, strlen(sensor_command), HAL_MAX_DELAY);
            HAL_Delay(11);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET); // PA8 LOW
            HAL_Delay(10);

            uint8_t data[4];
            uint8_t discard;
            if (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE))
            {
                // raed 4 bytes of data
                for (int i = 3; i >= 0; i--)
                {
                    HAL_UART_Receive(&huart1, &data[i], 1, HAL_MAX_DELAY);
                }

                HAL_UART_Receive(&huart1, &discard, 1, HAL_MAX_DELAY);
                HAL_UART_Receive(&huart1, &discard, 1, HAL_MAX_DELAY);

                int weightValue = 0;
                int validlength = 4;
                if (data[3] == 0) validlength = 3;

                for (int j = 0; j < validlength; j++) {
                    weightValue |= (data[validlength - j - 1] << (8 * j));
                }

                weightInKg[idx] = (float)(weightValue * 0.03);
                char weight_msg[50];
                sprintf(weight_msg, "Weight in kilograms: %.2f\r\n", weightInKg[idx]);
                CDC_Transmit_FS((uint8_t*)weight_msg, strlen(weight_msg));
            }
        }

        // weight readings
        CDC_Transmit_FS((uint8_t*)"Weight readings in kilograms:\r\n", 31);
        for (int i = 0; i < 8; i++)
        {
            char weight_reading[20];
            sprintf(weight_reading, "%.2f\r\n", weightInKg[i]);
            CDC_Transmit_FS((uint8_t*)weight_reading, strlen(weight_reading));
        }

        // weights sort
        Sort(weightInKg, 8);
        float median = (weightInKg[3] + weightInKg[4]) / 2;
        float valid = 0;
        float validWeight = 0;
        float error = 0.01 * median;
        float val;

        // calc valid weights
        for (int i = 0; i < 8; i++) {
            if (i < 4) {
                val = median - weightInKg[i];
                if (val < error) {
                    valid++;
                    validWeight += weightInKg[i];
                }
            } else {
                val = weightInKg[i] - median;
                if (val < error) {
                    valid++;
                    validWeight += weightInKg[i];
                }
            }
        }

        if (valid == 0) validWeight = median;
        else validWeight /= valid;

        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET); // PC13 LOW
        HAL_Delay(10);
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET); // PC13 HIGH
        HAL_Delay(10);

        // final avg weght
        char final_weight_msg[50];
        sprintf(final_weight_msg, "Final average Weight in kilograms: %.2f\r\n", validWeight);
        CDC_Transmit_FS((uint8_t*)final_weight_msg, strlen(final_weight_msg));
    }
}