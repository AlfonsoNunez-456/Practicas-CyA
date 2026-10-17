/**
 * Universidad de La Laguna, Grado en Ingeniería Informática
 * Computabilidad y Algoritima
 * Curso 26/27
 * @author Alfonso Reyes Núñez Fernández, alu0101784809@ull.edu.es
 * @date 13/10/2026
 * @file state.h
 * @brief Declaración de la clase State para representar un estado en un DFA
 */

#ifndef STATE_H_
#define STATE_H_

#include <map>

/**
 * @class State
 * @brief Modela un estado dentro de un Autómata Finito Determinista
 */
class State {
 public:
  /**
   * @brief Constructor por defecto de la clase State
   */
  State();

  /**
   * @brief Constructor de la clase State
   * @param identifier Identificador único del estado
   * @param is_accepting Indica si es un estado final o de aceptación
   */
  State(int identifier, bool is_accepting);

  /**
   * @brief Obtiene el identificador del estado
   * @return Identificador entero del estado
   */
  int identifier() const;

  /**
   * @brief Comprueba si el estado es de aceptación
   * @return true si el estado es final/aceptación, false en caso contrario
   */
  bool is_accepting() const;

  /**
   * @brief Añade una transición desde este estado hacia otro dado un símbolo
   * @param symbol Símbolo de entrada que desencadena la transición
   * @param destination_state Identificador del estado destino
   */
  void AddTransition(char symbol, int destination_state);

  /**
   * @brief Verifica si existe una transición con el símbolo especificado
   * @param symbol Símbolo de entrada a consultar
   * @return true si existe la transición, false en caso contrario
   */
  bool HasTransition(char symbol) const;

  /**
   * @brief Obtiene el estado destino tras procesar un símbolo de entrada
   * @param symbol Símbolo con el que transita el estado
   * @return Identificador del estado destino, o -1 si no existe la transición
   */
  int GetNextState(char symbol) const;

 private:
  int identifier_;
  bool is_accepting_;
  std::map<char, int> transitions_;
};

#endif  // STATE_H_