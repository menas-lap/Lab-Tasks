/**
 * main.c
 */

// Include Files
#include "stdint.h"
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include <Pin.h>
#include <UART.h>

// Macros
#define DELAY_TIME 500

// Variables
Pin_t redLed ={
                .Port=PORT_F,
                .pinNumber = PIN_1,
                .Direction = PIN_OUT,
                .Current = CURRENT_2MA,
                .Type = PIN_STD,
};
Pin_t blueLed ={
                .Port=PORT_F,
                .pinNumber = PIN_2,
                .Direction = PIN_OUT,
                .Current = CURRENT_2MA,
                .Type = PIN_STD,
};
Pin_t greenLed ={
                .Port=PORT_F,
                .pinNumber = PIN_3,
                .Direction = PIN_OUT,
                .Current = CURRENT_2MA,
                .Type = PIN_STD,
};
UART_t UART_ ={
                .UART_SELECT=UART_0,
                .BAUD_RATE = UART_BAUD_RATE_115200,
                .DATA_LENGTH = LENGTH_8_BIT,
                .PARITY_TYPE = PARITY_NONE,
                .STOP_BIT_LENGTH = STOP_BIT_ONE,
};

// Function Deceleration
void DelayMS(uint32_t delayValueMs);


void main(void){
    SysCtlClockSet(SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_USE_PLL | SYSCTL_SYSDIV_2_5 );
    Pin_Init(&redLed);
    Pin_Init(&blueLed);
    Pin_Init(&greenLed);
    UART_Init(&UART_);
    Std_Return returnVal = R_NOK;
    char ReceivedChar;
    while(1){
        ReceivedChar = UART_ReceiveChar(&UART_ , &returnVal);
        if(R_OK == returnVal){
            switch (ReceivedChar){
                case 'r':
                    Pin_Write(&redLed, HIGH);
                    Pin_Write(&blueLed, LOW);
                    Pin_Write(&greenLed, LOW);
                    break;
                case 'g':
                    Pin_Write(&greenLed, HIGH);
                    Pin_Write(&redLed, LOW);
                    Pin_Write(&blueLed, LOW);
                    break;
                case 'b':
                    Pin_Write(&blueLed, HIGH);
                    Pin_Write(&greenLed, LOW);
                    Pin_Write(&redLed, LOW);
                    break;
                case 'o':
                    Pin_Write(&blueLed, LOW);
                    Pin_Write(&redLed, LOW);
                    Pin_Write(&greenLed, LOW);
                    break;
                default:
                    break;
            }
        }
    }
}
