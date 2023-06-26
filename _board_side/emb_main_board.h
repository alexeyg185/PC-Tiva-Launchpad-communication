#ifndef	main_board
#define	main_board

#define RED_LED GPIO_PIN_1
#define BLUE_LED  GPIO_PIN_2
#define GREEN_LED GPIO_PIN_3

#define LED_PERIPH SYSCTL_PERIPH_GPIOF
#define LED_BASE GPIO_PORTF_BASE

#define ALL_PINS 6

#define Button_PERIPH SYSCTL_PERIPH_GPIOF
#define ButtonBase GPIO_PORTF_BASE
#define Button_Switch1 GPIO_PIN_4
#define Button_Switch2 GPIO_PIN_0

#define OPTIONS 2

#define SYSDIV2 7
// bus frequency is 400MHz/(SYSDIV2+1) = 400MHz/(7+1) = 50 MHz

#define NVIC_ST_CTRL_R      (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R    (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R   (*((volatile unsigned long *)0xE000E018))
	
uint32_t switch1_status=0;
uint32_t switch2_status=0;

#endif