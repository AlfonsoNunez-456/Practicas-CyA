/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * Nombre: Alfonso Reyes Núñez Fernández
 * Correo: alu0101784809@ull.edu.es
 * Fecha: 21/09/2026
 *
 * @file string_spec.h
 * @brief Implementación de la clase StringSpec para la representación de cadenas.
 */

#include "string_spec.h"

#include <algorithm>
#include <iostream>
#include <string>

StringSpec::StringSpec(const std::string& sequence, const Alphabet& alphabet)
    : alphabet_(alphabet) {
  if (sequence != "&") {
    for (char c : sequence) {
      symbols_.push_back(Symbol(c));
    }
  }
}

size_t StringSpec::Length() const {
  return symbols_.size();
}

StringSpec StringSpec::Reverse() const {
  StringSpec reversed;
  reversed.alphabet_ = alphabet_;
  reversed.symbols_ = symbols_;
  std::reverse(reversed.symbols_.begin(), reversed.symbols_.end());
  return reversed;
}

Language StringSpec::Prefixes() const {
  Language prefixes;
  prefixes.Insert(StringSpec("&", alphabet_));
  std::string current = "";
  for (const auto& symbol : symbols_) {
    current += symbol.character();
    prefixes.Insert(StringSpec(current, alphabet_));
  }
  return prefixes;
}

Language StringSpec::Suffixes() const {
  Language suffixes;
  suffixes.Insert(StringSpec("&", alphabet_));
  for (size_t i = 0; i < symbols_.size(); ++i) {
    std::string current = "";
    for (size_t j = i; j < symbols_.size(); ++j) {
      current += symbols_[j].character();
    }
    suffixes.Insert(StringSpec(current, alphabet_));
  }
  return suffixes;
}

bool StringSpec::IsValid() const {
  for (const auto& symbol : symbols_) {
    if (!alphabet_.Contains(symbol)) {
      return false;
    }
  }
  return true;
}

std::ostream& operator<<(std::ostream& salida, const StringSpec& string) {
  if (string.symbols_.empty()) {
    salida << "&";
  } else {
    for (const auto& symbol : string.symbols_) {
      salida << symbol;
    }
  }
  return salida;
}