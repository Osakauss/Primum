# to create disk go to: http://fejlesztek.hu/create-a-fat-file-system-image-on-linux/

DISK = ./disk.img
CC = x86_64-w64-mingw32-gcc
AS = nasm
BUILDDIR=bin
SRCDIR=src
CFLAGS=-Wall  -Werror -fno-builtin -m64 -mabi=ms -nostdlib -ffreestanding -I$(SRCDIR)/include
LFLAGS=-Wall -Werror -m64 -fno-builtin -ffreestanding -mabi=ms -nostdlib -shared -Wl,-dll -Wl,--subsystem,10 -e efi_main

CFILES  = $(shell find $(SRCDIR) -name '*.c')
OBJ = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(CFILES))
ASMFILES  = $(shell find $(SRCDIR) -name '*.s')
OBJ  += $(patsubst $(SRCDIR)/%.s,$(BUILDDIR)/%.s.o,$(ASMFILES))


all: build

build: BOOTX64.EFI

BOOTX64.EFI: setupDirs $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) -o $@
	

setupDirs:
	@mkdir -p $(BUILDDIR)
	@cd $(SRCDIR) \
	&& dirs=$$(find -type d) \
	&& cd ../$(BUILDDIR) \
	&& mkdir -p $$dirs



$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@echo "[$(CC)][$<]"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/%.s.o: $(SRCDIR)/%.s
	@echo [$(AS)][$<]
	@$(AS) $(ASFLAGS) $< -o $@











makeos:
	@#mkdir -p disk/EFI && mkdir disk/EFI/Boot
	@#cp BOOTX64.EFI disk/EFI/Boot/
	@#cp kernel disk/
	@cp primum.cfg disk/
	#python3 imgbuilder.py disk $(DISK) 

clean:
	@rm -rf $(BUILDDIR) *.EFI $(DISK)/kernel kernel disk/*
	-@#mdeltree -i $(DISK) ::

run: all
	#qemu-system-x86_64 -drive format=raw,unit=0,file=$(DISK) -bios bios64.bin -m 256M -vga std -name Primum -machine q35 -serial stdio