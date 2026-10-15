# Compilador y flags de compilación
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g

# Nombre del ejecutable final
TARGET = p01_single_grades

# Archivos fuente (.cc)
SRCS = alumno_main.cc tools.cc alumno.cc
OBJS = $(SRCS:.cc=.o)

# Regla por defecto (se ejecuta al escribir 'make')
all: $(TARGET)

# Regla para enlazar el ejecutable final
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regla genérica para compilar archivos .cc a .o
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla de limpieza (solo elimina el ejecutable)
clean:
	rm -f $(TARGET)

# Declaración de reglas que no representan archivos reales
.PHONY: all clean