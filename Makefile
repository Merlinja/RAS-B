# Source file macros
SRCS = Neural_Net.cpp Neuron.cpp Registration_Node.cpp Synapse.cpp
OBJS = ${SRCS:.cpp=.o}
HDRS = ${SRCS:.cpp=.h}
EXCS =Driver E1
PRGS = Driver.exe E1.exe

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
OFLAGS= -Wall


all: $(SRCS) $(EXCS)

$(OBJS): $(SRCS) $(HDRS)

#$(EXCS): $(OBJS) $@.o
#	$(CC) $(OFLAGS) $@.o $(OBJS) -o $@

Driver: Driver.o ${OBJS} ${SRCS}
	$(CC) -Wall Driver.o ${OBJS} -o Driver.exe

E1: Experiment_1.o ${OBJS} ${SRCS}
	$(CC) -Wall Experiment_1.o ${OBJS} -o E1.exe

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean :
	$(RM) *.o $(PRGS)

#Driver.o: Driver.cpp ${OBJS}
#	$(CC) $(CFLAGS) Driver.cpp -o Driver.o

#Experiment_1.o: Experiment_1.cpp ${OBJS} ${SRCS}
#	$(CC) $(CFLAGS) Experiment_1.cpp -o Experiment_1.o

#Neuron.o: Neuron.h Neuron.cpp
#	$(CC) $(CFLAGS) Neuron.cpp -o Neuron.o

#Neural_Net.o: Neural_Net.h Neural_Net.cpp
#	$(CC) $(CFLAGS) Neural_Net.cpp -o Neural_Net.o

#Registration_Node.o: Registration_Node.h Registration_Node.cpp
#	$(CC) $(CFLAGS) Registration_Node.cpp -o Registration_Node.o