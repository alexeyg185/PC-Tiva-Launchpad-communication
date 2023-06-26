**PC-Tiva Launchpad Communication**
Welcome to my project on bi-directional communication between a PC and the Texas Instruments Tiva Launchpad (EK-TM4C123GXL) board. This was a self-led initiative undertaken shortly after I completed my BSc in Software Engineering and prior to embarking on my professional journey in the field. The purpose of this project was to gain practical experience and further my understanding of real-time embedded systems. It's been an opportunity to apply theoretical knowledge into practice and experience firsthand the intricacies and challenges embedded systems can present.

The board, powered by an ARM Cortex-M4 80MHz CPU, communicates with the PC through a UART (UART0 on the board side) interface. Read on for more details about the project structure, its functionality, communication details, and some important notes.

PC-Tiva Launchpad Communication
This project demonstrates bi-directional communication between a PC and the Texas Instruments Tiva Launchpad (EK-TM4C123GXL) board, which is powered by an ARM Cortex-M4 80MHz CPU. The communication is established via UART (UART0 on the board side).

**Project Structure**
The project is organized into two main parts:

1. board_side: This directory contains the program which runs on the Tiva board.
2. pc_side: This directory contains the program which runs on the PC.

**Board Side**
The program for the board side is developed with Keil uVision4 IDE and is written in C++. It uses a .NET based GUI. This program should be compiled and downloaded to the board using an available IDE to check its functionality.

**PC Side**
The program for the PC side is developed with Microsoft Visual Studio 2013 and is written in C. The executable file is included in the directory, so you can run it directly.

**Functionality**
On the Tiva board, there are two switch buttons (SW1, SW2). When pressed on/off, a controller on the GUI (PC side) lights up in red color when the switch is on, and in green when the switch is off.
On the PC side, the GUI has three buttons: red, green, and blue. Pressing any of these buttons turns on the corresponding LED on the board.
Communication
Communication between the board and the PC is handled via UART.

* Board Side:

  * Rx (Receive): This is event-driven. When data is detected on the UART bus, an interrupt is triggered, which then lights up the corresponding LEDs on the board.
  * Tx (Transmit): This is polling-based. The main loop checks the status of the switches and sends the status to the PC when any changes are detected.

* PC Side:

  * Rx (Receive): This is polling-based. It checks if there's data on the UART, and if there is, it decodes the data and updates the corresponding controllers in the GUI window.
  * Tx (Transmit): This is event-driven. When a button in the GUI is clicked, the PC sends the corresponding signal data to the board.

**Demonstration**
Please check the PC Tiva Launchpad communication [demonstration.mp4](https://youtu.be/kAWYBlZ-W80) video for a complete demonstration of these operations.

**Note**
You might need to specify the COM port number in the GUI to which Tiva is connected. The default is set to 3.
To enter the COM port in GUI, press 'Alt' on your keyboard before entering any values.
