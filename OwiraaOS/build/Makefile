TOOLCHAIN = ../../cross/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi
CC = $(TOOLCHAIN)-gcc
OBJCOPY = $(TOOLCHAIN)-objcopy
CPU = cortex-a7
ARCHDIR = model1

CFLAGS = -mcpu=$(CPU) -fpic -ffreestanding
CSRCFLAGS = -O2 -Wall -Wextra
LFLAGS = -ffreestanding -O2 -nostdlib

KER_SRC = ../src/kernel
KER_HEAD = ../include
COMMON_SRC = ../src/common
OBJ_DIR = objects
KERSOURCES = $(wildcard $(KER_SRC)/*.c)
KERSOURCES += $(wildcard $(KER_SRC)/$(ARCHDIR)/*.c)
COMMONSOURCES = $(wildcard $(COMMON_SRC)/*.c)
ASMSOURCES = $(wildcard $(KER_SRC)/*.S)
OBJECTS = $(patsubst $(KER_SRC)/%.c, $(OBJ_DIR)/%.o, $(KERSOURCES))
OBJECTS += $(patsubst $(COMMON_SRC)/%.c, $(OBJ_DIR)/%.o, $(COMMONSOURCES))
OBJECTS += $(patsubst $(KER_SRC)/%.S, $(OBJ_DIR)/%.o, $(ASMSOURCES))
HEADERS = $(wildcard $(KER_HEAD)/*.h)

IMG_NAME=kernel

build: $(OBJECTS) $(HEADERS)
	$(CC) -T linker.ld -o $(IMG_NAME).elf $(LFLAGS) $(OBJECTS)
	$(OBJCOPY) $(IMG_NAME).elf -O binary $(IMG_NAME).img

$(OBJ_DIR)/%.o: $(KER_SRC)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(KER_SRC) -I$(KER_HEAD) -c $< -o $@ $(CSRCFLAGS)

#$(OBJ_DIR)/%.o: $(KER_SRC)/$(ARCH_DIR)/%.c
#	mkdir -p $(@D)
#	$(CC) $(CFLAGS) -I$(KER_SRC) -I$(KER_HEAD) -c $< -o $@ $(CSRCFLAGS)

$(OBJ_DIR)/%.o: $(KER_SRC)/%.S
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(KER_SRC) -c $< -o $@

$(OBJ_DIR)/%.o: $(COMMON_SRC)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(KER_SRC) -I$(KER_HEAD) -c $< -o $@ $(CSRCFLAGS)

clean:
	rm -rf $(OBJ_DIR)
	rm $(IMG_NAME).elf
	rm $(IMG_NAME).img

run: build
	qemu-system-arm -m 1G -M raspi2b -serial stdio -kernel kernel.elf
