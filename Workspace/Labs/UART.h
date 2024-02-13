/*
 * UART.h
 *
 *  Created on: Jan 31, 2024
 *      Author: menas
 */

#ifndef UART_H_
#define UART_H_

// Include Files
#include "Pin.h"
#include "uart.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"

// Macros

//UART base
#define UART_0 UART0_BASE
#define UART_1 UART1_BASE
#define UART_2 UART2_BASE
#define UART_3 UART3_BASE
#define UART_4 UART4_BASE
#define UART_5 UART5_BASE
#define UART_6 UART6_BASE
#define UART_7 UART7_BASE

// Parity type
#define PARITY_NONE UART_CONFIG_PAR_NONE
#define PARITY_EVEN UART_CONFIG_PAR_EVEN
#define PARITY_ODD  UART_CONFIG_PAR_ODD

// Data length
#define LENGTH_8_BIT UART_CONFIG_WLEN_8
#define LENGTH_7_BIT UART_CONFIG_WLEN_7
#define LENGTH_6_BIT UART_CONFIG_WLEN_6
#define LENGTH_5_BIT UART_CONFIG_WLEN_5

// Stop bit
#define STOP_BIT_ONE UART_CONFIG_STOP_ONE
#define STOP_BIT_TWO UART_CONFIG_STOP_TWO

// Baud rate
#define UART_BAUD_RATE_9600     (uint32_t)9600
#define UART_BAUD_RATE_19200    (uint32_t)19200
#define UART_BAUD_RATE_38400    (uint32_t)38400
#define UART_BAUD_RATE_115200   (uint32_t)115200
#define UART_BAUD_RATE_230400   (uint32_t)230400
#define UART_BAUD_RATE_460800   (uint32_t)460800

// User define datatypes
typedef struct{
    uint32_t UART_SELECT;
    uint32_t BAUD_RATE;
    uint32_t PARITY_TYPE;
    uint32_t DATA_LENGTH;
    uint32_t STOP_BIT_LENGTH;
}UART_t;

// Function Deceleration
Std_Return UART_Init(UART_t *_uart);
Std_Return UART_SendChar(UART_t *_uart,uint8_t data);
Std_Return UART_SendString(UART_t *_uart,const char *str);
uint8_t UART_ReceiveChar(UART_t *_uart,Std_Return *retVal);


#endif /* UART_H_ */
