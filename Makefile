objects = main.o

ifeq ($(OS),Windows_NT)
	#Windows stuff
	RM = del
	#echo "Compiling for windows."
else
	#Linux stuff
	#echo "Compiling for linux."
	RM = rm
endif

driver.exe: driver.o
	cc -o driver.exe driver.o

driver.o: driver.c
	cc -c driver.c

clean :
	$(RM) *.obj
	$(RM) *.o