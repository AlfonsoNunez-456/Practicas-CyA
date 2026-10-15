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
 * @brief Declaración de la clase Language y del criterio de ordenación para cadenas.
 */

#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include <iostream>
#include <set>

class StringSpec;

/**
 * @struct CustomStringComparator
 * @brief Functor para comparar cadenas priorizando su longitud y luego su orden lexicográfico.
 */
struct CustomStringComparator {
  /**
   * @brief Aplica el criterio de ordenación estricto entre dos objetos StringSpec.
   * @param primera Primera cadena a comparar.
   * @param segunda Segunda cadena a comparar.
   * @return true si 'a' precede a 'b'.
   */
  bool operator()(const StringSpec& primera, const StringSpec& segunda) const;
};

/// Clase lenguaje
class Language {
 public:
  /// Constructor por defecto de la clase lenguaje
  Language() = default;

  /**
   * @brief Inserta una cadena en el lenguaje.
   * @param string Cadena a añadir al conjunto.
   */
  void Insert(const StringSpec& string);

  /// Sobrecara del operador de flujo de entrada
  friend std::ostream& operator<<(std::ostream& entrada, const Language& language);

 private:
  std::set<StringSpec, CustomStringComparator> strings_;
};

#endif  /// LANGUAGE_H_