CXX = g++
CXXFLAGS = -Wall -O3 -std=c++11 -march=native

TARGET = main

all: $(TARGET)

OBJS = Dataframe.o

$(TARGET): main.cpp Dataframe.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.cpp.o : 
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)
