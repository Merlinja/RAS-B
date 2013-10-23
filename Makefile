Driver.exe: driver.o
	g++ -Wall -g -o Driver.exe driver.o Neuron.o

driver.o: driver.cpp Neuron.o
	g++ -Wall -c driver.cpp -o driver.o

Neuron.o: Neuron.h Neuron.cpp
	g++ -Wall -c Neuron.cpp -o Neuron.o

clean :
	$(RM) *.obj
	$(RM) *.o