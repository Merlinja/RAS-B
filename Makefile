objects = main.o

ifeq ($(OS),Windows_NT)
	#Windows stuff
	RM = del
	#@echo "Compiling for windows."
else
	#Linux stuff
	echo "Compiling for linux."
	RM = rm
endif

#driver.exe: driver.o subs.o asm_io.o
#	gcc -m32 -o driver.exe driver.o subs.o asm_io.o

#asm_io.o: asm_io.asm
#	nasm -f elf32 -d ELF_TYPE asm_io.asm

#subs.o: subs.asm
#	nasm -f elf32 -d ELF_TYPE subs.asm

#driver.o: driver.c
#	gcc -m32 -c driver.c

clean:
	$(RM) *.obj
	$(RM) *.o
