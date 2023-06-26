//Author: Alexey Gruzdev July 2015

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"

#include "driverlib/sysctl.c"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.c"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"

#include "tm4c123gh6pm.h"

#include "emb_main_board.h"
#include "uart_handler.h"

void Global_Init(void);
void PortF_Init(void);

int main(void)
{
		uint8_t state=0;	
		int sw1_prev_st=0, sw2_prev_st=0; //saves the previous status of switches
	
	
		Global_Init();
		PortF_Init();            // initialize buttons and LEDs on Port F

		while(1)
		{
		
			//0 - sw1 is off; 1 - sw1 is on; 2 - sw2 is off; 3 - sw2 is on;
			switch1_status=GPIOPinRead(ButtonBase,Button_Switch1);
			switch2_status=GPIOPinRead(ButtonBase,Button_Switch2);
		
			if( (switch1_status & Button_Switch1)==0) //checks whether the button is pressed
			{
				
					if(sw1_prev_st==0) //pressed 1st time
					{
						state^=RED_LED;
						sw1_prev_st=1; //indicate sw1 is on
						UARTSend((uint8_t *)"1");
					}
			}
			
			if( (switch1_status & Button_Switch1)!=0)
			{
				if(sw1_prev_st==1) //indicate has been released
				{
					state^=RED_LED;
					sw1_prev_st=0; //
					UARTSend((uint8_t *)"0");
					
				}
			}
			
			
			if( (switch2_status & Button_Switch2)==0) //checks whether the button is pressed
			{
					
					if(sw2_prev_st==0)
					{
						state^=RED_LED;
						sw2_prev_st=1; //indicate sw2 is on
						UARTSend((uint8_t *)"3");
					}
			}
			
			if( (switch2_status & Button_Switch2)!=0)
			{
				if(sw2_prev_st==1) //indicate has been released
				{
					state^=RED_LED;
					sw2_prev_st=0; 
					UARTSend((uint8_t *)"2");
					
				}
			}
	

    GPIOPinWrite(GPIO_PORTF_BASE, RED_LED|BLUE_LED|GREEN_LED, state); //to indicate switch press
	
  }
	
   
}



void Global_Init(void)
{
	  ROM_FPUEnable();
    ROM_FPULazyStackingEnable();

    ROM_SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);

    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    ROM_IntMasterEnable();

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    ROM_UARTConfigSetExpClk(UART0_BASE, ROM_SysCtlClockGet(), 115200,
                            (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                             UART_CONFIG_PAR_NONE));

    ROM_IntEnable(INT_UART0);
    ROM_UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);
	
	
}


void PortF_Init(void)
{ 
	volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000020;     // 1) activate clock for Port F
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock GPIO Port F
  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0
  // only PF0 needs to be unlocked, other bits can't be locked
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 in, PF3-1 out
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
  GPIO_PORTF_PUR_R = 0x11;          // enable pull-up on PF0 and PF4
  GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital I/O on PF4-0
}



