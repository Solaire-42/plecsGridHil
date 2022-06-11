CROSS            ?= "C:/Users/fluky/Documents/Plexim/PLECS_RT_Box/PLECS_RT_Box-4/bin/win/aarch64-none-elf/bin/aarch64-none-elf-"
CFLAGS           := -Wall -O2 -g  -c -fmessage-length=0 -DEXTERNAL_MODE=1 \
   -fgcse-after-reload \
   -finline-functions \
   -fipa-cp-clone \
   -floop-interchange \
   -floop-unroll-and-jam \
   -fpeel-loops \
   -fpredictive-commoning \
   -fsplit-paths \
   -ftree-loop-distribute-patterns \
   -ftree-loop-distribution \
   -ftree-loop-vectorize \
   -ftree-partial-pre \
   -ftree-slp-vectorize \
   -funswitch-loops \
   -fvect-cost-model \
   -fno-fast-math \
   -mtune=cortex-a53 -march=armv8-a -mcpu=cortex-a53 \
   -Wno-unused-variable \
   -funsafe-math-optimizations -fopt-info-vec --param max-completely-peeled-insns=1000 --param max-completely-peel-times=100
CC               = $(CROSS)gcc
LD               = $(CROSS)ld
STRIP            = $(CROSS)strip
OBJCOPY          = $(CROSS)objcopy
INCLUDE          := -I"C:/Users/fluky/Documents/Plexim/PLECS_RT_Box/PLECS_RT_Box-4/include/rtbox2"
LDFLAGS          := -T "C:/Users/fluky/Documents/Plexim/PLECS_RT_Box/PLECS_RT_Box-4/build/rtbox2.lds"        
LIBS             := "C:/Users/fluky/Documents/Plexim/PLECS_RT_Box/PLECS_RT_Box-4/lib/rtbox2/librtbox2.a" -L"C:/Users/fluky/Documents/Plexim/PLECS_RT_Box/PLECS_RT_Box-4/lib/rtbox2/Xilinx" -lrpumsg_a53 -lmetal -lxil \
   -L"C:/Users/fluky/Documents/Plexim/PLECS_RT_Box/PLECS_RT_Box-4/bin/win/aarch64-none-elf/bin/../aarch64-none-elf/lib" \
   -L"C:/Users/fluky/Documents/Plexim/PLECS_RT_Box/PLECS_RT_Box-4/bin/win/aarch64-none-elf/bin/../lib/gcc/aarch64-none-elf/8.3.0" \
   -lm -lm --start-group -lc -lgcc -lnosys --end-group

undefine GCC_EXEC_PREFIX

ifeq ($(OS),Windows_NT)
 SHELL            := cmd.exe
 RM               := DEL /F
 CP               := COPY /Y
else
 RM               := rm -f
 CP               := cp
endif

APP = Plant_linked.elf
BIN = Plant.elf

HEADERS += Plant.h
C_SRCFILES += Plant_main.c Plant.c

OBJFILES := $(patsubst %.c, %.o, $(C_SRCFILES))
DEPFILES := $(patsubst %.c, %.d, $(C_SRCFILES))

all: $(BIN)

$(APP): $(OBJFILES)
	@echo Linking $@
	@$(LD) -o $@ $(OBJFILES) $(LIBS) $(LDFLAGS) 

$(BIN): $(APP)
	@echo Creating $@
	@$(OBJCOPY) -O binary $< $@

%.o:%.c $(HEADERS)
	@echo Compiling $(<:.c=.o)
	@$(CC) $(CFLAGS) $(ARCH_CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	-$(RM) $(LIB) $(OBJFILES)

FORCE:

PHONY: all clean
