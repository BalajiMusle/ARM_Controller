
#GCC_BASE=/opt/gcc-arm-none-eabi-5_4-2016q2/
#GCC_BIN=$(GCC_BASE)/bin/
GCC_BIN=/home/sunbeam/Balaji/ARM/Toolchain/gcc-arm-none-eabi-5_4-2016q2/bin/

CC=$(GCC_BIN)arm-none-eabi-gcc
AS=$(GCC_BIN)arm-none-eabi-as
LD=$(GCC_BIN)arm-none-eabi-ld
NM=$(GCC_BIN)arm-none-eabi-nm
DB=$(GCC_BIN)arm-none-eabi-gdb
OBJCOPY=$(GCC_BIN)arm-none-eabi-objcopy

TARGET=basic
CPU=cortex-m3
STATE=thumb
DBG=warf2
ARCH=armv7

TEXT=0x00000000
DATA=0x20000000

EMU=qemu-system-arm
EMUMACH=lm3s6965evb
EMUDBGPORT=1234

ASFLAGS=-mcpu=$(CPU) -march=$(ARCH) -m$(STATE) -g$(DBG)
LDFLAGS=-Ttext=$(TEXT) -Tdata=$(DATA)

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@ 

$(TARGET).elf: $(TARGET).o
	$(LD) $(LDFLAGS) -o $@ $<

$(TARGET).o: $(TARGET).s
	$(AS) $(ASFLAGS) -o $@ $<

run:
	$(EMU) -machine $(EMUMACH) -cpu $(CPU) -S -gdb tcp::$(EMUDBGPORT) -nographic -kernel $(TARGET).elf

debug:
	$(DB) $(TARGET).elf -ex "target remote localhost:$(EMUDBGPORT)"

stop:
	pkill qemu-system-arm

clean:
	rm -f $(TARGET).bin $(TARGET).elf $(TARGET).o

version:
	$(CC) -v

.PHONY: clean run debug version


