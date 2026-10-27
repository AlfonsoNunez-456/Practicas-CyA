/**
 * Universidad de La Laguna
 * Ingeniería Informática
 * Computabilidad y Algoritmia
 * Curso 26/27
 * @file state.h
 * @brief Declaración de la clase state, que representa un estado del autómata
 * @author Alfonso Reyes Núñez Fernández, alu0101784809@ull.edu.es
 * @date 31/10/2026
 */

#ifndef STATE_H_
#define STATE_H_

#include <utility>
#include <vector>

/**
 * @class State
 * @brief Modela un estado dentro de un DFA.
 */
class State {
 public:
  State();
  State(int identifier, bool is_accepting);

  int identifier() const;
  bool is_accepting() const;

  void AddTransition(char symbol, int destination_state);
  const std::vector<std::pair<char, int>>& transitions() const;

 private:
  int identifier_;
  bool is_accepting_;
  std::vector<std::pair<char, int>> transitions_;
};

#endif  // STATE_H_