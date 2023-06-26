#ifndef	uart_con
#define	uart_con


void UART_Init(void);
void UARTIntHandler(void);
void UARTSend(const uint8_t* );

#endif