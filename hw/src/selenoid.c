/******************************************************************************/
/** @file       lcd.c
 *******************************************************************************
 *
 *  @brief      
 *
 *  @author    
 *
 *  @remark     
 *
 ******************************************************************************/
/*
 *              .
 *
 ******************************************************************************/

/****** Header-Files **********************************************************/
#include "selenoid.h"
#include "gpio.h"
#include "systick.h"
#include "nxp_lcd_driver.h"

/****** Macros ****************************************************************/

uint8_t fOpenRelay1 = 0;
uint8_t fCloseRelay1 = 0;
uint8_t fOpenRelay2 = 0;
uint8_t fCloseRelay2 = 0;
uint8_t fOpenRelay3 = 0;
uint8_t fCloseRelay3 = 0;
uint8_t fOpenRelay4 = 0;
uint8_t fCloseRelay4 = 0;
uint8_t fOpenRelay5 = 0;
uint8_t fCloseRelay5 = 0;
uint8_t fOpenRelay6 = 0;
uint8_t fCloseRelay6 = 0;
uint8_t fOpenRelay7 = 0;
uint8_t fCloseRelay7 = 0;

/****** Function prototypes ****************************************************/

/****** Data ******************************************************************/

/****** Implementation ********************************************************/

/*******************************************************************************
 *  function :    led_init
 ******************************************************************************/
void selenoid_init(void) {

    GpioInit_t tGpioInit = {GPIO_MODE_OUTPUT,
                            GPIO_OUTPUT_PUSH_PULL,
                            GPIO_SPEED_MEDIUM,
                            GPIO_PULL_NON
                           };

    /* Enable the peripheral clock of GPIOA and GPIOB */
    RCC->IOPENR |= RCC_IOPENR_GPIOAEN | RCC_IOPENR_GPIOBEN;

    /* Select output mode on GPIOA pin 3 - SELENOID_DRV_4_RESET */  
    gpio_init(GPIOA, 3, &tGpioInit);
		/* Select output mode on GPIOA pin 4 - SELENOID_DRV_3_RESET */
    gpio_init(GPIOA, 4, &tGpioInit);
		/* Select output mode on GPIOA pin 5 - SELENOID_DRV_2_RESET */
    gpio_init(GPIOA, 5, &tGpioInit);													 													 
    /* Select output mode on GPIOA pin 6 - SELENOID_DRV_1_RESET */  
    gpio_init(GPIOA, 6, &tGpioInit);
		/* Select output mode on GPIOA pin 7 - SELENOID_DRV_4_SET */
    gpio_init(GPIOA, 7, &tGpioInit);
		/* Select output mode on GPIOA pin 8 - SELENOID_DRV_3_SET */
    gpio_init(GPIOA, 8, &tGpioInit);
		/* Select output mode on GPIOA pin 11 - SELENOID_DRV_2_SET */
    gpio_init(GPIOA, 11, &tGpioInit);
		/* Select output mode on GPIOA pin 12 - SELENOID_DRV_1_SET */
    gpio_init(GPIOA, 12, &tGpioInit);
		/* Select output mode on GPIOA pin 15 - SELENOID_ENABLE */
    gpio_init(GPIOA, 15, &tGpioInit);		
		
    /* Enable the peripheral clock of GPIOB */
    RCC->IOPENR |= RCC_IOPENR_GPIOBEN;	
		/* Select output mode on GPIOB pin 15 - SELENOID_SLEEP */
    gpio_init(GPIOB, 15, &tGpioInit);			
}


/*******************************************************************************
 *  function :    selenoid_pin_set -- COM PORT
 ******************************************************************************/
void selenoid_pin_set(Selenoid_t tSelenoid) {

    gpio_set(GPIOA, 12);
}


/*******************************************************************************
 *  function :    selenoid_pin_reset  -- COM  PORT
 ******************************************************************************/
void selenoid_pin_reset(Selenoid_t tSelenoid) {

    gpio_clear(GPIOA, 6);
}

/*******************************************************************************
 *  function :    selenoid_enable
 ******************************************************************************/
void selenoid_enable( void ) {

    gpio_set(GPIOA, 15);
}

/*******************************************************************************
 *  function :    selenoid_disable
 ******************************************************************************/
void selenoid_disable( void ) {

    gpio_clear(GPIOA, 15);
}

/*******************************************************************************
 *  function :    selenoid_sleep
 ******************************************************************************/
void selenoid_sleep( void ) {

    gpio_clear(GPIOB, 15);
}

/*******************************************************************************
 *  function :    selenoid_sleep
 ******************************************************************************/
void selenoid_wakeup( void ) {

    gpio_set(GPIOB, 15);
}

/*******************************************************************************
 *  function :    closeAllSelenoids   -- ONLY USE TESTING PURPOSE
 ******************************************************************************/
void closeAllSelenoids( void ) 
{
// TODO
}

/*******************************************************************************
 *  function :    openAllSelenoids    -- ONLY USE TESTING PURPOSE
 ******************************************************************************/
void openAllSelenoids( void ) 
{
// TODO
}


/*******************************************************************************
// *  function :    Open Relay 1
// ******************************************************************************/
void openRelay1( void ) 
{
// Selenoid 1 ONN
  gpio_set(GPIOA, 6);
	systick_delayMs(10);
	gpio_clear(GPIOA, 6);
}

/*******************************************************************************
 *  function :    Close Relay 1
 ******************************************************************************/
void closeRelay1( void ) 
{
// Selenoid 1 OFF	
	GPIOA->ODR |= 0x000019B8; // GPIOA  3 4 5 7 8 11 12 set, 6 reset
	systick_delayMs(10);
	GPIOA->ODR &= 0xFFFFE607; // GPIOA  3 4 5 6 7 8 11 12 clear 
}

/*******************************************************************************
 *  function :    Open Relay 2
 ******************************************************************************/
void openRelay2( void ) 
{
// Selenoid 1 ONN
  gpio_set(GPIOA, 11);
	systick_delayMs(10);
	gpio_clear(GPIOA, 11);
}

/*******************************************************************************
 *  function :    Close Relay 2
 ******************************************************************************/
void closeRelay2( void ) 
{
// Selenoid 2 OFF	
	GPIOA->ODR |= 0x000011F8; // GPIOA  3 4 5 6 7 8 12 set, 11 reset
	systick_delayMs(10);
	GPIOA->ODR &= 0xFFFFE607; // GPIOA  3 4 5 6 7 8 11 12 clear 
}

/*******************************************************************************
 *  function :    Open Relay 3
 ******************************************************************************/
void openRelay3( void ) 
{
// Selenoid 3 ONN
  gpio_set(GPIOA, 5);
	systick_delayMs(10);
	gpio_clear(GPIOA, 5);
}

/*******************************************************************************
 *  function :    Close Relay 3
 ******************************************************************************/
void closeRelay3( void ) 
{
// Selenoid 3 OFF	
	GPIOA->ODR |= 0x000019D8; // GPIOA  3 4 6 7 8 11 12 set, 5 reset
	systick_delayMs(10);
	GPIOA->ODR &= 0xFFFFE607; // GPIOA  3 4 5 6 7 8 11 12 clear 
}
/*******************************************************************************
 *  function :    Open Relay 4
 ******************************************************************************/
void openRelay4( void ) 
{
// Selenoid 4 ONN
  gpio_set(GPIOA, 8);
	systick_delayMs(10);
	gpio_clear(GPIOA, 8);
}

/*******************************************************************************
 *  function :    Close Relay 4
 ******************************************************************************/
void closeRelay4( void ) 
{
// Selenoid 4 OFF	
	GPIOA->ODR |= 0x000018F8; // GPIOA  3 4 5 6 7 11 12 set, 8 reset
	systick_delayMs(10);
	GPIOA->ODR &= 0xFFFFE607; // GPIOA  3 4 5 6 7 8 11 12 clear 
}

/*******************************************************************************
 *  function :    Open Relay 4
 ******************************************************************************/
void openRelay5( void ) 
{
// Selenoid 5 ONN
  gpio_set(GPIOA, 4);
	systick_delayMs(10);
	gpio_clear(GPIOA, 4);
}

/*******************************************************************************
 *  function :    Close Relay 5
 ******************************************************************************/
void closeRelay5( void ) 
{
// Selenoid 5 OFF	
	GPIOA->ODR |= 0x000019E8; // GPIOA  3 5 6 7 8 11 12 set, 4 reset
	systick_delayMs(10);
	GPIOA->ODR &= 0xFFFFE607; // GPIOA  3 4 5 6 7 8 11 12 clear 
}

/*******************************************************************************
 *  function :    Open Relay 6
 ******************************************************************************/
void openRelay6( void ) 
{
// Selenoid 6 ONN
  gpio_set(GPIOA, 7);
	systick_delayMs(10);
	gpio_clear(GPIOA, 7);
}

/*******************************************************************************
 *  function :    Close Relay 6
 ******************************************************************************/
void closeRelay6( void ) 
{
// Selenoid 6 OFF	
	GPIOA->ODR |= 0x00001978; // GPIOA  3 4 5 6 8 11 12 set, 7 reset
	systick_delayMs(10);
	GPIOA->ODR &= 0xFFFFE607; // GPIOA  3 4 5 6 7 8 11 12 clear 
}

/*******************************************************************************
 *  function :    Open Relay 7
 ******************************************************************************/
void openRelay7( void ) 
{
// Selenoid 7 ONN
  gpio_set(GPIOA, 3);
	systick_delayMs(10);
	gpio_clear(GPIOA, 3);
}

/*******************************************************************************
 *  function :    Close Relay 7
 ******************************************************************************/
void closeRelay7( void ) 
{
// Selenoid 7 OFF	
	GPIOA->ODR |= 0x000019F0; // GPIOA  4 5 6 7 8 11 12 set, 3 reset
	systick_delayMs(10);
	GPIOA->ODR &= 0xFFFFE607; // GPIOA  3 4 5 6 7 8 11 12 clear 
}




/*******************************************************************************
 *  function :    selenoid Control
 ******************************************************************************/
void selenoidCon( void ) 
{

	if(fCloseRelay1)
	{
		fRelay1Status = 0;
		fAnyRelayON = 0;
		LCDBufferReset();      // Röle açildiginda/kapandiginde sprink isaretini ekrandan kaldirmak için		
		systick_delayMs(20);
		selenoid_wakeup();
		selenoid_enable();
		systick_delayMs(20);
		fCloseRelay1 = 0;
		closeRelay1();	
		systick_delayMs(20);		
		selenoid_sleep();
		selenoid_disable();		
	}	
	if(fCloseRelay2)
	{
		fRelay2Status = 0;
		fAnyRelayON = 0;
		LCDBufferReset();      // Röle açildiginda/kapandiginde sprink isaretini ekrandan kaldirmak için		
		systick_delayMs(20);
		selenoid_wakeup();
		selenoid_enable();
		systick_delayMs(20);
		fCloseRelay2 = 0;
		closeRelay2();	
		systick_delayMs(20);		
		selenoid_sleep();
		selenoid_disable();			
	}			
	if(fCloseRelay3)
	{
		fRelay3Status = 0;
		fAnyRelayON = 0;
		LCDBufferReset();      // Röle açildiginda/kapandiginde sprink isaretini ekrandan kaldirmak için		
		systick_delayMs(20);
		selenoid_wakeup();
		selenoid_enable();
		systick_delayMs(20);
		fCloseRelay3 = 0;
		closeRelay3();	
		systick_delayMs(20);		
		selenoid_sleep();
		selenoid_disable();				
	}
	if(fCloseRelay4)
	{
		fRelay4Status = 0;
		fAnyRelayON = 0;
		LCDBufferReset();      // Röle açildiginda/kapandiginde sprink isaretini ekrandan kaldirmak için
		systick_delayMs(20);
		selenoid_wakeup();
		selenoid_enable();
		systick_delayMs(20);
		fCloseRelay4 = 0;
		closeRelay4();	
		systick_delayMs(20);		
		selenoid_sleep();
		selenoid_disable();		
	}	
	if(fCloseRelay5)
	{
		fRelay5Status = 0;
		fAnyRelayON = 0;
		LCDBufferReset();      // Röle açildiginda/kapandiginde sprink isaretini ekrandan kaldirmak için
		systick_delayMs(20);
		selenoid_wakeup();
		selenoid_enable();
		systick_delayMs(20);
		fCloseRelay5 = 0;
		closeRelay5();	
		systick_delayMs(20);		
		selenoid_sleep();
		selenoid_disable();		
	}		
	if(fCloseRelay6)
	{
		fRelay6Status = 0;
		fAnyRelayON = 0;
		LCDBufferReset();      // Röle açildiginda/kapandiginde sprink isaretini ekrandan kaldirmak için
		systick_delayMs(20);
		selenoid_wakeup();
		selenoid_enable();
		systick_delayMs(20);
		fCloseRelay6 = 0;
		closeRelay6();	
		systick_delayMs(20);		
		selenoid_sleep();
		selenoid_disable();		
	}	
	if(fCloseRelay7)
	{
		fRelay7Status = 0;
		fAnyRelayON = 0;
		LCDBufferReset();      // Röle açildiginda/kapandiginde sprink isaretini ekrandan kaldirmak için
		systick_delayMs(20);
		selenoid_wakeup();
		selenoid_enable();
		systick_delayMs(20);
		fCloseRelay7 = 0;
		closeRelay7();	
		systick_delayMs(20);		
		selenoid_sleep();
		selenoid_disable();		
	}		

	
	if(fOpenRelay1)
	{
		fRelay1Status = 1;
		fAnyRelayON = 1;
		LCDBufferReset();      // Röle açildiginda/kapandiginde sprink isaretini ekrandan kaldirmak için		
		systick_delayMs(20);
		selenoid_wakeup();
		selenoid_enable();
		systick_delayMs(20);
		fOpenRelay1 = 0;
		openRelay1();
		systick_delayMs(20);		
		selenoid_sleep();
		selenoid_disable();			
	}	
	
	if(fOpenRelay2)
	{
		fRelay2Status = 1;
		fAnyRelayON = 1;
		LCDBufferReset();      // Röle açildiginda/kapandiginde sprink isaretini ekrandan kaldirmak için		
		systick_delayMs(20);
		selenoid_wakeup();
		selenoid_enable();
		systick_delayMs(20);
		fOpenRelay2 = 0;
		openRelay2();	
		systick_delayMs(20);		
		selenoid_sleep();
		selenoid_disable();			
	}

	if(fOpenRelay3)
	{
		fRelay3Status = 1;
		fAnyRelayON = 1;
		LCDBufferReset();      // Röle açildiginda/kapandiginde sprink isaretini ekrandan kaldirmak için		
		systick_delayMs(20);
		selenoid_wakeup();
		selenoid_enable();
		systick_delayMs(20);
		fOpenRelay3 = 0;
		openRelay3();	
		systick_delayMs(20);		
		selenoid_sleep();
		selenoid_disable();			
	}

	if(fOpenRelay4)
	{
		fRelay4Status = 1;
		fAnyRelayON = 1;
		LCDBufferReset();      // Röle açildiginda/kapandiginde sprink isaretini ekrandan kaldirmak için		
		systick_delayMs(20);
		selenoid_wakeup();
		selenoid_enable();
		systick_delayMs(20);
		fOpenRelay4 = 0;
		openRelay4();	
		systick_delayMs(20);		
		selenoid_sleep();
		selenoid_disable();				
	}	
	
	if(fOpenRelay5)
	{
		fRelay5Status = 1;
		fAnyRelayON = 1;
		LCDBufferReset();      // Röle açildiginda/kapandiginde sprink isaretini ekrandan kaldirmak için		
		systick_delayMs(20);
		selenoid_wakeup();
		selenoid_enable();
		systick_delayMs(20);
		fOpenRelay5 = 0;
		openRelay5();	
		systick_delayMs(20);		
		selenoid_sleep();
		selenoid_disable();				
	}		
	
	if(fOpenRelay6)
	{
		fRelay6Status = 1;
		fAnyRelayON = 1;
		LCDBufferReset();      // Röle açildiginda/kapandiginde sprink isaretini ekrandan kaldirmak için		
		systick_delayMs(20);
		selenoid_wakeup();
		selenoid_enable();
		systick_delayMs(20);
		fOpenRelay6 = 0;
		openRelay6();	
		systick_delayMs(20);		
		selenoid_sleep();
		selenoid_disable();				
	}	

	if(fOpenRelay7)
	{
		fRelay7Status = 1;
		fAnyRelayON = 1;
		LCDBufferReset();      // Röle açildiginda/kapandiginde sprink isaretini ekrandan kaldirmak için		
		systick_delayMs(20);
		selenoid_wakeup();
		selenoid_enable();
		systick_delayMs(20);
		fOpenRelay7 = 0;
		openRelay7();	
		systick_delayMs(20);		
		selenoid_sleep();
		selenoid_disable();				
	}		
}


