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
 * @brief Declaración de la clase StringSpec para la representación de cadenas.
 */

#ifndef STRING_SPEC_H_
#define STRING_SPEC_H_

#include <iostream>
#include <string>
#include <vector>

#include "alphabet.h"
#include "language.h"
#include "symbol.h"

/// clase StringSpec
class StringSpec {
 public:
  /// Constructor por defecto de la clase StringSpec
  StringSpec() = default;

  /// Constructor de la clase StringSpec
  StringSpec(const std::string& sequence, const Alphabet& alphabet);

  /**
   * @brief Devuelve la longitud (número de símbolos) de la cadena.
   * @return Tamaño de la secuencia de símbolos.
   */
  size_t Length() const;

  /**
   * @brief Genera la cadena inversa.
   * @return Nuevo objeto StringSpec correspondiente a la inversa.
   */
  StringSpec Reverse() const;

  /**
   * @brief Obtiene el conjunto de prefijos de la cadena.
   * @return Lenguaje que almacena los prefijos.
   */
  Language Prefixes() const;

  /**
   * @brief Obtiene el conjunto de sufijos de la cadena.
   * @return Lenguaje que almacena los sufijos.
   */
  Language Suffixes() const;

  /**
   * @brief Valida si todos los símbolos pertenecen al alfabeto asignado.
   * @return true si la cadena es válida sobre su alfabeto, false en caso contrario.
   */
  bool IsValid() const;

  /// Getters
  const Alphabet& alphabet() const { return alphabet_; }
  const std::vector<Symbol>& symbols() const { return symbols_; }

  /// Sobrecarga del operador de flujo de salida
  friend std::ostream& operator<<(std::ostream& salida, const StringSpec& string);

  /**
   * @brief Concatena dos cadenas
   * @param const StringSpec& cadena a concatenar
   * @return Cadena concatenada
   */
  std::string Concatenar (const std::string& cadena);

 private:
  std::vector<Symbol> symbols_;
  Alphabet alphabet_;
};

#endif  /// STRING_SPEC_H_