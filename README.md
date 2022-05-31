# Embedded Systems Experiments for the Telecommunications Engineering Undergraduate Program

This page presents the results of a [undergraduate student project](https://wiki.sj.ifsc.edu.br/index.php/Concep%C3%A7%C3%A3o_de_Experimentos_de_Sistemas_Embarcados_para_Disciplinas_do_Curso_de_Engenharia_de_Telecomunica%C3%A7%C3%B5es) executed at IFSC, _campus_ São José in 2015.

## Project

  - **Title**: Development of Embedded System Experiments for the courses of the Telecommnications Engineering udergraduate program.
  - **Acronym**: ESTE (Experimentos de SisTemas Embarcados)
  - **Context**: Funded by IFSC São José Intern Call 13/PRPPGI/2015
  - **Student**: Katharine Schaeffer (Telecommnications Engineering)
  - **Coordinator**: [Arliones Hoeller Jr.](https://github.com/arliones)
  - **Duration**: may-november 2015
  - **Goal**: To design a set of experiments related to the integration of analog and digital devices to embedded systems.

## Experiments

All experiments designed in this project used Atmel AVR microcontrollers. These microcontrollers present a well organized RISC architecture that fits well for didtatic porpuses. They also are easy to be bought by students because they are available in the most popular and inexpensive Arduino platforms. In this project we used the Arduino UNO board.

### Used Equipment

  - Basic Equipments: these equipments are needed in all experiments.
      - 01 Arduino UNO;
      - 01 PC/laptop running the following software:
          - [IDE Arduino;](http://playground.arduino.cc/Linux/Ubuntu)
          - [GCC compiler for AVR with support to avrlibc;](http://avr-eclipse.sourceforge.net/wiki/index.php/The_AVR_GCC_Toolchain)
          - [avrdude](http://avr-eclipse.sourceforge.net/wiki/index.php/The_AVR_GCC_Toolchain)
          - [IDE for C/C++ programming (Eclipse CDT recommmended).](http://www.eclipse.org/downloads/packages/eclipse-ide-cc-developers/marsr)
          - [Fritzing](http://fritzing.org/download/)

  - Extra Equipment: these may be used in some experiments or for debugging.
      - 01 extra Arduino UNO;
      - RS232-USB converter;
      - Multimeter;
      - Osciloscope;
      - Logic Analyzer.

### Digital Interfaces Experiments

  - [ESTE: General Purpose Input and Output (GPIO)](https://github.com/arliones/este/experiments/gpio/basic);
  - [ESTE: GPIO and External Interrupts - part 1](https://github.com/arliones/este/experiments/gpio/interrupt1);
  - [ESTE: GPIO and External Interrupts - part 2](https://github.com/arliones/este/experiments/gpio/interrupt2);
  - [ESTE: Universal Assynchronous Receiver and Transmitter (UART)](https://github.com/arliones/este/experiments/uart/basic);
  - [ESTE: UART - Serial Communication](https://github.com/arliones/este/experiments/uart/txrx);
  - [ESTE: UART - Basic Interrupts](https://github.com/arliones/este/experiments/uart/interrupts);
  - [ESTE: UART - Interrupts and Circular Buffer](https://github.com/arliones/este/experiments/uart/buffers);
  - [ESTE: Pulse Width Modulation (PWM)](https://github.com/arliones/este/experiments/pwm/basic);
  - [ESTE: Dimmer with PWM and ADC](https://github.com/arliones/este/experiments/pwm/dimmer);
  - [ESTE: Automatic Dimmer with PWM and ADC](https://github.com/arliones/este/experiments/pwm/auto_dimmer);

## Analog Interfaces Experiments

  - [ESTE: Analog-to-Digital Converter (ADC) and Sensor Reading](https://github.com/arliones/este/experiments/adc/basic);
  - [ESTE: Analog Temperature Sensor 1 (LM35DT - Precision Centigrade Temperature Sensors)](https://github.com/arliones/este/experiments/adc/lm35);
  - [ESTE: Analog Temperature Sensor 2 (NTC - Negative Temperature Coeficient)](https://github.com/arliones/este/experiments/adc/ntc);
  - [ESTE: Analog Light Sensor (LDR - Light Dependent Resistor)](https://github.com/arliones/este/experiments/adc/ldr);