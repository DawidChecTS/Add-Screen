AVR_BIN=C:/avr/avr-gcc-15.2.0-x64-windows/bin

ifeq ($(wildcard $(AVR_BIN)/avr-g++.exe),)
CC=avr-g++
LD=avr-ld
OBJCOPY=avr-objcopy
OBJDUMP=avr-objdump
AVRSIZE=avr-size
OBJISP=avrdude
else
CC=$(AVR_BIN)/avr-g++.exe
LD=$(AVR_BIN)/avr-ld.exe
OBJCOPY=$(AVR_BIN)/avr-objcopy.exe
OBJDUMP=$(AVR_BIN)/avr-objdump.exe
AVRSIZE=$(AVR_BIN)/avr-size.exe
OBJISP=$(AVR_BIN)/avrdude.exe
endif

MCU=atmega328p
PROGRAMMER=arduino
BAUDRATE=115200
CFLAGS=-Wall -Wextra  -Wundef -pedantic \
		-Os  -DF_CPU=16000000UL -mmcu=${MCU} -DBAUD=19200
LDFLAGS=-mmcu=$(MCU)
PORT=\\\\.\\COM4
BIN=CuperAdCcreen
OUT=${BIN}.hex
SOURCES = main.cpp src/millis.cpp src/lcd_driver.cpp

DEBUG?=1

ifeq ($(OS),Windows_NT)
define make-dir
if not exist "$(1)" mkdir "$(1)"
endef
RM_CMD=del /Q
else
define make-dir
mkdir -p "$(1)"
endef
RM_CMD=rm -f
endif

ifeq ($(DEBUG), 1)
	OUTPUTDIR=bin/debug
else
	OUTPUTDIR=bin/release
endif

OBJS =  $(addprefix $(OUTPUTDIR)/,$(SOURCES:.cpp=.o))
DIRS = $(sort $(dir $(OBJS)))

all: $(DIRS) $(OUT) 

$(OBJS): Makefile

$(OUTPUTDIR)/%.o:%.cpp
	@$(call make-dir,$(dir $@))
	$(CC) $(CFLAGS) -MD -o $@ -c $<

%.lss: %.elf
	$(OBJDUMP) -h -S -s $< > $@

%.elf: $(OBJS)
	$(CC) -Wl,-Map=$(@:.elf=.map) $(LDFLAGS) -o $@ $^
	$(AVRSIZE) $@


$(OBJS):$(SOURCES)

%.hex: %.elf
	$(OBJCOPY) -O ihex -R .fuse -R .lock -R .user_signatures -R .comment $< $@

isp: ${BIN}.hex
	$(OBJISP) -F -V -c $(PROGRAMMER) -p ${MCU} -P ${PORT} -b $(BAUDRATE) -U flash:w:$<

clean:
	-$(RM_CMD) "$(OUT)" *.map *.P *.d


$(DIRS):
	@$(call make-dir,$@)
		   	
.PHONY: clean dirs