// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 0: El Entorno de trabajo IaaS para la asignatura 
// Autor: Alfonso Reyes Núñez Fernández
// Correo: alu0101784809@ull.edu.es
// Fecha: 09/09/2026
// Archivo pell.cc
// Archivo que contiene el código que calcula los primeros n números de la serie de Pell

#include <iostream>

long Pell (int number) {
  long resultado = 0;
  if (number == 1) {
    resultado = 1;
  }
  else {
    long previo = 0;
    long resultado_anterior = 1;
    for (int i = 2; i <= number; ++i) {
      resultado = 2 * resultado_anterior + previo;
      previo = resultado_anterior;
      resultado_anterior = resultado;
    }
  }
  return resultado;
}

int main (int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Uso: " << argv[0] << " número entero\n";
    return 1; 
  }
  int numero = atoi(argv [1]);
  if (numero < 0) {
    std::cerr << "El número debe ser igual a 0 o positivo\n";
    return 2;
  }
  for (int i = 0; i < numero; ++i) {
    std::cout << Pell (i) << " ";
  }
  std::cout << std::endl;
  return 0; 
}