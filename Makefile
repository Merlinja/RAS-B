ifeq ($(OS),Windows_NT)
	#Windows stuff
	RM = rm
else
	#Linux stuff
	RM = rm
endif

# C compiling flags
CC=g++
CFLAGS= -c -Wall

# Source file macros
SRCS = Neural_Net.cpp Neuron.cpp
OBJS = ${SRCS:.cpp=.o}

Driver.exe: driver.o ${OBJS} ${SRCS}
	$(CC) -Wall driver.o ${OBJS} -o Driver.exe

E1: Experiment_1.o ${OBJS} ${SRCS}
	$(CC) -Wall Experiment_1.o ${OBJS} -o E1.exe

driver.o: driver.cpp ${OBJS}
	$(CC) $(CFLAGS) driver.cpp -o driver.o

Experiment_1.o: Experiment_1.cpp ${OBJS} ${SRCS}
	$(CC) $(CFLAGS) Experiment_1.cpp -o Experiment_1.o

Neuron.o: Neuron.h Neuron.cpp
	$(CC) $(CFLAGS) Neuron.cpp -o Neuron.o

Neural_Net.o: Neural_Net.h Neural_Net.cpp
	$(CC) $(CFLAGS) Neural_Net.cpp -o Neural_Net.o

clean :
	$(RM) *.o