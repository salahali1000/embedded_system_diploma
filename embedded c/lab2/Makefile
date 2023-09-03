#@copyright :salah ali
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4  -gdwarf-2 -g
INCS=-I . 
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
PROJECT_NAME=learn-in-depth_cortex-m4

all: $(PROJECT_NAME).bin
	@echo "Build is Done"

	
%.o: %.c
	$(CC)gcc.exe -c  $(INCS) -mthumb $(CFLAGS) $< -o $@
		
	
$(PROJECT_NAME).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld  $(LIBS) $(OBJ) $(ASOBJ)   -o $@ -Map=Mapfile.map cp $(PROJECT_NAME).elf $(PROJECT_NAME).axf
	
	
$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean_all:
	rm *.o *.elf *.bin 
	
	
clean:
	rm *.elf *.bin
	
