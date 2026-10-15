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
 * @brief Declaración de la clase Alphabet.
 */

#ifndef ALPHABET_H_
#define ALPHABET_H_

#include <iostream>
#include <set>

#include "symbol.h"

/// Clase alfabeto
class Alphabet {
 public:
  /// Constructor por defecto
  Alphabet() = default;

  /**
   * @brief Añade un nuevo símbolo al conjunto del alfabeto.
   * @param symbol Símbolo que se insertará.
   */
  void Insert(const Symbol& symbol);

  /**
   * @brief Comprueba la pertenencia de un símbolo al alfabeto.
   * @param symbol Símbolo a verificar.
   * @return true si el símbolo forma parte del alfabeto, false en caso contrario.
   */
  bool Contains(const Symbol& symbol) const;
  
  /// Sobrecarga del operador de flujo de salida
  friend std::ostream& operator<<(std::ostream& salida, const Alphabet& alphabet);

 private:
  std::set<Symbol> symbols_;
};

#endif  /// ALPHABET_H_