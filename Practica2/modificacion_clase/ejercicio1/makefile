CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

SRCS = symbol.cc alphabet.cc string_spec.cc language.cc language_main.cc
OBJS = $(SRCS:.cc=.o)
TARGET = p02_strings

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean