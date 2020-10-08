
#include "main.h"
#include <string.h>
CRC_HandleTypeDef hcrc;
UART_HandleTypeDef huart2;


/* Entropy String. Uniformly distributed random bit string 1*/
uint8_t entropy_data[32] = {
                             0x9d, 0x20, 0x1a, 0x18, 0x9b, 0x6d, 0x1a, 0xa7, 0x0e,
                             0x79, 0x57, 0x6f, 0x36, 0xb6, 0xaa, 0x88, 0x55, 0xfd,
                             0x4a, 0x7f, 0x97, 0xe9, 0x71, 0x69, 0xb6, 0x60, 0x88,
                             0x78, 0xe1, 0x9c, 0x8b, 0xa5
                           };
/* Nonce. Non repeating sequence, such as a timestamp */
uint8_t nonce[] = {0xFE, 0xA9, 0x96, 0xD4, 0x62, 0xC5};
/* Personalization String */
uint8_t personalization_String[] = {0x1E, 0x6C, 0x7B, 0x82, 0xE5, 0xA5, 0x71, 0x8D};
/* Structure that will keep the Random State */
RNGstate_stt RNGstate;
RNGinitInput_stt RNGinit_st;
/* Array that will be filled with random bytes */
int32_t status;
uint8_t RandomString[32]; //the private key
uint8_t pubKey[32];  //Buffer that will store the public key
FLASH_EraseInitTypeDef Flash_ROM;  //声明 FLASH_EraseInitTypeDef 结构体为 Flash_ROM
//const eeprom[PAGE_SIZE*PAGE_COUNT]={} ;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/

static void MX_USART2_UART_Init(void);
static void MX_CRC_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_USART2_UART_Init();
  MX_CRC_Init();
  /* USER CODE BEGIN 2 */
  /* Set the values of EntropyData, Nonce, Personalization String and their sizes inside the RNGinit_st structure */
    RNGinit_st.pmEntropyData = entropy_data;
    RNGinit_st.mEntropyDataSize = sizeof(entropy_data);
    RNGinit_st.pmNonce =  nonce;
    RNGinit_st.mNonceSize = sizeof( nonce );
    RNGinit_st.pmPersData = personalization_String;
    RNGinit_st.mPersDataSize = sizeof( personalization_String );

    status = RNGinit(&RNGinit_st,&RNGstate);
    if  ( status == RNG_SUCCESS )
    {
      /* The Random engine has been initialized, the status is in RNGstate */

      /* Now fill the random string with random bytes */
      status = RNGgenBytes(&RNGstate, NULL, RandomString, sizeof(RandomString));
      if (status == RNG_SUCCESS)
      {

    	  status = ED25519keyGen(RandomString, pubKey);
    	  if (status != ED25519_SUCCESS)
    	  {
    		  Error_Handler();
    	  }


        /* Random Generated Succefully, free the state before returning */
         status = RNGfree(&RNGstate);
         if  ( status != RNG_SUCCESS )
         {
             Error_Handler();
         }


      }
      else
      {
        /* In case of randomization not success possible values of status:
         * RNG_ERR_BAD_PARAMETER, RNG_ERR_UNINIT_STATE
         */

        Error_Handler();
      }

    }
    else
    {
      /* In case of randomization not success possible values of status:
       * RNG_ERR_BAD_ENTROPY_SIZE, RNG_ERR_BAD_PERS_STRING_SIZE
       */
    	Error_Handler();

    }
    //HAL_FLASH_Unlock();               //解锁Flash
    //Flash_ROM.TypeErase=FLASH_TYPEERASE_PAGES;//标明Flash执行页面只做擦除操作
    //Flash_ROM.PageAddress=VIRADDR;
    //Flash_ROM.NbPages=PAGE_COUNT;
    //uint32_t PageError = 0;                    //设置PageError,如果出现错误这个变量会被设置为出错的FLASH地址
    //HAL_FLASHEx_Erase(&Flash_ROM, &PageError);  //调用擦除函数擦除
    //HAL_FLASH_Lock();                 //锁定Flash
    //FLASH_WaitForLastOperation(1000);
    //if(VIRADDR*4<PAGE_SIZE*PAGE_COUNT)//地址在Flash_ROM定义的范围内
    //{
      //HAL_FLASH_Unlock();               //解锁Flash
      //FLASH_WaitForLastOperation(1000);
      //HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,VIRADDR,*pubKey);
      //FLASH_WaitForLastOperation(1000);
      //HAL_FLASH_Lock();                 //锁定Flash
      //FLASH_WaitForLastOperation(1000);

    //}

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */


/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  hcrc.Init.DefaultInitValueUse = DEFAULT_INIT_VALUE_ENABLE;
  hcrc.Init.InputDataInversionMode = CRC_INPUTDATA_INVERSION_NONE;
  hcrc.Init.OutputDataInversionMode = CRC_OUTPUTDATA_INVERSION_DISABLE;
  hcrc.InputDataFormat = CRC_INPUTDATA_FORMAT_BYTES;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 38400;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}


void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
