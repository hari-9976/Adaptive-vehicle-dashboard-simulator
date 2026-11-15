Overview
----------------------------------------------------------------------------------------------------------------------------
An embedded vehicle dashboard simulation system developed using two LPC2129 ARM7 microcontrollers communicating through
the Controller Area Network (CAN) protocol.

The system uses a transmitter node to collect vehicle-related parameters from sensors and switches, packs the data into 
CAN frames, and transmits them to a receiver node. The receiver decodes the CAN messages and displays the vehicle parameters 
through a UART terminal.

Key Features
----------------------------------------------------------------------------------------------------------------------------
1.Node-to-node communication using the CAN protocol.
2.Two LPC2129 ARM7 microcontrollers configured as transmitter and receiver nodes.
3.LM35 temperature sensor interfacing through ADC.
4.Potentiometer interfacing to represent vehicle speed.
5.Ultrasonic sensor interfacing for distance measurement.
6.External interrupt-based control for left indicator, right indicator, and headlight.
7.CAN frame data packing and decoding.
8.UART-based dashboard parameter visualization.
