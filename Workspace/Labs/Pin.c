/*
 * Pin.c
 *
 *  Created on: Jan 31, 2024
 *      Author: menas
 */

#include <Pin.h>

Std_Return Pin_Init(Pin_t *pin){
    Std_Return returnStatus = R_NOK;
    uint32_t portSelect =0;
    if(NULL == pin){
        returnStatus = R_NOK;
    }
    else
    {
        switch(pin->Port){
            case PORT_A:
                portSelect = SYSCTL_PERIPH_GPIOA;
                break;
            case PORT_B:
                portSelect = SYSCTL_PERIPH_GPIOB;
                break;
            case PORT_C:
                portSelect = SYSCTL_PERIPH_GPIOC;
                break;
            case PORT_D:
                portSelect = SYSCTL_PERIPH_GPIOD;
                break;
            case PORT_E:
                portSelect = SYSCTL_PERIPH_GPIOE;
                break;
            case PORT_F:
                portSelect = SYSCTL_PERIPH_GPIOF;
                break;
            default :
                portSelect = SYSCTL_PERIPH_GPIOF;
                break;
        }
        SysCtlGPIOAHBEnable(portSelect);
        SysCtlPeripheralEnable(portSelect);
        while(!SysCtlPeripheralReady(portSelect));
        GPIOPadConfigSet(pin->Port, pin->pinNumber, pin->Current, pin->Type);
        GPIODirModeSet(pin->Port, pin->pinNumber, pin->Direction);
        GPIOPinWrite(pin->Port, pin->pinNumber, 0x00);

        returnStatus = R_OK;
    }
    return returnStatus;
}

Std_Return Pin_Write(Pin_t *pin, uint8_t State){
    Std_Return returnStatus = R_NOK;
    if(NULL == pin ){
        returnStatus = R_NOK;
    }
    else
    {
        switch(State){
        case HIGH:
            GPIOPinWrite(pin->Port, pin->pinNumber, pin->pinNumber);
            break;
        case LOW:
            GPIOPinWrite(pin->Port, pin->pinNumber, 0x00);
            break;
        default:
            GPIOPinWrite(pin->Port, pin->pinNumber, 0x00);
            break;
        }

        returnStatus = R_OK;
    }
    return returnStatus;
}


int8_t Pin_Read_Value(Pin_t *pin,uint8_t *ReturnType){
    Std_Return returnStatus = R_NOK;
    uint32_t pinValue = 0;
    if(NULL == pin || NULL == ReturnType){
        returnStatus = R_NOK;
    }
    else
    {
         pinValue = GPIOPinRead(pin->Port, pin->pinNumber);

         returnStatus = R_OK;
    }
    *ReturnType = returnStatus;
    return pinValue;
}


Std_Return Pin_Toggle(Pin_t *pin){
    Std_Return returnStatus = R_NOK;
        uint32_t pinValue =0;
        if(NULL == pin){
            returnStatus = R_NOK;
        }
        else
        {
            pinValue = GPIOPinRead(pin->Port, pin->pinNumber);
            if(pinValue == pin->pinNumber)
            {
                GPIOPinWrite(pin->Port, pin->pinNumber, 0x00);

            }
            else
            {
                GPIOPinWrite(pin->Port, pin->pinNumber, pin->pinNumber);

            }

            returnStatus = R_OK;
        }
        return returnStatus;
}


