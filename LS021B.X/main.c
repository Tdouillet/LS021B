/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  PIC24FJ512GU410
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "DELAY.h"
#include "mcc_generated_files/tmr4.h"
#include "mcc_generated_files/mccp4_compare.h"
#include "extra_fct.h"

uint8_t va_ok = 0;
uint8_t vb_ok = 0;

uint8_t draw_ok= 0;

/*
                         Main application
 */

void Delay(unsigned int msec)
{
   while(msec > 0)
   {
       __delay_ms(1);
      msec--;
    }
}

void Delay_us(unsigned int usec)
{
   while(usec > 0)
   {
       __delay_us(1);
      usec--;
    }
}

void T4handler(void){
    if (!vb_ok){
        VA_Toggle();
        vb_ok++;
    } else {
        VCOM_Toggle();
        VA_Toggle();
    }
}

void Draw(void){
    draw_ok = 1;    
}



int main(void)
{
    
    // initialize the device
    SYSTEM_Initialize();
    uint32_t total_count = 0;
    BCK_SetLow();
    VA_SetLow();
    VCOM_SetLow();
    LED9_SetHigh();
    TMR4_SetInterruptHandler(T4handler);
    TMR4_Start();
    draw_ok=1;
    Red();
    INTB_SetHigh();
    GSP_SetHigh();
    MCCP4_COMPARE_Start();
//    Delay(500);
    
    while (1)
    {
        if (draw_ok){
            total_count++;
            
            if (total_count%2==0){
                BSP_SetHigh();
            } else if (total_count%2==1){
                BSP_SetLow();
            }
            if (total_count%4==0){
                GCK_Toggle();
            } else if (total_count%4==2){
                GCK_Toggle();
            }
            if (total_count%664==131){
                GEN_SetHigh();
            } else if (total_count%664==533){
                GEN_SetLow();
            }
            if (total_count%430272==0){
               total_count = 0;
               GSP_SetHigh();
               INTB_SetHigh();
            } else if (total_count%429360==0){
                INTB_SetLow();
            }  
            if (total_count==1328){
                GSP_SetLow();
            }
        } else{
            BCK_Off();
        }
    }

    return 1;
    }
/**
 End of File
*/

/*
 _____________________________Deprecated_______________________________________
 */

void white(void){
    uint8_t toto=0;
    R0_SetHigh();
    R1_SetHigh();
    G0_SetHigh();
    G1_SetHigh();
    B0_SetHigh();
    B1_SetHigh();
    INTB_SetHigh();
    Delay_us(21);
    GSP_SetHigh();
    GCK_SetLow();
    Delay_us(41);
    GCK_SetHigh();
    Delay_us(84);
    GCK_SetLow();
    Delay_us(42);
    GSP_SetLow();
    Delay_us(42);
    for(uint16_t k=0; k<646;k++){
        GCK_Toggle();
        BSP_SetHigh();
        for(uint8_t i=0; i<124;i++){
            toto++;
            if(toto==40){
                GEN_SetHigh();
            }
            else if(toto==90)
                GEN_SetLow();
            BCK_Toggle();
        }
        toto=0;
        BSP_SetLow();
    }
    Delay_us(21);
    INTB_SetLow();
}