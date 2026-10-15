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
 * @file alphabet.h
 * @brief Implementación de la clase Alphabet.
 */

#include "alphabet.h"

#include <iostream>

void Alphabet::Insert(const Symbol& symbol) {
  symbols_.insert(symbol);
}

bool Alphabet::Contains(const Symbol& symbol) const {
  return symbols_.find(symbol) != symbols_.end();
}

std::ostream& operator<<(std::ostream& salida, const Alphabet& alphabet) {
  salida << "{";
  auto simbolo = alphabet.symbols_.begin();
  while (simbolo != alphabet.symbols_.end()) {
    salida << *simbolo;
    if (++simbolo != alphabet.symbols_.end()) {
      salida << ", ";
    }
  }
  salida << "}";
  return salida;
}