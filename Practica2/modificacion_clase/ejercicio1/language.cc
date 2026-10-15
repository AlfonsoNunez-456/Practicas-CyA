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
 * @file language.h
 * @brief Implementación de la clase Language y del criterio de ordenación para cadenas.
 */

#include "language.h"
#include "string_spec.h"

#include <iostream>

bool CustomStringComparator::operator()(const StringSpec& primera, const StringSpec& segunda) const {
  if (primera.Length() != segunda.Length()) {
    return primera.Length() < segunda.Length();
  }
  return primera.symbols() < segunda.symbols();
}

void Language::Insert(const StringSpec& string) {
  strings_.insert(string);
}

std::ostream& operator<<(std::ostream& salida, const Language& language) {
  salida << "{";
  auto simbolo = language.strings_.begin();
  while (simbolo != language.strings_.end()) {
    salida << *simbolo;
    if (++simbolo != language.strings_.end()) {
      salida << ", ";
    }
  }
  salida << "}";
  return salida;
}