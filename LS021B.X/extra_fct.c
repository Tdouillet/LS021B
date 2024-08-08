/*
 * File:   extra_fct.c
 * Author: t.douillet
 *
 * Created on July 17, 2024, 10:54 AM
 */


#include "xc.h"
#include "DELAY.h"
#include "extra_fct.h"
#include "mcc_generated_files/pin_manager.h"


void Black(void){
    R0_SetLow();
    R1_SetLow();
    G0_SetLow();
    G1_SetLow();
    B0_SetLow();
    B1_SetLow();
}

void Blue(void){
    R0_SetLow();
    R1_SetLow();
    G0_SetLow();
    G1_SetLow();
    B0_SetHigh();
    B1_SetHigh();
}

void Green(void){
    R0_SetLow();
    R1_SetLow();
    G0_SetHigh();
    G1_SetHigh();
    B0_SetHigh();
    B1_SetHigh();
}


void Red(void){
    R0_SetHigh();
    R1_SetHigh();
    G0_SetLow();
    G1_SetLow();
    B0_SetLow();
    B1_SetLow();
}


void White(void){
    R0_SetHigh();
    R1_SetHigh();
    G0_SetHigh();
    G1_SetHigh();
    B0_SetHigh();
    B1_SetHigh();
}

void BCK_On(void){
    CCP4RB = 0x15;
}
void BCK_Off(void){
    CCP4RB = 0x2A;
}
