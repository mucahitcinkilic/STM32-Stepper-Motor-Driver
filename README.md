This project provides a stepper motor control solution using the STM32 microcontroller. It features half-step driving mode and adjustable RPM for precise control of the motor in both clockwise and counterclockwise directions. The motor can be rotated by a specific angle through calculated step sequences, ensuring accurate positioning and smooth movement.

Features
Adjustable RPM: Motor speed can be set between 1 and 13 RPM for fine-tuned control.
Half-Step Driving: Uses half-step mode for smoother motor operation.
Directional Control: Supports both clockwise and counterclockwise rotation.
Angle-Based Rotation: Rotate the motor by a defined angle through step sequence calculations.
How It Works
The motor pins are initialized, and the half-step sequence is executed based on the required angle and direction.
The stepper_step_angle() function calculates the number of step sequences needed for a specific angle and drives the motor at the specified RPM.
The project uses a delay mechanism to manage timing between steps and ensure smooth operation.
Prerequisites
STM32 Development Board (e.g., STM32F103)
Stepper Motor (compatible with half-step control)
STM32CubeIDE or IAR Embedded Workbench for compiling and flashing the project.
How to Use
Clone the repository and open the project in your STM32 development environment.
Build and flash the project onto your STM32 microcontroller.
Connect your stepper motor to the STM32 according to the pin configuration in the code.
Modify the stepper_step_angle() function to control the motor’s angle, direction, and speed.
License
This project is licensed under the MIT License.

The project has been developed using the C programming language and was compiled using IAR Embedded Workbench, version 7.80. It is designed to run on an STM32 microcontroller, but can be adapted to other platforms with minor modifications.

Please note that only the core project files (stp.c, stp.h, and main.c) have been provided. You will need to implement other necessary configurations, such as IO initialization and RCC enabling, according to your own compiler and library setup. Ensure that the hardware-specific settings are adjusted for your environment.

The project also includes the design of the electronic circuit schematic, outlining the components and their connections. However, it does not include a PCB (Printed Circuit Board) design.

Demonstration Video Link: https://youtu.be/_ikhdW4bP60?si=8B1KRZ_AjRtAgkzU