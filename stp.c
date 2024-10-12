#include "stp.h"
#include "io.h"
#include "system.h"

#define stepsperrev 4096  // Number of steps per revolution for the stepper motor

// Set the stepper motor RPM (revolutions per minute) - max 13, min 1
static void stepper_set_rpm (int rpm)  
{       
    if (rpm > 13)  // Limit the maximum RPM to 13
        rpm = 13;
    if (rpm < 1)   // Limit the minimum RPM to 1
        rpm = 1;
    
    // Delay for the appropriate time to achieve the specified RPM
    DelayUs(60000000 / stepsperrev / rpm);
}

// Function to control the half-step driving mode of the stepper motor
static void stepper_half_drive (int step)
{
    switch (step) {
        case 0:
            IO_Write(Stepper_IN1, 1);   // Activate IN1
            IO_Write(Stepper_IN2, 0);   // Deactivate IN2
            IO_Write(Stepper_IN3, 0);   // Deactivate IN3
            IO_Write(Stepper_IN4, 0);   // Deactivate IN4
            break;

        case 1:
            IO_Write(Stepper_IN1, 1);   // Activate IN1
            IO_Write(Stepper_IN2, 1);   // Activate IN2
            IO_Write(Stepper_IN3, 0);   // Deactivate IN3
            IO_Write(Stepper_IN4, 0);   // Deactivate IN4
            break;

        case 2:
            IO_Write(Stepper_IN1, 0);   // Deactivate IN1
            IO_Write(Stepper_IN2, 1);   // Activate IN2
            IO_Write(Stepper_IN3, 0);   // Deactivate IN3
            IO_Write(Stepper_IN4, 0);   // Deactivate IN4
            break;

        case 3:
            IO_Write(Stepper_IN1, 0);   // Deactivate IN1
            IO_Write(Stepper_IN2, 1);   // Activate IN2
            IO_Write(Stepper_IN3, 1);   // Activate IN3
            IO_Write(Stepper_IN4, 0);   // Deactivate IN4
            break;

        case 4:
            IO_Write(Stepper_IN1, 0);   // Deactivate IN1
            IO_Write(Stepper_IN2, 0);   // Deactivate IN2
            IO_Write(Stepper_IN3, 1);   // Activate IN3
            IO_Write(Stepper_IN4, 0);   // Deactivate IN4
            break;

        case 5:
            IO_Write(Stepper_IN1, 0);   // Deactivate IN1
            IO_Write(Stepper_IN2, 0);   // Deactivate IN2
            IO_Write(Stepper_IN3, 1);   // Activate IN3
            IO_Write(Stepper_IN4, 1);   // Activate IN4
            break;

        case 6:
            IO_Write(Stepper_IN1, 0);   // Deactivate IN1
            IO_Write(Stepper_IN2, 0);   // Deactivate IN2
            IO_Write(Stepper_IN3, 0);   // Deactivate IN3
            IO_Write(Stepper_IN4, 1);   // Activate IN4
            break;

        case 7:
            IO_Write(Stepper_IN1, 1);   // Activate IN1
            IO_Write(Stepper_IN2, 0);   // Deactivate IN2
            IO_Write(Stepper_IN3, 0);   // Deactivate IN3
            IO_Write(Stepper_IN4, 1);   // Activate IN4
            break;
    }
}

// Rotate the stepper motor by a specific angle
// direction: 0 for clockwise, 1 for counterclockwise
// rpm: speed of rotation in revolutions per minute
void stepper_step_angle (float angle, int direction, int rpm) 
{
    float anglepersequence = 0.703125;  // Each step sequence covers 0.703125 degrees
    int numberofsequences = (int)(angle / anglepersequence);  // Calculate number of step sequences required
    
    // Loop through each sequence to achieve the desired angle
    for (int seq = 0; seq < numberofsequences; seq++) {
        if (direction == 0)  // Clockwise rotation
        {
            // Execute the steps in reverse order for clockwise rotation
            for (int step = 7; step >= 0; step--) {
                stepper_half_drive(step);  // Perform the half-step drive
                stepper_set_rpm(rpm);      // Adjust the RPM
            }
        }
        else if (direction == 1)  // Counterclockwise rotation
        {
            // Execute the steps in order for counterclockwise rotation
            for (int step = 0; step <= 7; step++) {
                stepper_half_drive(step);  // Perform the half-step drive
                stepper_set_rpm(rpm);      // Adjust the RPM
            }
        }
    }
}