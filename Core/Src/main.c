/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdlib.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct ws2812b_color {
  uint8_t red, green, blue;
} ws2812b_color;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define zero 0b1000000
#define one 0b11111000

#define WS2812B_LEDS 64

#define UP 		0
#define DOWN 	1
#define LEFT	3
#define RIGHT 	4


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */


SPI_HandleTypeDef *hspi_ws2812b;
ws2812b_color ws2812b_array[WS2812B_LEDS];

static uint8_t buffer[64*24+120];

uint8_t length = 1;
int head_position[2]={0};
uint8_t prev_head_position[2]={0};
uint8_t tail_x[64] = {0};
uint8_t tail_y[64] = {0};
uint8_t move_direction = RIGHT;
uint8_t prev_move_direction = RIGHT;
uint8_t fruit_position[2]={0};
uint8_t GROWTH = 0;
uint8_t EATEN = 1;
uint8_t collision[8][8]={0};
uint8_t GAME_OVER = 1;
int MOVEX = 1;
 int MOVEY = 1;

 int tail_X[64] = {0};
 int tail_Y[64] = {0};
 int moved = 0;

 int M0[8][8] = {{0,0,0,0,0,0,0,0},
 				{0,0,0,0,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,1,0,1,0,0,0,0},
 				{0,1,0,1,0,0,0,0},
 				{0,1,0,1,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,0,0,0,0,0,0,0}};

 int M1[8][8] = {{0,0,0,0,0,0,0,0},
 				{0,0,0,0,0,0,0,0},
 				{0,1,1,0,0,0,0,0},
 				{0,0,1,0,0,0,0,0},
 				{0,0,1,0,0,0,0,0},
 				{0,0,1,0,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,0,0,0,0,0,0,0}};

 int M2[8][8] = {{0,0,0,0,0,0,0,0},
 				{0,0,0,0,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,0,0,1,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,1,0,0,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,0,0,0,0,0,0,0}};

 int M3[8][8] = {{0,0,0,0,0,0,0,0},
 				{0,0,0,0,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,0,0,1,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,0,0,1,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,0,0,0,0,0,0,0}};

 int M4[8][8] = {{0,0,0,0,0,0,0,0},
 				{0,0,0,0,0,0,0,0},
 				{0,1,0,1,0,0,0,0},
 				{0,1,0,1,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,0,0,1,0,0,0,0},
 				{0,0,0,1,0,0,0,0},
 				{0,0,0,0,0,0,0,0}};

 int M5[8][8] = {{0,0,0,0,0,0,0,0},
 				{0,0,0,0,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,1,0,0,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,0,0,1,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,0,0,0,0,0,0,0}};

 int M6[8][8] = {{0,0,0,0,0,0,0,0},
 				{0,0,0,0,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,1,0,0,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,1,0,1,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,0,0,0,0,0,0,0}};

 int M7[8][8] = {{0,0,0,0,0,0,0,0},
 				{0,0,0,0,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,1,0,1,0,0,0,0},
 				{0,0,0,1,0,0,0,0},
 				{0,0,0,1,0,0,0,0},
 				{0,0,0,1,0,0,0,0},
 				{0,0,0,0,0,0,0,0}};

 int M8[8][8] = {{0,0,0,0,0,0,0,0},
 				{0,0,0,0,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,1,0,1,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,1,0,1,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,0,0,0,0,0,0,0}};

 int M9[8][8] = {{0,0,0,0,0,0,0,0},
 				{0,0,0,0,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,1,0,1,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,0,0,1,0,0,0,0},
 				{0,1,1,1,0,0,0,0},
 				{0,0,0,0,0,0,0,0}};



void WS2812B_Init(SPI_HandleTypeDef * spi_handler)
{
	hspi_ws2812b = spi_handler;
}

void WS2812B_SetDiodeRGB(int16_t diode_id, uint8_t R, uint8_t G, uint8_t B)
{
	if(diode_id >= WS2812B_LEDS || diode_id < 0) return;
	ws2812b_array[diode_id].red = R;
	ws2812b_array[diode_id].green = G;
	ws2812b_array[diode_id].blue = B;
}

void SetDiodeCoord(uint8_t x, uint8_t y, uint8_t R, uint8_t G, uint8_t B)
{
	WS2812B_SetDiodeRGB(x+y*8,R,G,B);
}


void sendlight()
{
	for(uint8_t i = 0; i < 120; i++)
		buffer[i] = 0x00;

	for(uint16_t i=0, j=120; i<WS2812B_LEDS; i++)
	{
		//GREEN
		for(int8_t k=7; k>=0; k--)
		{
			if((ws2812b_array[i].green & (1<<k)) == 0)
				buffer[j] = zero;
			else
				buffer[j] = one;
			j++;
		}

		//RED
		for(int8_t k=7; k>=0; k--)
		{
			if((ws2812b_array[i].red & (1<<k)) == 0)
				buffer[j] = zero;
			else
				buffer[j] = one;
			j++;
		}

		//BLUE
		for(int8_t k=7; k>=0; k--)
		{
			if((ws2812b_array[i].blue & (1<<k)) == 0)
				buffer[j] = zero;
			else
				buffer[j] = one;
			j++;
		}
	}


	HAL_SPI_Transmit(hspi_ws2812b, buffer, (WS2812B_LEDS+5) * 24, 1000);
}

void move()
		{
			if(GROWTH)
			{
				tail_x[length] = head_position[0];
				tail_y[length] = head_position[1];
				length++;
				GROWTH = 0;
			}
			else if(length)
			{
				for(int i = 0; i < length-1; i++)
				{
					tail_x[i] = tail_x[i+1];
					tail_y[i] = tail_y[i+1];
				}
				tail_x[length-1] = head_position[0];
				tail_y[length-1] = head_position[1];
			}

			switch(move_direction)
			{
			case UP:
				if(prev_move_direction == DOWN)
					{
						move_direction = prev_move_direction;
						head_position[1] -= 1;
					}
				else 	head_position[1] += 1;
				break;
			case DOWN:
				if(prev_move_direction == UP)
					{
						move_direction = prev_move_direction;
						head_position[1] += 1;
					}
				else 	head_position[1] -= 1;
				break;
			case LEFT:
				if(prev_move_direction == RIGHT)
					{
						move_direction = prev_move_direction;
						head_position[0] += 1;
					}
				else 	head_position[0] -= 1;
				break;
			case RIGHT:
				if(prev_move_direction == LEFT)
					{
						move_direction = prev_move_direction;
						head_position[0] -= 1;
					}
				else 	head_position[0] += 1;
				break;
			}
			if(head_position[0] < 0)
				head_position[0] = 0;
			if(head_position[0] > 7)
				head_position[0] = 7;
			if(head_position[1] < 0)
				head_position[1] = 0;
			if(head_position[1] > 7)
				head_position[1] = 7;

			prev_head_position[0] = head_position[0];
			prev_head_position[1] = head_position[1];
			prev_move_direction = move_direction;


		}
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */
int R = 1;
  int G = 100;
  int B = 200;
  volatile int Joystick[2];

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
  void ADC_SetActiveChannel(ADC_HandleTypeDef *hadc, uint32_t AdcChannel)
  {
    ADC_ChannelConfTypeDef sConfig = {0};
    sConfig.Channel = AdcChannel;
    sConfig.Rank = 1;
    sConfig.SamplingTime = 480;
    if (HAL_ADC_ConfigChannel(hadc, &sConfig) != HAL_OK)
    {
     Error_Handler();
    }
  }


  void led_digits(int digit1, int digit2, int Rb, int Gb, int Bb, int Rd, int Gd, int Bd)
  {
  for(int i = 0; i < WS2812B_LEDS; i++)
  	  	  {
  	  	      WS2812B_SetDiodeRGB(i,Rb,Gb,Bb);
  	  	  }



  switch(digit1)
  {
  case 0:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M0[i][j] == 1)
  			{
  				SetDiodeCoord(j,i,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 1:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M1[i][j] == 1)
  			{
  				SetDiodeCoord(j,i,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 2:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M2[i][j] == 1)
  			{
  				SetDiodeCoord(j,i,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 3:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M3[i][j] == 1)
  			{
  				SetDiodeCoord(j,i,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 4:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M4[i][j] == 1)
  			{
  				SetDiodeCoord(j,i,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 5:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M5[i][j] == 1)
  			{
  				SetDiodeCoord(j,i,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 6:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M6[i][j] == 1)
  			{
  				SetDiodeCoord(j,i,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 7:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M7[i][j] == 1)
  			{
  				SetDiodeCoord(j,i,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 8:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M8[i][j] == 1)
  			{
  				SetDiodeCoord(j,i,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 9:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M9[i][j] == 1)
  			{
  				SetDiodeCoord(j,i,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  }

  switch(digit2)
  {
  case 0:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M0[i][j+4] == 1)
  			{
  				SetDiodeCoord(j,i+1,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 1:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M1[i][j+4] == 1)
  			{
  				SetDiodeCoord(j,i+1,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 2:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M2[i][j+4] == 1)
  			{
  				SetDiodeCoord(j,i+1,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 3:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M3[i][j+4] == 1)
  			{
  				SetDiodeCoord(j,i+1,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 4:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M4[i][j+4] == 1)
  			{
  				SetDiodeCoord(j,i+1,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 5:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M5[i][j+4] == 1)
  			{
  				SetDiodeCoord(j,i+1,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 6:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M6[i][j+4] == 1)
  			{
  				SetDiodeCoord(j,i+1,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 7:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M7[i][j+4] == 1)
  			{
  				SetDiodeCoord(j,i+1,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 8:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M8[i][j+4] == 1)
  			{
  				SetDiodeCoord(j,i+1,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  case 9:

  	for(int i = 0; i<8; i++)
  	{
  		for(int j = 0; j<8; j++)
  		{
  			if(M9[i][j+4] == 1)
  			{
  				SetDiodeCoord(j,i+1,Rd,Gd,Bd);
  			}
  		}
  	}
  	break;

  }

  }


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
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_ADC1_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_ADC_Start(&hadc1);
  WS2812B_Init(&hspi1);


  HAL_Delay(10);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(GAME_OVER)
		{

			for(int i = 0; i < WS2812B_LEDS; i++)
					  {
						  WS2812B_SetDiodeRGB(i,50,0,0);
						  sendlight();
						  HAL_Delay(20);
					  }
			while(GAME_OVER)
			{
			 led_digits((length-1)/10,(length-1)%10,50,0,0,25,25,25);
			 sendlight();
			}
		}

	  for(int i = 0; i < WS2812B_LEDS; i++)
	  	  {
	  	      WS2812B_SetDiodeRGB(i,0,0,0);
	  	  }

	  if(HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
	  	      {
	  	        Joystick[0] = HAL_ADC_GetValue(&hadc1); // Get X value
	  	        ADC_SetActiveChannel(&hadc1, ADC_CHANNEL_7);
	  	        HAL_ADC_Start(&hadc1);
	  	      }

	  	      if(HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
	  	      {
	  	        Joystick[1] = HAL_ADC_GetValue(&hadc1); // Get Y value
	  	        ADC_SetActiveChannel(&hadc1, ADC_CHANNEL_6);
	  	        HAL_ADC_Start(&hadc1);
	  	      }
	  	if(fruit_position[0] == head_position[0] && fruit_position[1] == head_position[1])
	  	{
	  		EATEN = 1;
	  		GROWTH = 1;
	  		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 1);


	  	}
	  	if(EATEN)
	  	{
	  	do{
	  		fruit_position[0] = rand()%8;
	  		fruit_position[1] = rand()%8;
	  	}while(collision[fruit_position[0]][fruit_position[1]]==1 || (fruit_position[0] == head_position[0] && fruit_position[1] == head_position[1]));
	  	EATEN = 0;
	  	}

	    if(Joystick[0] < 100 && MOVEX == 1 && MOVEY == 1)
	    {
	    	move_direction = LEFT;


	    }
	    else if(Joystick[0] > 4000 && MOVEX == 1 && MOVEY == 1)
	    	{
	    	move_direction = RIGHT;
	    	MOVEX = 0;

	    	}
	    else if(Joystick[1] > 4000  && MOVEX == 1 && MOVEY == 1)
	    	{
	    	move_direction = UP;
	    	MOVEY = 0;

	    	}
	    else if(Joystick[1] < 100 && MOVEX == 1 && MOVEY == 1)
			{xxx
			move_direction = DOWN;
			MOVEY = 0;

			}

		if(moved)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 0);
			move();
			moved = 0;
			for(int i = 0; i < 8; i++)
			{
				for(int j = 0; j < 8; j++)
				{
					collision[i][j] = 0;
				}
			}
			for(int i = 0; i < length; i++)
			{
					collision[tail_x[i]][tail_y[i]] = 1;

			}
			if(collision[head_position[0]][head_position[1]] == 1)
				GAME_OVER = 1;

		}





		if(Joystick[0] < 3000 && Joystick[0]>1000) MOVEX = 1;
		if(Joystick[1] < 3000 && Joystick[1]>1000) MOVEY = 1;

		SetDiodeCoord(head_position[0],head_position[1],0,0,25);
		SetDiodeCoord(fruit_position[0],fruit_position[1],25,0,0);
	 for(int i = 0; i < length; i++)
		  {
		 	 SetDiodeCoord(tail_x[i],tail_y[i],0,25,0);

		  }



//	if(R >= 254) directionR = -1; // zmiana kierunku na malejąchead_Y
//	else if(R <= 1)   directionR = 1;  // zmiana kierunku na rosnący
//	if(G >= 254) directionG = -1; // zmiana kierunku na malejący
//	else if(G <= 1)   directionG = 1;  // zmiana kierunku na rosnący
//	if(B >= 254) directionB = -1; // zmiana kierunku na malejący
//	else if(B <= 1)   directionB = 1;  // zmiana kierunku na rosnący
//
//	if(!(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0)))
//	  {
//		R=R+directionR;
//		G=G+directionG;
//		B=B+directionB;
//	  }



	sendlight();



    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC12|RCC_PERIPHCLK_TIM2;
  PeriphClkInit.Adc12ClockSelection = RCC_ADC12PLLCLK_DIV1;
  PeriphClkInit.Tim2ClockSelection = RCC_TIM2CLK_HCLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the ADC multi-mode
  */
  multimode.Mode = ADC_MODE_INDEPENDENT;
  if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_6;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 20000;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */
//  __HAL_RCC_SYSCFG_CLK_ENABLE();
  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC3 */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    moved = 1;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{


	GAME_OVER = 0;
	length = 0;
	head_position[0] = 0;
	head_position[1] = 0;
	for(int i = 0; i < 64; i++)
	{
		tail_x[i] = 0;
		tail_y[i] = 0;
	}

	EATEN = 1;
	prev_head_position[0]= 0;
	prev_head_position[0]= 1;
	prev_move_direction = RIGHT;
	move_direction = RIGHT;
	fruit_position[0]= 0;
	fruit_position[1]= 0;

}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
