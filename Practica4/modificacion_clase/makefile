CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -g

TARGET = p04_html_analyzer
OBJS = p04_html_analyzer.o \
       html_analyzer.o \
       html_document.o \
       tag_info.o \
       atribute_info.o \
       tag_atributes_info.o \
       comment_info.o \
       link_info.o 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean