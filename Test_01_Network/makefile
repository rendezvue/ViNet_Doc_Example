INCDIRS = -I../../EnsembleAPI \
		-I../../EnsembleAPI/src \
		-I../../EnsembleCommon \
		-I../../EnsembleCommand \
		-I../../PacketEthComm \
		-I../../PacketEthComm/Client
		
OPENCV_CFLAG = `pkg-config opencv4 --cflags`
OPENCV_LIBS = `pkg-config opencv4 --libs`

TARGET = ENSEMBLE_TEST

CC = gcc
LD = gcc

CXXFLAGS  = $(OPENCV_CFLAG) $(INCDIRS) -O3 -Wall -std=c++11 -fopenmp -openmp

LIBS = -Xlinker --start-group -lpthread -ldl -lm -lrt -lc -lstdc++ -lboost_system -lboost_thread -lboost_filesystem -lboost_regex -lboost_date_time -lboost_program_options -lgomp -lstdc++fs -Xlinker --end-group $(OPENCV_LIBS)

SRCDIRS		= ../../EnsembleAPI \
			../../EnsembleAPI/src \
			../../EnsembleCommon \
			../../EnsembleCommand \
			../../PacketEthComm \
			../../PacketEthComm/Client
			
VPATH = . $(SRCDIRS)

SRCS = $(foreach dir, . $(SRCDIRS),$(wildcard $(dir)/*.cpp))

OBJS = $(SRCS:.cpp=.o)
OBJS := $(notdir $(OBJS))

all: $(TARGET)

$(TARGET) : $(OBJS)
	-rm -f $(TARGET)
	$(CC) $(CXXFLAGS) $^ -o $(TARGET) $(LIBS)

clean:
	-rm -rf $(OBJS)
	-rm -f $(TARGET)
	-rm -f depend

depend: 
	$(SRCS) 
	$(CC) -M $(CXXFLAGS) $^ > $@ 

-include depend
