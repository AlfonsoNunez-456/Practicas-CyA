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
 * @file symbol.h
 * @brief Declaración de la clase Symbol.
 */

#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <iostream>

/// Clase símbolo
class Symbol {
 public:
  /// Constructor clase símbolo
  explicit Symbol(char character = '\0') : character_(character) {}

  /// Getters 
  char character() const { return character_; }

  /// Sobrecarga del operador <
  bool operator<(const Symbol& simbolo) const { return character_ < simbolo.character_; }

  /// Sobrecarga del operador ==
  bool operator==(const Symbol& simbolo) const { return character_ == simbolo.character_; }
  
  /// Sobrecarga del operador del flujo de salida
  friend std::ostream& operator<<(std::ostream& salida, const Symbol& symbol);

  /// Sobrecarga del operador del flujo de entrada
  friend std::istream& operator>>(std::istream& entrada, Symbol& symbol);

 private:
  char character_;
};

#endif  /// SYMBOL_H_