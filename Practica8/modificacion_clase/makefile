CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = p08_grammar_generator
OBJS = main.o automata.o grammar.o state.o production.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean