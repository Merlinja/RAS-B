ifeq ($(OS),Windows_NT)
	#Windows stuff
	RM = del
else
	#Linux stuff
	RM = rm
endif


Driver.exe: driver.o
	g++ -Wall -g -o Driver.exe driver.o Neuron.o Neural_Net.o

driver.o: driver.cpp Neuron.o Neural_Net.o
	g++ -Wall -c driver.cpp -o driver.o

Neuron.o: Neuron.h Neuron.cpp
	g++ -Wall -c Neuron.cpp -o Neuron.o

Neural_Net.o: Neural_Net.h Neural_Net.cpp
	g++ -Wall -c Neural_Net.cpp -o Neural_Net.o

clean :
	$(RM) *.o