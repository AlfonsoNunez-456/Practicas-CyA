/**
 * Universidad de La Laguna, Grado en Ingeniería Informática
 * Computabilidad y Algoritima
 * Curso 26/27
 * @author Alfonso Reyes Núñez Fernández, alu0101784809@ull.edu.es
 * @date 13/10/2026
 * @file dfa.h
 * @brief Declaración de la clase DFA para representar un Autómata Finito Determinista
 */

#ifndef DFA_H_
#define DFA_H_

#include <iostream>
#include <map>
#include <set>
#include <string>

#include "state.h"

/**
 * @class DFA
 * @brief Modela el funcionamiento de un DFA
 */
class DFA {
 public:
  /**
   * @brief Constructor por defecto de la clase DFA
   */
  DFA();

  /**
   * @brief Carga y valida la especificación de un DFA desde un archivo
   * @param filename Ruta o nombre del fichero .dfa con la especificación
   * @return true si el autómata se creó de forma válida, false en caso contrario
   */
  bool LoadFromFile(const std::string& filename);

  /**
   * @brief Simula el procesamiento de una cadena en el autómata e imprime la traza
   * @param input_string Cadena de caracteres a procesar
   * @param output_stream Flujo de salida donde se imprimirá la traza.
   * @return true si la cadena es aceptada por el autómata, false si es rechazada
   */
  bool SimulateString(const std::string& input_string, std::ostream& output_stream) const;

 private:
  std::set<char> alphabet_;
  std::map<int, State> states_;
  int initial_state_identifier_;
};

#endif  // DFA_H_