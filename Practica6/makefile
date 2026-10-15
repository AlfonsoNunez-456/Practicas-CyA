CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = p06_DFA_simulator
OBJS = main.o dfa.o state.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean