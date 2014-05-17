TARGET = main
OBJS = $(TARGET).o utils.o codes.o

MCU = attiny45
F_CPU = 8000000L

AVRDUDE_FLAGS = -p $(MCU) -c usbasp -P usb

HFUSE=0xDE
LFUSE=0xE2

DEFINES = -DF_CPU=$(F_CPU)
WARNINGS = -Wall -Wextra

CPPFLAGS += -MD -MP
CXXFLAGS +=
CFLAGS += -g -O2 -mmcu=$(MCU) $(DEFINES) $(WARNINGS) -std=c99
LDFLAGS += -Wl,-Map,$(TARGET).map

AR = avr-ar
AS = avr-as
CC = avr-gcc
CXX = avr-g++
NM = avr-nm
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
AVRDUDE = avrdude

-include $(OBJS:.o=.d)

all: $(TARGET).elf $(TARGET).hex $(TARGET).eep $(TARGET).lst

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

%.hex: %.elf
	$(OBJCOPY) -j .eeprom -j .text -j .data -O ihex $< $@

flash: $(TARGET).hex
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:$(TARGET).hex

fuses:
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U hfuse:w:$(HFUSE):m -U lfuse:w:$(LFUSE):m

clean:
	rm -f $(OBJS).o
	rm -f $(TARGET).elf
	rm -f $(TARGET).hex
	rm -f $(TARGET).eep
	rm -f $(TARGET).lst
	rm -f $(TARGET).map

.PHONY: all clean flash fuses
