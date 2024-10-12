#include <stdio.h>
#include <stdint.h>

#include "system.h"
#include "io.h"
#include "timer.h"
#include "oled.h"
#include "stp.h"



void init(void)
{
 // I/O ports initialization
  Sys_IoInit();
  
  // System Clock Tick initialization (currently commented out)
  //Sys_TickInit();
  
  // Console initialization
  Sys_ConsoleInit();

  // LED initialization and setting its initial state to ON
  IO_Write(IOP_LED, 1);
  IO_Init(IOP_LED, IO_MODE_OUTPUT_OD);  
  
  // Stepper motor pins initialization
  IO_Write(Stepper_IN1, 0);
  IO_Init(Stepper_IN1, IO_MODE_OUTPUT);  
  IO_Write(Stepper_IN2, 0);
  IO_Init(Stepper_IN2, IO_MODE_OUTPUT);  
  IO_Write(Stepper_IN3, 0);
  IO_Init(Stepper_IN3, IO_MODE_OUTPUT);  
  IO_Write(Stepper_IN4, 0);
  IO_Init(Stepper_IN4, IO_MODE_OUTPUT);  
}


void Task_Print(void)
{
  static unsigned long count;
  
  // Set the OLED cursor to the first row and display the value of variable 'a'
  OLED_SetCursor(0, 0);
  printf("%8d", a);
  
  // Set the OLED cursor to the second row and display an incrementing counter
  OLED_SetCursor(1, 0);
  printf("%8lu", ++count);
}



void main()
{
// Initial configurations
  init();
  
  // Set font for the OLED display
  OLED_SetFont(FNT_BIG);
 
  // Task loop
  while (1) 
  {


// Rotate stepper motor by specific angles with different speeds and delays
    stepper_step_angle(360,1,13);
    DelayMs(2000);
    stepper_step_angle(180,1,13);
    DelayMs(2000);
    stepper_step_angle(90,1,13);
    DelayMs(2000);
    stepper_step_angle(45,1,13);
    DelayMs(2000);
    
    stepper_step_angle(360,1,7);
    DelayMs(2000);
    stepper_step_angle(180,1,7);
    DelayMs(2000);
    stepper_step_angle(90,1,7);
    DelayMs(2000);
    stepper_step_angle(45,1,7);
    DelayMs(2000);
    
    stepper_step_angle(360,1,4);
    DelayMs(2000);
    stepper_step_angle(180,1,4);
    DelayMs(2000);
    stepper_step_angle(90,1,4);
    DelayMs(2000);
    stepper_step_angle(45,1,4);
    DelayMs(2000);
  }  
}


