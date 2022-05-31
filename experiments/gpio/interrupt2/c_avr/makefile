APP_NAME := led_button_interrupt2
DEVICE := -P /dev/ttyACM0
FLAGS := -Os

all:
	avr-gcc -mmcu=atmega328p $(FLAGS) $(APP_NAME).c -o main.elf
	avr-objcopy -O ihex main.elf main.ihex
	avrdude -p atmega328p -c arduino $(DEVICE) -U flash:w:main.ihex

clean:
	rm *.elf *.ihex
