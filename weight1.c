#include "main.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"
#include "stm32f1xx_hal.h"

UART_HandleTypeDef huart1; // UART1 for sensor communication

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USB_DEVICE_Init(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_USB_DEVICE_Init();

  uint8_t data[4];
  uint8_t discard;
  
  while (1)
  {
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET); // PC13 HIGH
    HAL_Delay(2000);

    // send msg over USB
    char message[] = "passkey sending\r\n";
    CDC_Transmit_FS((uint8_t*)message, strlen(message));

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET); // PA8 HIGH
    char sensor_command[] = "S98;MSV?;";
    HAL_UART_Transmit(&huart1, (uint8_t*)sensor_command, strlen(sensor_command), HAL_MAX_DELAY);
    HAL_Delay(11);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET); // PA8 LOW
    HAL_Delay(10);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET); // PA8 HIGH

    char sensor_command2[] = "S09;MSV?;";
    HAL_UART_Transmit(&huart1, (uint8_t*)sensor_command2, strlen(sensor_command2), HAL_MAX_DELAY);
    HAL_Delay(11);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET); // PA8 LOW
    HAL_Delay(10);

    if (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE))
    {
      CDC_Transmit_FS((uint8_t*)"data receiving\r\n", 16);
      
      for (int i = 3; i >= 0; i--)
      {
        HAL_UART_Receive(&huart1, &data[i], 1, HAL_MAX_DELAY);
      }

      // Read and discard two extra bytes
      HAL_UART_Receive(&huart1, &discard, 1, HAL_MAX_DELAY);
      HAL_UART_Receive(&huart1, &discard, 1, HAL_MAX_DELAY);

      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
      HAL_Delay(300);
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
      HAL_Delay(300);

      unsigned long weightValue = 0;
      int validlength = 4;
      if (data[3] == 0) validlength = 3;

      for (int j = 0; j < validlength; j++)
      {
        weightValue |= (data[validlength - j - 1] << (8 * j));
      }

      float weightInKg = weightValue * 0.03;
      char weight_msg[50];
      sprintf(weight_msg, "Weight in kilograms: %.2f\r\n", weightInKg);
      CDC_Transmit_FS((uint8_t*)weight_msg, strlen(weight_msg));
    }
  }
}

static void MX_USART1_UART_Init(void)
{
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_9B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_EVEN;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
}

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  // PC13 output for LED
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  // PA8 output
  GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}