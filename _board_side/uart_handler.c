
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"


#include "tm4c123gh6pm.h"

#define NVIC_EN0_INT5           0x00000020  // Interrupt 5 enable
#define RED_LED GPIO_PIN_1
#define BLUE_LED  GPIO_PIN_2
#define GREEN_LED GPIO_PIN_3

#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif


void UARTSend(const uint8_t *out_buffer)
{

    ROM_UARTCharPutNonBlocking(UART0_BASE, *out_buffer);

}


void UARTIntHandler(void)
{
    uint32_t ui32Status;
		unsigned char in_buffer;

    ui32Status = ROM_UARTIntStatus(UART0_BASE, true);


    ROM_UARTIntClear(UART0_BASE, ui32Status);


    while(ROM_UARTCharsAvail(UART0_BASE))
    {
  
        in_buffer=ROM_UARTCharGetNonBlocking(UART0_BASE);
				
				if(in_buffer == 'r')
				{
						ROM_GPIOPinWrite(GPIO_PORTF_BASE, RED_LED, RED_LED);
				}
				else if (in_buffer == 'g')
				{
						ROM_GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, GREEN_LED);
				}
				else if (in_buffer == 'b')
				{
						ROM_GPIOPinWrite(GPIO_PORTF_BASE, BLUE_LED, BLUE_LED);
				}

        SysCtlDelay(SysCtlClockGet() / 100);
				GPIOPinWrite(GPIO_PORTF_BASE, RED_LED|BLUE_LED|GREEN_LED, 0);	

    }
		
	
}

void UART_Init(void)
{
  SYSCTL_RCGCUART_R |= 0x01;            // activate UART0
  SYSCTL_RCGCGPIO_R |= 0x01;            // activate port A
	
	
  UART0_CTL_R &= ~UART_CTL_UARTEN;      // disable UART
  UART0_IBRD_R = 27;                    // IBRD = int(50,000,000 / (16 * 115,200)) = int(27.1267)
  UART0_FBRD_R = 8;                     // FBRD = int(0.1267 * 64 + 0.5) = 8
                                        // 8 bit word length (no parity bits, one stop bit, FIFOs)
  UART0_LCRH_R = (UART_LCRH_WLEN_8|UART_LCRH_FEN);
  UART0_IFLS_R &= ~0x3F;                // clear TX and RX interrupt FIFO level fields
                                        // configure interrupt for TX FIFO <= 1/8 full
                                        // configure interrupt for RX FIFO >= 1/8 full
  UART0_IFLS_R += (UART_IFLS_TX1_8|UART_IFLS_RX1_8);
                                        // enable TX and RX FIFO interrupts and RX time-out interrupt
  UART0_IM_R |= (UART_IM_RXIM|UART_IM_TXIM|UART_IM_RTIM);
  UART0_CTL_R |= UART_CTL_UARTEN;       // enable UART
  GPIO_PORTA_AFSEL_R |= 0x03;           // enable alt funct on PA1-0
  GPIO_PORTA_DEN_R |= 0x03;             // enable digital I/O on PA1-0
                                        // configure PA1-0 as UART
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011;
  GPIO_PORTA_AMSEL_R = 0;               // disable analog functionality on PA
                                        // UART0=priority 2
  NVIC_PRI1_R = (NVIC_PRI1_R&0xFFFF00FF)|0x00004000; // bits 13-15
  NVIC_EN0_R = NVIC_EN0_INT5;           // enable interrupt 5 in NVIC

	
}



