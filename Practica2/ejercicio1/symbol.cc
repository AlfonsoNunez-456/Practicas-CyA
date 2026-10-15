/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * Nombre: Alfonso Reyes Núñez Fernández
 * Correo: alu0101784809@ull.edu.es
 * Fecha: 19/09/2026
 *
 * @file symbol.cc
 * @brief Implementación de la clase Symbol.
 */


#include "symbol.h"

#include <iostream>

std::ostream& operator<<(std::ostream& salida, const Symbol& symbol) {
  salida << symbol.character_;
  return salida;
}

std::istream& operator>>(std::istream& entrada, Symbol& symbol) {
  entrada >> symbol.character_;
  return entrada;
}